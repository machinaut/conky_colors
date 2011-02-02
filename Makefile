VPATH=src/
CFLAGS=-Wall -std=c99
CWD:=$(shell pwd)
DOTFILES:="$(HOME)/src/dotfiles"

all: conky-colors
local: conky-colors-local
conky-colors: conky-colors.c conkycover.c conkyforecast.c conkyplayer.c conkyrc_cairo.c conkyrc_board.c conkyrc_default.c \
       coverposition.c finddir.c help.c options.c photoposition.c themes.c translations.c variables.c \
       confinstall.c utils.c initialize.c

conky-colors-local: conky-colors.c conkycover.c conkyforecast.c conkyplayer.c conkyrc_cairo.c conkyrc_board.c conkyrc_default.c \
       coverposition.c finddir.c help.c options.c photoposition.c themes.c translations.c variables.c \
       confinstall.c utils.c initialize.c
	cc $(CFLAGS) -DAJRAY_DOTFILES=$(DOTFILES) $^ -o conky-colors

install: conky-colors conkyrc
	mkdir -p $(DESTDIR)/usr/share 
	mkdir -p $(DESTDIR)/usr/share/fonts/TTF/conky
	mkdir -p $(DESTDIR)/usr/share/fonts/OTF/conky
	mkdir -p $(DESTDIR)/usr/bin
	cp -v conky-colors $(DESTDIR)/usr/bin
	cp -v -r conkycolors $(DESTDIR)/usr/share
	cp -v fonts/conkycolors/*.ttf fonts/conkycolors/*.TTF $(DESTDIR)/usr/share/fonts/TTF/conky
	cp -v fonts/conkycolors/*.otf $(DESTDIR)/usr/share/fonts/OTF/conky
	chmod +x $(DESTDIR)/usr/share/conkycolors/scripts/*
	chmod +x $(DESTDIR)/usr/share/conkycolors/bin/*

install-local: conky-colors-local conkyrc-local
	mkdir -p $(DOTFILES)
	mkdir -p $(HOME)/.fonts/TTF/conky
	mkdir -p $(HOME)/.fonts/OTF/conky
	mkdir -p $(DOTFILES)/bin
	mkdir -p $(HOME)/bin
	cp -v conky-colors $(DOTFILES)/bin
	ln -s $(DOTFILES)/bin/conky-colors $(HOME)/bin
	cp -v -r conkycolors $(DOTFILES)
	cp -v fonts/conkycolors/*.ttf fonts/conkycolors/*.TTF $(HOME)/.fonts/TTF/conky
	cp -v fonts/conkycolors/*.otf $(HOME)/.fonts/OTF/conky
	#ln -s $(DOTFILES)/fonts $(HOME)/.fonts # this should already be there
	chmod +x $(DOTFILES)/conkycolors/scripts/*
	chmod +x $(DOTFILES)/conkycolors/bin/*

conkyrc: conky-colors

conkyrc-local: conky-colors-local

clean:
	rm -f conky-colors
clean-local: clean

uninstall:
	rm -rf $(DESTDIR)/usr/share/conkycolors
	rm $(DESTDIR)/usr/bin/conky-colors
	for file in $$(find $(CWD)/fonts/conkycolors -iname *.otf -print0); do \
	  rm $(DESTDIR)/usr/share/fonts/OTF/conky/$$(basename $$file); \
	done
	for file in $$(find $(CWD)/fonts/conkycolors -iname *.ttf -print0); do \
	  rm $(DESTDIR)/usr/share/fonts/TTF/conky/$$(basename $$file); \
	done

uninstall-local:
	rm -rf $(DOTFILES)/conkycolors
	rm $(DOTFILES)/bin/conky-colors
	for file in $$(find $(CWD)/fonts/conkycolors -iname *.otf -print0); do \
	  rm $(HOME)/.fonts/OTF/conky/$$(basename $$file); \
	done
	for file in $$(find $(CWD)/fonts/conkycolors -iname *.ttf -print0); do \
	  rm $(HOME)/.fonts/TTF/conky/$$(basename $$file); \
	done

.PHONY: all local clean clean-local install install-local uninstall uninstall-local

