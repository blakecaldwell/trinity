/* Syscalls from arch/sparc/kernel/systbls_{32,64}.S as of 2.6.31rc2 */

#include "trinity.h"
#include "sanitise.h"

# define NR_SYSCALLS 326

struct syscalltable syscalls_sparc[NR_SYSCALLS+1] = {
#include "syscalls/restart_syscall.h"
#include "syscalls/exit"
#include "syscalls/fork"
#include "syscalls/read"
#include "syscalls/write"
#include "syscalls/open.h"
#include "syscalls/close.h"
#include "syscalls/wait4.h"
#include "syscalls/creat.h"
#include "syscalls/link.h"
#include "syscalls/unlink.h"
#include "syscalls/ni_syscall (sunos_execv).h"
#include "syscalls/chdir.h"
#include "syscalls/chown.h"
#include "syscalls/mknod.h"
#include "syscalls/chmod.h"
#include "syscalls/lchown.h"
#include "syscalls/brk.h"
#include "syscalls/perfctr.h"
#include "syscalls/lseek.h"
#include "syscalls/getpid.h"
#include "syscalls/capget.h"
#include "syscalls/capset.h"
#include "syscalls/setuid.h"
#include "syscalls/getuid.h"
#include "syscalls/vmsplice"
#include "syscalls/ptrace.h"
#include "syscalls/alarm.h"
#include "syscalls/sigaltstack.h"
#include "syscalls/pause"
#include "syscalls/utime.h"
#include "syscalls/ni_syscall (old stty syscall holder).h"
#include "syscalls/ni_syscall (old gtty syscall holder).h"
#include "syscalls/access.h"
#include "syscalls/nice.h"
#include "syscalls/ni_syscall (old ftime syscall holder).h"
#include "syscalls/sync.h"
#include "syscalls/kill.h"
#include "syscalls/newstat.h"
#include "syscalls/sendfile64.h"
#include "syscalls/newlstat.h"
#include "syscalls/dup.h"
#include "syscalls/pipe.h"
#include "syscalls/times.h"
#include "syscalls/ni_syscall (old prof syscall holder).h"
#include "syscalls/umount.h"
#include "syscalls/setgid.h"
#include "syscalls/getgid.h"
#include "syscalls/signal.h"
#include "syscalls/geteuid.h"
#include "syscalls/getegid.h"
#include "syscalls/acct.h"
#include "syscalls/memory_ordering.h"
#include "syscalls/getgid.h"
#include "syscalls/ioctl.h"
#include "syscalls/reboot.h"
#include "syscalls/mmap2.h"
#include "syscalls/symlink.h"
#include "syscalls/readlink.h"
#include "syscalls/execve.h"
#include "syscalls/umask.h"
#include "syscalls/chroot.h"
#include "syscalls/newfstat.h"
#include "syscalls/fstat64.h"
#include "syscalls/getpagesize.h"
#include "syscalls/msync.h"
#include "syscalls/vfork"
#include "syscalls/pread64"
#include "syscalls/pwrite64"
#include "syscalls/geteuid.h"
#include "syscalls/getegid.h"
#include "syscalls/mmap.h"
#include "syscalls/setreuid.h"
#include "syscalls/munmap.h"
#include "syscalls/mprotect"
#include "syscalls/madvise.h"
#include "syscalls/vhangup.h"
#include "syscalls/truncate64.h"
#include "syscalls/mincore.h"
#include "syscalls/getgroups.h"
#include "syscalls/setgroups.h"
#include "syscalls/getpgrp.h"
#include "syscalls/setgroups.h"
#include "syscalls/setitimer.h"
#include "syscalls/ftruncate64.h"
#include "syscalls/swapon.h"
#include "syscalls/getitimer.h"
#include "syscalls/setuid.h"
#include "syscalls/sethostname.h"
#include "syscalls/setgid.h"
#include "syscalls/dup2.h"
#include "syscalls/setfsuid.h"
#include "syscalls/fcntl.h"
#include "syscalls/select.h"
#include "syscalls/setfsgid.h"
#include "syscalls/fsync.h"
#include "syscalls/setpriority.h"
#include "syscalls/socket.h"
#include "syscalls/connect.h"
#include "syscalls/accept.h"
#include "syscalls/getpriority.h"
#include "syscalls/rt_sigreturn"
#include "syscalls/rt_sigaction"
#include "syscalls/rt_sigprocmask"
#include "syscalls/rt_sigpending.h"
#include "syscalls/rt_sigtimedwait.h"
#include "syscalls/rt_sigqueueinfo.h"
#include "syscalls/rt_sigsuspend.h"
#include "syscalls/setresuid.h"
#include "syscalls/getresuid.h"
#include "syscalls/setresgid.h"
#include "syscalls/getresgid.h"
#include "syscalls/setregid.h"
#include "syscalls/recvmsg"
#include "syscalls/sendmsg"
#include "syscalls/getgroups"
#include "syscalls/gettimeofday.h"
#include "syscalls/getrusage.h"
#include "syscalls/getsockopt"
#include "syscalls/getcwd"
#include "syscalls/readv.h"
#include "syscalls/writev.h"
#include "syscalls/settimeofday"
#include "syscalls/fchown"
#include "syscalls/fchmod"
#include "syscalls/recvfrom"
#include "syscalls/setreuid"
#include "syscalls/setregid"
#include "syscalls/rename"
#include "syscalls/truncate"
#include "syscalls/ftruncate"
#include "syscalls/flock"
#include "syscalls/lstat64.h"
#include "syscalls/sendto"
#include "syscalls/shutdown"
#include "syscalls/socketpair"
#include "syscalls/mkdir"
#include "syscalls/rmdir"
#include "syscalls/utimes"
#include "syscalls/stat64.h"
#include "syscalls/sendfile64.h"
#include "syscalls/getpeername"
#include "syscalls/futex"
#include "syscalls/gettid"
#include "syscalls/getrlimit"
#include "syscalls/setrlimit.h"
#include "syscalls/pivot_root"
#include "syscalls/prctl"
#include "syscalls/pciconfig_read.h"
#include "syscalls/pciconfig_write.h"
#include "syscalls/getsockname"
#include "syscalls/inotify_init"
#include "syscalls/inotify_add_watch"
#include "syscalls/poll"
#include "syscalls/getdents64"
#include "syscalls/fcntl64.h"
#include "syscalls/inotify_rm_watch"
#include "syscalls/statfs"
#include "syscalls/fstatfs"
#include "syscalls/oldumount.h"
#include "syscalls/sched_setaffinity.h"
#include "syscalls/sched_getaffinity.h"
#include "syscalls/getdomainname.h"
#include "syscalls/setdomainname.h"
#include "syscalls/utrap_install.h"
#include "syscalls/quotactl"
#include "syscalls/set_tid_address"
#include "syscalls/mount.h"
#include "syscalls/ustat"
#include "syscalls/setxattr"
#include "syscalls/lsetxattr"
#include "syscalls/fsetxattr"
#include "syscalls/getxattr"
#include "syscalls/lgetxattr"
#include "syscalls/getdents"
#include "syscalls/setsid"
#include "syscalls/fchdir.h"
#include "syscalls/fgetxattr.h"
#include "syscalls/listxattr.h"
#include "syscalls/llistxattr.h"
#include "syscalls/flistxattr.h"
#include "syscalls/removexattr.h"
#include "syscalls/lremovexattr.h"
#include "syscalls/sigpending.h"
#include "syscalls/ni_syscall.h"
#include "syscalls/setpgid.h"
#include "syscalls/fremovexattr.h"
#include "syscalls/tkill.h"
#include "syscalls/exit_group"
#include "syscalls/newuname.h"
#include "syscalls/init_module.h"
#include "syscalls/personality.h"
#include "syscalls/remap_file_pages.h"
#include "syscalls/epoll_create.h"
#include "syscalls/epoll_ctl.h"
#include "syscalls/epoll_wait.h"
#include "syscalls/ioprio_set.h"
#include "syscalls/getppid.h"
#include "syscalls/ni_syscall.h"
#include "syscalls/sgetmask.h"
#include "syscalls/ssetmask.h"
#include "syscalls/sigsuspend"
#include "syscalls/newlstat.h"
#include "syscalls/uselib.h"
#include "syscalls/old_readdir.h"
#include "syscalls/readahead.h"
#include "syscalls/socketcall.h"
#include "syscalls/syslog.h"
#include "syscalls/lookup_dcookie"
#include "syscalls/fadvise64.h"
#include "syscalls/fadvise64_64.h"
#include "syscalls/tgkill.h"
#include "syscalls/waitpid.h"
#include "syscalls/swapoff.h"
#include "syscalls/sysinfo.h"
#include "syscalls/ipc.h"
#include "syscalls/sigreturn.h"
#include "syscalls/clone"
#include "syscalls/ioprio_get.h"
#include "syscalls/adjtimex.h"
#include "syscalls/sigprocmask.h"
#include "syscalls/ni_syscall.h"
#include "syscalls/delete_module.h"
#include "syscalls/ni_syscall.h"
#include "syscalls/getpgid.h"
#include "syscalls/bdflush.h"
#include "syscalls/sysfs.h"
#include "syscalls/ni_syscall.h"
#include "syscalls/setfsuid.h"
#include "syscalls/setfsgid.h"
#include "syscalls/select"
#include "syscalls/time"
#include "syscalls/splice"
#include "syscalls/stime"
#include "syscalls/statfs64.h"
#include "syscalls/fstatfs64.h"
#include "syscalls/llseek.h"
#include "syscalls/mlock.h"
#include "syscalls/munlock.h"
#include "syscalls/mlockall.h"
#include "syscalls/munlockall.h"
#include "syscalls/sched_setparam.h"
#include "syscalls/sched_getparam.h"
#include "syscalls/sched_setscheduler.h"
#include "syscalls/sched_getscheduler.h"
#include "syscalls/sched_yield.h"
#include "syscalls/sched_get_priority_max.h"
#include "syscalls/sched_get_priority_min.h"
#include "syscalls/sched_rr_get_interval.h"
#include "syscalls/nanosleep.h"
#include "syscalls/mremap"
#include "syscalls/sysctl.h"
#include "syscalls/getsid.h"
#include "syscalls/fdatasync.h"
#include "syscalls/nfsservctl.h"
#include "syscalls/sync_file_range"
#include "syscalls/clock_settime.h"
#include "syscalls/clock_gettime.h"
#include "syscalls/clock_getres.h"
#include "syscalls/clock_nanosleep.h"
#include "syscalls/sched_getaffinity.h"
#include "syscalls/sched_setaffinity.h"
#include "syscalls/timer_settime.h"
#include "syscalls/timer_gettime.h"
#include "syscalls/timer_getoverrun.h"
#include "syscalls/timer_delete.h"
#include "syscalls/timer_create.h"
#include "syscalls/ni_syscall.h"
#include "syscalls/io_setup.h"
#include "syscalls/io_destroy.h"
#include "syscalls/io_submit.h"
#include "syscalls/io_cancel.h"
#include "syscalls/io_getevents.h"
#include "syscalls/mq_open.h"
#include "syscalls/mq_unlink.h"
#include "syscalls/mq_timedsend.h"
#include "syscalls/mq_timedreceive.h"
#include "syscalls/mq_notify.h"
#include "syscalls/mq_getsetattr.h"
#include "syscalls/waitid.h"
#include "syscalls/tee.h"
#include "syscalls/add_key.h"
#include "syscalls/request_key.h"
#include "syscalls/keyctl.h"
#include "syscalls/openat.h"
#include "syscalls/mkdirat.h"
#include "syscalls/mknodat.h"
#include "syscalls/fchownat.h"
#include "syscalls/futimesat.h"
#include "syscalls/fstatat64.h"
#include "syscalls/unlinkat.h"
#include "syscalls/renameat.h"
#include "syscalls/linkat.h"
#include "syscalls/symlinkat.h"
#include "syscalls/readlinkat.h"
#include "syscalls/fchmodat.h"
#include "syscalls/faccessat.h"
#include "syscalls/pselect6.h"
#include "syscalls/ppoll.h"
#include "syscalls/unshare.h"
#include "syscalls/set_robust_list"
#include "syscalls/get_robust_list.h"
#include "syscalls/migrate_pages.h"
#include "syscalls/mbind.h"
#include "syscalls/get_mempolicy.h"
#include "syscalls/set_mempolicy.h"
#include "syscalls/kexec_load.h"
#include "syscalls/move_pages.h"
#include "syscalls/getcpu.h"
#include "syscalls/epoll_pwait.h"
#include "syscalls/utimensat.h"
#include "syscalls/signalfd.h"
#include "syscalls/timerfd_create.h"
#include "syscalls/eventfd.h"
#include "syscalls/fallocate.h"
#include "syscalls/timerfd_settime.h"
#include "syscalls/timerfd_gettime.h"
#include "syscalls/signalfd4.h"
#include "syscalls/eventfd2.h"
#include "syscalls/epoll_create1.h"
#include "syscalls/dup3.h"
#include "syscalls/pipe2.h"
#include "syscalls/inotify_init1.h"
#include "syscalls/accept4.h"
#include "syscalls/preadv.h"
#include "syscalls/pwritev.h"
#include "syscalls/rt_tgsigqueueinfo.h"
};
