AUTOMAKE_OPTIONS = foreign
SUBDIRS = src
dist_doc_DATA = README.md

dist_man1_MANS = docs/yaids.1

AM_CFLAGS =-Wall -Wextra -Werror -Ofast -I$(top_srcdir)/include/

.PHONY: clean-local
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
        
.PHONY: format
format: FORCE
	for f in $(find src -name "*.c" -or -name "*.h"); do echo "Formatting: $f"; indent -kr -ci4 -cli4 -i4 -nut --no-tabs "$f" && rm "$f~"; sed -E -i 's/^\s+$//g' "$f"; done
	for f in $(find . -name "*.sh"); do echo "Formatting: $f"; shfmt -i 4 -ci -sr -fn -kp -w "$f"; sed -E -i 's/^\s+\{\s*$/\{/g' $f; done

FORCE:
