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

SUBMODULES	:= ./Brb2/

################################
# Targets
################################

OBJS 			:= $(addprefix $(objdir),$(SRCS:.cpp=.o))
DEPENDENCY 		:= $(addprefix $(depdir),$(SRCS:.cpp=.dep))
GCH				:= $(PCH).gch
PREBUILD		:= $(objdir).lastprebuild
BUILD			:= $(objdir).lastbuild
POSTBUILD		:= $(objdir).lastpostbuild

vpath %.h		$(incdir)
vpath %.cpp		$(srcdirs)
vpath %.dep		$(depdir)
vpath %.o 		$(objdir)

.PHONY: all build install clean realclean rebuild installdirs

################################
# Make
################################

all: $(PREBUILD) $(GCH) build $(POSTBUILD)

$(PREBUILD): $(SUBMODULES)
#submodules
	sudo $(MAKE) $(INSTALL) -C Brb2
	@touch $@

# GNU specific precompiled header: 
$(GCH): $(PCH)
	@echo [PRECOMPILED HEADER]
	$(CXX) -c $(CFLAGS) $<
	@echo

build: $(BUILD)
	@echo [PROJECT UP-TO-DATE]
	@echo

$(BUILD): $(OBJS)
	@echo [LINK]
	$(CXX) $(LDFLAGS) $^ -o $(builddir)$(PROG_NAME)
	@touch $@
	@echo

$(objdir)%.o : %.cpp %.dep
	@echo [COMPILE]
	$(CXX) -c $(CFLAGS) \
	-o $@ $<
	@echo

# Dependency generation:
# dep/main.dep: src/main.cpp inc/header.h
$(depdir)%.dep : %.cpp | $(dirs)
	@echo [DEPENDENCY]
	$(CXX) -c $(CFLAGS) \
	-MM -MP -MT $@ $< \
	> $@
	@echo

-include $(DEPENDENCY)

$(POSTBUILD): $(BUILD)
	@echo [POSTBUILD]
	cp $(RESS) $(builddir)
	@touch $@
	@echo

install: all

clean:
	@echo [CLEAN]
ifdef builddir
	rm -f $(builddir)*
endif
	rm -f $(OBJS) $(DEPENDENCY) $(GCH) $(BUILD) $(PREBUILD) $(POSTBUILD)
	@echo

realclean: clean
	

rebuild: clean
	@echo [REBUILD]
	$(MAKE)
	@echo

# Directory structure
$(dirs):
	@echo [MKDIR dirs]
	mkdir -p $(dirs)
	mkdir -p $(foreach dir,$(patsubst ./%,%,$(srcdirs)),$(objdir)$(dir))
	mkdir -p $(foreach dir,$(patsubst ./%,%,$(srcdirs)),$(depdir)$(dir))
	@echo

installdirs:
	@echo [INSTALLDIRS]
	mkdir -p $(dirs)
	mkdir -p $(foreach dir,$(patsubst ./%,%,$(srcdirs)),$(objdir)$(dir))
	mkdir -p $(foreach dir,$(patsubst ./%,%,$(srcdirs)),$(depdir)$(dir))
	@echo
