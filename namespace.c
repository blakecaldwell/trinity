// namespace.c
// Blake Caldwell
// From http://lwn.net/Articles/539940/

/* userns_child_exec.c

   Copyright 2013, Michael Kerrisk
   Licensed under GNU General Public License v2 or later

   Create a child process that executes a shell command in new
   namespace(s); allow UID and GID mappings to be specified when
   creating a user namespace.
*/

#include <errno.h>
#include "log.h"
#include "params.h"
#include "trinity.h"
#include <sys/capability.h>
#include <sys/wait.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <namespace.h>
//#define _GNU_SOURCE
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>


/* A simple error-handling function: print an error message based
   on the value in 'errno' and terminate the calling process */

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                        } while (0)

struct child_args {
    char **argv;        /* Command to be executed by child, with arguments */
    int    pipe_fd[2];  /* Pipe used to synchronize parent and child */
    struct childdata *child;
    int childno;
};

/* Update the mapping file 'map_file', with the value provided in
   'mapping', a string that defines a UID or GID mapping. A UID or
   GID mapping consists of one or more newline-delimited records
   of the form:

       ID_inside-ns    ID-outside-ns   length

   Requiring the user to supply a string that contains newlines is
   of course inconvenient for command-line use. Thus, we permit the
   use of commas to delimit records in this string, and replace them
   with newlines before writing the string to the file. */


static void
update_map(char *mapping, char *map_file)
{
    int fd;
    int j;
    int map_len;     /* Length of 'mapping' */

    /* Replace commas in mapping string with newlines */

    map_len = strlen(mapping);
    for (j = 0; j < map_len; j++)
        if (mapping[j] == ',')
            mapping[j] = '\n';

    fd = open(map_file, O_RDWR);
    if (fd == -1) {
        fprintf(stderr, "open %s: %s\n", map_file, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (write(fd, mapping, map_len) != map_len) {
        fprintf(stderr, "write %s: %s\n", map_file, strerror(errno));
        exit(EXIT_FAILURE);
    }

    close(fd);
}

static int              /* Start function for cloned child */
childFunc(void *arg)
{
    struct child_args *args = (struct child_args *) arg;
    char ch;

    /* Wait until the parent has updated the UID and GID mappings. See
       the comment in main(). We wait for end of file on a pipe that will
       be closed by the parent process once it has updated the mappings. */

    close(args->pipe_fd[1]);    /* Close our descriptor for the write end
                                   of the pipe so that we see EOF when
                                   parent closes its descriptor */
    if (read(args->pipe_fd[0], &ch, 1) != 0) {
        fprintf(stderr, "Failure in child: read from pipe returned != 0\n");
        exit(EXIT_FAILURE);
    }

    child_process(args->child, args->childno);

    errExit("main_loop");
}

#define STACK_SIZE (1024 * 1024)
static char child_stack[STACK_SIZE];    /* Space for child's stack */

void create_userns(struct childdata *child, int childno)
{
    int flags;
    pid_t child_pid;
    struct child_args args;
    char map_path[PATH_MAX];
    char uid_map[20] = "0 1000 1";
    char gid_map[20] = "0 1000 1";

    /* Parse command-line options. The initial '+' character in
       the final getopt() argument prevents GNU-style permutation
       of command-line options. That's useful, since sometimes
       the 'command' to be executed by this program itself
       has command-line options. We don't want getopt() to treat
       those as options to this program. */

    verbose = 1;
    flags = CLONE_NEWNS | CLONE_NEWNET | CLONE_NEWPID | CLONE_NEWUTS | CLONE_NEWUSER;
    //flags |= CLONE_NEWIPC;

    // this is the command execve'd within the namespace
    //args.argv = &argv[optind];

    /* We use a pipe to synchronize the parent and child, in order to
       ensure that the parent sets the UID and GID maps before the child
       calls execve(). This ensures that the child maintains its
       capabilities during the execve() in the common case where we
       want to map the child's effective user ID to 0 in the new user
       namespace. Without this synchronization, the child would lose
       its capabilities if it performed an execve() with nonzero
       user IDs (see the capabilities(7) man page for details of the
       transformation of a process's capabilities during execve()). */

    if (pipe(args.pipe_fd) == -1)
        errExit("pipe");

    /* Create the child in new namespace(s) */

    child_pid = clone(childFunc, child_stack + STACK_SIZE,
                      flags | SIGCHLD, &args);
    if (child_pid == -1)
        errExit("clone");

    /* Parent falls through to here */

    if (verbose)
        printf("PID of child created by clone() is %ld\n",
                (long) child_pid);

    /* Update the UID and GID maps in the child */

    if (uid_map != NULL) {
        snprintf(map_path, PATH_MAX, "/proc/%ld/uid_map",
                (long) child_pid);
        update_map(uid_map, map_path);
    }
    if (gid_map != NULL) {
        snprintf(map_path, PATH_MAX, "/proc/%ld/gid_map",
                (long) child_pid);
        update_map(gid_map, map_path);
    }

    /* Close the write end of the pipe, to signal to the child that we
       have updated the UID and GID maps */

    close(args.pipe_fd[1]);

    if (waitpid(child_pid, NULL, 0) == -1)      /* Wait for child */
        errExit("waitpid");

    if (verbose)
        printf("terminating\n");

    exit(EXIT_SUCCESS);
}
