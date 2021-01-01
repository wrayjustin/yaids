#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([yaids], [0.0.5], [wray.justin@gmail.com])
AM_INIT_AUTOMAKE([-Wall foreign subdir-objects])
AC_CONFIG_HEADERS([config.h])

# Set CFLAGS
: ${CFLAGS=""}

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_SEARCH_LIBS([fmin], [m],, AC_ERROR([Missing libc6-dev and/or libpthread-stubs0-dev Library]))
AC_SEARCH_LIBS([strlcpy], [bsd],, AC_WARN([Missing libbsd-dev Library ... using less secure strncpy]))
AC_SEARCH_LIBS([pthread_create], [pthread],, AC_ERROR([Missing libc6-dev and/or libpthread-stubs0-dev Library]))
AC_SEARCH_LIBS([pthread_detach], [pthread],, AC_ERROR([Missing libc6-dev and/or libpthread-stubs0-dev Library]))
AC_SEARCH_LIBS([pthread_mutex_lock], [pthread],, AC_ERROR([Missing libc6-dev and/or libpthread-stubs0-dev Library]))
AC_SEARCH_LIBS([pthread_mutex_unlock], [pthread],, AC_ERROR([Missing libc6-dev and/or libpthread-stubs0-dev Library]))
AC_SEARCH_LIBS([pthread_self], [pthread],, AC_ERROR([Missing libc6-dev and/or libpthread-stubs0-dev Library]))
AC_SEARCH_LIBS([pthread_sigmask], [pthread],, AC_ERROR([Missing libc6-dev and/or libpthread-stubs0-dev Library]))
AC_SEARCH_LIBS([pcap_dump], [pcap],, AC_ERROR([Missing libpcap-dev Library]))
AC_SEARCH_LIBS([pcap_dump_flush], [pcap],, AC_ERROR([Missing libpcap-dev Library]))
AC_SEARCH_LIBS([pcap_open_live], [pcap],, AC_ERROR([Missing libpcap-dev Library]))
AC_SEARCH_LIBS([pcap_open_offline], [pcap],, AC_ERROR([Missing libpcap-dev Library]))
AC_SEARCH_LIBS([yr_scanner_scan_mem], [yara],, AC_ERROR([Missing yara and/or libyara-dev Library]))
AC_SEARCH_LIBS([yr_scanner_set_callback], [yara],, AC_ERROR([Missing yara and/or libyara-dev Library]))

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([bsd/string.h],, AC_WARN([Missing libbsd-dev Library ... using less secure strncpy]))
AC_CHECK_HEADERS([ctype.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([fcntl.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([malloc.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([net/ethernet.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([netinet/ether.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([netinet/if_ether.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([netinet/in.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([netinet/ip.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([netinet/tcp.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([netinet/udp.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([pcap.h],, AC_ERROR([Missing libpcap-dev Header]))
AC_CHECK_HEADERS([pthread.h],, AC_ERROR([Missing libc6-dev and/or libpthread-stubs0-dev Header]))
AC_CHECK_HEADERS([signal.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([stdarg.h],, AC_ERROR([Missing libgcc-dev Header]))
AC_CHECK_HEADERS([stdbool.h],, AC_ERROR([Missing libgcc-dev Header]))
AC_CHECK_HEADERS([stdio.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([stdlib.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([sys/prctl.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([sys/stat.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([sys/socket.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([sys/sysinfo.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([sys/types.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([time.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([unistd.h],, AC_ERROR([Missing libc6-dev Header]))
AC_CHECK_HEADERS([yara.h],, AC_ERROR([Missing libyara-dev Header]))
AC_CHECK_HEADERS([yara/types.h],, AC_ERROR([Missing libyara-dev Header]))

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_CHECK_FUNCS([atoi])
AC_CHECK_FUNCS([memset])
AC_CHECK_FUNCS([memcpy])
AC_CHECK_FUNCS([strndup])
AC_CHECK_FUNCS([gmtime_r])
AC_CHECK_FUNCS([malloc_trim])
AC_CHECK_FUNCS([strlcpy])
AC_CHECK_FUNCS([strncpy])

# Fortify
AC_ARG_ENABLE([fortify2],
  [AS_HELP_STRING([--disable-fortify2], [compiles with -D_FORTIFY_SOURCE=2 option; compile-time and run-time security checks (Default: Enabled)])],
  [if test x$enableval = xyes; then
    CFLAGS="$CFLAGS -D_FORTIFY_SOURCE=1"
  fi],
  [
    CFLAGS="$CFLAGS -D_FORTIFY_SOURCE=2"
  ])
AC_ARG_ENABLE([fortify1],
  [AS_HELP_STRING([--enable-fortify1], [compiles with -D_FORTIFY_SOURCE=1 option; compile-time only security checks (Default: Disabled)])],
  [if test x$enableval = xyes; then
    CFLAGS="$CFLAGS -D_FORTIFY_SOURCE=1"
  fi])

# Debug
AC_ARG_ENABLE([debug],
  [AS_HELP_STRING([--enable-debug], [compiles with -g -ggdb options (Default: Disabled)])],
  [if test x$enableval = xyes; then
    CFLAGS="-g -ggdb $CFLAGS"
  fi])

# Profiing (GMON)
AC_ARG_ENABLE([profiling],
  [AS_HELP_STRING([--enable-profiling], [compiles with -pg options (Default: Disabled)])],
  [if test x$enableval = xyes; then
    CFLAGS="-pg $CFLAGS"
  fi])

# Makefiles
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])

AC_OUTPUT
