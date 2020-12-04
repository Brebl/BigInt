#!/usr/bin/make -f
# Copyright (C) 2020 Antti Helminen
# This program is free software; you can redistribute
# it and/or modify it under the terms of the GNU
# General Public License

################################
# System configuration
################################
SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .cpp .o .h .dep

CXX 			:= g++
LD				:= ld
INSTALL			:= install
INSTALLDATA		:= install -m 644
OS				:= linux

CFLAGS	 		= -g -Wall $(DEFS) $(INC)
DEFS			= -std=c++17 -march=x86-64
INC				= -iquote $(incdir)
LDFLAGS			= -lbrb2 #-Wl,-rpath=$(libdir)

prefix 			= /usr/local/
bindir 			= $(prefix)bin/
libdir			= $(prefix)lib/
includedir 		= $(prefix)include/

################################
# Project files
################################
PROG_NAME 		= BigInt

builddir 		= ./bin/$(OS)/
incdir			= ./inc/
src_basedir		= ./src/
srcdirs			= $(addsuffix /,$(shell find $(patsubst %/,%,$(src_basedir)) -type d))
resdir			= ./res/
3libdir			= ./lib/$(OS)/
depdir			= ./dep/$(OS)/
objdir			= ./obj/$(OS)/

dirs			= $(builddir) $(incdir) $(src_basedir) $(resdir) \
				$(3libdir) $(depdir) $(objdir)

SRCS	:= $(patsubst ./%,%,$(foreach dir, $(srcdirs),$(wildcard $(dir)*.cpp)))

RESS	:= $(wildcard $(resdir)*)

LIBS	:= \

PCH		:= $(incdir)pch.h

SUBS	:= ./Brb2/

################################
# Targets
################################

OBJS 			:= $(addprefix $(objdir),$(SRCS:.cpp=.o))
DEPENDENCY 		:= $(addprefix $(depdir),$(SRCS:.cpp=.dep))
GCH				:= $(PCH).gch
PREBUILD		:= $(objdir).lastprebuild
BUILD			:= $(objdir).lastbuild

vpath %.h		$(incdir)
vpath %.cpp		$(srcdirs)
vpath %.dep		$(depdir)
vpath %.o 		$(objdir)

.PHONY: all build install clean realclean rebuild installdirs prebuild

################################
# Make
################################

all: $(PREBUILD) $(GCH) build

$(PREBUILD): $(SUBS)
#submodules
	sudo $(MAKE) install -C Brb2
	@touch $@

# GNU specific precompiled header: 
$(GCH): $(PCH)
	@echo
	@echo [PRECOMPILED HEADER]
	$(CXX) -c $(CFLAGS) $<

build: $(BUILD)
	@echo
	@echo [PROJECT UP-TO-DATE]

$(BUILD): $(OBJS)
	@echo
	@echo [LINK]
	$(CXX) $(LDFLAGS) $^ -o $(builddir)$(REALNAME)
	@touch $@

$(objdir)%.o : %.cpp %.dep
	@echo [COMPILE]
	$(CXX) -c $(CFLAGS) \
	-o $@ $<

# Dependency generation:
# dep/main.dep: src/main.cpp inc/header.h
$(depdir)%.dep : %.cpp | $(dirs)
	@echo [DEPENDENCY]
	$(CXX) -c $(CFLAGS) \
	-MM -MP -MT $@ $< \
	> $@

-include $(DEPENDENCY)

install: all

clean:
	@echo [CLEAN]
ifdef builddir
	rm -f $(builddir)*
endif
	rm -f $(OBJS) $(DEPENDENCY) $(GCH) $(BUILD)

realclean: clean
	

rebuild: clean
	@echo
	@echo [REBUILD]
	$(MAKE)

# Directory structure
$(dirs):
	@echo
	@echo [MKDIR dirs]
	mkdir -p $(dirs)
	mkdir -p $(foreach dir,$(patsubst ./%,%,$(srcdirs)),$(objdir)$(dir))
	mkdir -p $(foreach dir,$(patsubst ./%,%,$(srcdirs)),$(depdir)$(dir))

installdirs:
	@echo [INSTALLDIRS]
	mkdir -p $(dirs)
	mkdir -p $(foreach dir,$(patsubst ./%,%,$(srcdirs)),$(objdir)$(dir))
	mkdir -p $(foreach dir,$(patsubst ./%,%,$(srcdirs)),$(depdir)$(dir))
