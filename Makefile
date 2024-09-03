# var
MODULE = $(notdir $(CURDIR))
REL    = $(shell git rev-parse --short=4    HEAD)
BRANCH = $(shell git rev-parse --abbrev-ref HEAD)
NOW    = $(shell date +%d%m%y)

# dirs
CWD = $(CURDIR)
BIN = $(CWD)/bin
TMP = $(CWD)/tmp

# tools
CURL = curl -L -o
CF   = clang-format -style=file -i

# src
C += $(wildcard src/*.c*)
H += $(wildcard inc/*.h*)
A += $(wildcard src/*.ino)

# all
.PHONY: all
all:

# format
.PHONY: format
format: tmp/format_cpp
tmp/format_cpp: $(C) $(H) $(A)
	$(CF) $? && touch $@

# doc
doc: \
	doc/ragel-guide-6.10.pdf

doc/ragel-guide-6.10.pdf:
	$(CURL) $@ https://www.colm.net/files/ragel/ragel-guide-6.10.pdf

# install
.PHONY: install update doc ref gz
install: doc ref gz
	$(MAKE) update
update:
	sudo apt update
	sudo apt install `cat apt.txt`
ref:
gz:
