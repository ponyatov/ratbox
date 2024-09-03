# var
MODULE = $(notdir $(CURDIR))
REL    = $(shell git rev-parse --short=4    HEAD)
BRANCH = $(shell git rev-parse --abbrev-ref HEAD)
NOW    = $(shell date +%d%m%y)

# version
RAGEL_VER    = 6.10

# dirs
CWD = $(CURDIR)
BIN = $(CWD)/bin
TMP = $(CWD)/tmp

# tools
CURL = curl -L -o
CF   = clang-format -style=file -i

# package
RAGEL_URL = https://www.colm.net/files/ragel
RAGEL_PDF = ragel-guide-$(RAGEL_VER).pdf

# src
C += $(wildcard src/*.c*) $(wildcard $(MODULE)/*.c*)
H += $(wildcard inc/*.h*) $(wildcard $(MODULE)/*.h*)
A += $(wildcard $(MODULE)/*.ino)

BINS += $(wildcard lib/*.bin)

# cfg
CFLAGS += -Iinc -Isrc -Itmp -DLinux
CFLAGS += -O0 -ggdb

# all
.PHONY: all
all: bin/$(MODULE) $(BINS)
	$^

# format
.PHONY: format
format: tmp/format_cpp
tmp/format_cpp: $(C) $(H) $(A)
	$(CF) $? && touch $@

# rule
bin/$(MODULE): $(C) $(H)
	$(CXX) $(CFLAGS) -o $@ $(C)
$(MODULE)/parser.cpp: src/$(MODULE).ragel
	ragel -G2 -o $@ $<

lib/%.bin: lib/%.hex
	xxd -r -p $< $@ && hexdump -C $@

# doc
.PHONY: doxy
doxy: .doxygen doc/DoxygenLayout.xml $(C) $(H) $(A) README.md
	rm -rf docs
	MODULE=$(MODULE) REL="$(REL)" BRANCH=$(BRANCH) NOW=$(NOW) \
		doxygen $< 1>/dev/null
doc/DoxygenLayout.xml:
	cd doc ; doxygen -l

.PHONY: doc
doc: \
	doc/$(RAGEL_PDF) doc/1986/LDM-HELPER-K1986BE1QI.pdf

doc/$(RAGEL_PDF):
	$(CURL) $@ $(RAGEL_URL)/$(RAGEL_PDF)

doc/1986/LDM-HELPER-K1986BE1QI.pdf:
	$(CURL) $@ https://ldm-systems.ru/f/doc/catalog/LDM-HELPER-K1986BE1QI-FULL/LDM-HELPER-K1986BE1QI.pdf

# install
.PHONY: install update ref gz
install: doc ref gz
	$(MAKE) update
update:
	sudo apt update
	sudo apt install -uy `cat apt.txt`
ref:
gz:
