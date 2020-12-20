AUTOMAKE_OPTIONS = foreign
SUBDIRS = src
dist_doc_DATA = README.md

AM_CFLAGS =-Wall -Wextra -Werror -Ofast -I$(top_srcdir)/include/

clean-local:
	@rm config.status configure config.log
	@rm Makefile Makefile.in
	@rm src/Makefile src/Makefile.in
	@rm -r autom4te.cache/
	@rm aclocal.m4
	@rm compile install-sh missing
	@rm config.h.in
	@rm -f config.h.in~
	@rm -f autoscan.log configure.scan
	@rm depcomp
	@rm stamp-h1
        
format:
	@for f in $(find src -name "*.c" -or -name "*.h"); do indent -kr -ci4 -cli4 -i4 -nut --no-tabs "$f" && rm "$f~"; done
