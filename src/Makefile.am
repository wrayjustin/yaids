AUTOMAKE_OPTIONS = foreign
AM_CFLAGS =-Wall -Wextra -Werror -Ofast -I$(top_srcdir)/include/

sbin_PROGRAMS = yaids

yaids_SOURCES =  \
  yaids.c \
  yaidsconf.c \
  yaidsio.c \
  yaidspcap.c \
  yaidsyara.c \
  yaidsthread.c \
  $(top_srcdir)/include/ethertypes.h \
  $(top_srcdir)/include/yaids.h \
  $(top_srcdir)/include/yaidsconf.h \
  $(top_srcdir)/include/yaidsio.h \
  $(top_srcdir)/include/yaidspcap.h \
  $(top_srcdir)/include/yaidsthread.h \
  $(top_srcdir)/include/yaidstypes.h \
  $(top_srcdir)/include/yaidsyara.h

yaids_INCLUDES = $(top_srcdir)/include/

dist_bin_SCRIPTS = yaidsc
