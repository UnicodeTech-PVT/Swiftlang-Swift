//===--- SwiftMusl.h ------------------------------------------------------===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2023 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//

#include <assert.h>
#include <float.h>
#include <iso646.h>
#include <limits.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <tgmath.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <inttypes.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <threads.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>
#include <aio.h>
#include <arpa/inet.h>
#include <arpa/ftp.h>
#include <arpa/nameser.h>
#include <arpa/nameser_compat.h>
#include <arpa/telnet.h>
#include <arpa/tftp.h>
#include <cpio.h>
#include <dirent.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <fmtmsg.h>
#include <fnmatch.h>
#include <ftw.h>
#include <glob.h>
#include <grp.h>
#include <iconv.h>
#include <langinfo.h>
#include <libgen.h>
#include <monetary.h>
#include <mqueue.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <net/route.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <netinet/icmp6.h>
#include <netinet/if_ether.h>
#include <netinet/igmp.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <nl_types.h>
#include <poll.h>
#include <pthread.h>
#include <pwd.h>
#include <regex.h>
#include <sched.h>
#include <search.h>
#include <semaphore.h>
#include <spawn.h>
#include <strings.h>
#include <stropts.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/msg.h>
#include <sys/resource.h>
#include <sys/select.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <sys/acct.h>
#include <sys/auxv.h>
#include <sys/cachectl.h>
#include <sys/dir.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/fanotify.h>
#include <sys/file.h>
#include <sys/fsuid.h>
#include <sys/inotify.h>
#include <sys/ioctl.h>
#include <sys/io.h>
#include <sys/klog.h>
#include <sys/membarrier.h>
#include <sys/mount.h>
#include <sys/mtio.h>
#include <sys/param.h>
#include <sys/personality.h>
#include <sys/prctl.h>
#include <sys/procfs.h>
#include <sys/ptrace.h>
#include <sys/quota.h>
#include <sys/random.h>
#include <sys/reboot.h>
#include <sys/reg.h>
#include <sys/sendfile.h>
#include <sys/signalfd.h>
#include <sys/statfs.h>
#include <sys/stropts.h>
#include <sys/swap.h>
#include <sys/syscall.h>
#include <sys/sysinfo.h>
#include <sys/syslog.h>
#include <sys/sysmacros.h>
#include <sys/timeb.h>
#include <sys/timerfd.h>
#include <sys/timex.h>
#include <sys/ttydefaults.h>
#include <sys/ucontext.h>
#include <sys/user.h>
#include <sys/vfs.h>
#include <sys/xattr.h>
#include <syslog.h>
#include <tar.h>
#include <termios.h>
#include <ucontext.h>
#include <unistd.h>
#include <ulimit.h>
#include <utime.h>
#include <utmpx.h>
#include <alloca.h>
#include <ar.h>
#include <byteswap.h>
#include <crypt.h>
#include <elf.h>
#include <endian.h>
#include <err.h>
#include <getopt.h>
#include <ifaddrs.h>
#include <lastlog.h>
#include <libintl.h>
#include <link.h>
#include <malloc.h>
#include <memory.h>
#include <mntent.h>
#include <netpacket/packet.h>
#include <paths.h>
#include <pty.h>
#include <resolv.h>
#include <scsi/scsi.h>
#include <scsi/scsi_ioctl.h>
#include <scsi/sg.h>
#include <shadow.h>
#include <stdio_ext.h>
#include <syscall.h>
#include <sysexits.h>
#include <utmp.h>
#include <values.h>
#include <unwind.h>
#include <wordexp.h>
#include <fts.h>