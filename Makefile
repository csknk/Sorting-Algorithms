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
#TEST_OBJS=$(OBJS_DIR)/stress-three-way.o
#OBJECT_FILES=$(filter-out $(TEST_OBJS),$(OBJECT_FILES))

.PHONY: all clean
all: $(EXECUTABLE_FILES)
#all: $(EXECUTABLE_FILES) $(BIN_DIR)/stress-three-way

$(BIN_DIR)/%: $(OBJS_DIR)/%.o
	@$(CXX) $(LDFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: %.cpp
	$(info Building object file for "$(<)")
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

#$(BIN_DIR)/stress-three-way: $(OBJS_DIR)/stress-three-way.o
#	@$(CXX) $(LDFLAGS) -o $@ $^
#
#$(OBJS_DIR)/stress-three-way.o: three-partition-qsort.cpp
#	$(info Building object file for "$(<)")
#	@mkdir -p $(@D)
#	@$(CXX) $(CXXFLAGS) -D STRESS_TEST -o $@ -c $<

$(OBJS_DIR)/selection-sort.o: util.h
$(OBJS_DIR)/merge-sort-simple.o: util.h
$(OBJS_DIR)/merge-sort-inversions.o: util.h
$(OBJS_DIR)/merge-sort.o: util.h
$(OBJS_DIR)/count-sort.o: util.h
$(OBJS_DIR)/quick-sort.o: util.h
$(OBJS_DIR)/three-partition-qsort.o: util.h
#$(OBJS_DIR)/stress-three-way.o: util.h

clean:
	rm $(OBJS_DIR)/*.o
	rm -f $(BIN_DIR)/*
