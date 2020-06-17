# Makefile to compile and link all C++ files in the current directory, such that each C++
# file results in a unique executable.
#
# This is useful for experimentation, testing and small-scale projects.
# 
# Copyright (c) David Egan 2020
# SPDX-License-Identifier: GPL-2.0-or-later

WARNINGS = -pedantic -Wall -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable
BIN_DIR = bin
OBJS_DIR = $(BIN_DIR)/objs
CXXFLAGS = $(WARNINGS) -std=c++17 -g
LDFLAGS =
CXX = g++ ${CXXFLAGS}

SRCS = $(wildcard *.cpp)
EXECUTABLE_FILES = $(SRCS:%.cpp=$(BIN_DIR)/%)
OBJECT_FILES = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

.PHONY: all clean
all: $(EXECUTABLE_FILES)

$(BIN_DIR)/%: $(OBJS_DIR)/%.o
	@$(CXX) $(LDFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: %.cpp
	$(info Building object file for "$(<)")
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJS_DIR)/selection-sort.o: util.h
$(OBJS_DIR)/merge-sort.o: util.h
$(OBJS_DIR)/count-sort.o: util.h
$(OBJS_DIR)/quick-sort.o: util.h

clean:
	rm $(OBJS_DIR)/*.o
	rm -f $(BIN_DIR)/*
