# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/elm/Documents/GitHub/TCG_2019_project4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/elm/Documents/GitHub/TCG_2019_project4

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/Users/elm/Documents/GitHub/TCG_2019_project4/CMakeFiles /mnt/c/Users/elm/Documents/GitHub/TCG_2019_project4/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/Users/elm/Documents/GitHub/TCG_2019_project4/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named hahanogo

# Build rule for target.
hahanogo: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 hahanogo
.PHONY : hahanogo

# fast build rule for target.
hahanogo/fast:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/build
.PHONY : hahanogo/fast

MCTStree.o: MCTStree.cpp.o

.PHONY : MCTStree.o

# target to build an object file
MCTStree.cpp.o:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/MCTStree.cpp.o
.PHONY : MCTStree.cpp.o

MCTStree.i: MCTStree.cpp.i

.PHONY : MCTStree.i

# target to preprocess a source file
MCTStree.cpp.i:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/MCTStree.cpp.i
.PHONY : MCTStree.cpp.i

MCTStree.s: MCTStree.cpp.s

.PHONY : MCTStree.s

# target to generate assembly for a file
MCTStree.cpp.s:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/MCTStree.cpp.s
.PHONY : MCTStree.cpp.s

Main.o: Main.cpp.o

.PHONY : Main.o

# target to build an object file
Main.cpp.o:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/Main.cpp.o
.PHONY : Main.cpp.o

Main.i: Main.cpp.i

.PHONY : Main.i

# target to preprocess a source file
Main.cpp.i:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/Main.cpp.i
.PHONY : Main.cpp.i

Main.s: Main.cpp.s

.PHONY : Main.s

# target to generate assembly for a file
Main.cpp.s:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/Main.cpp.s
.PHONY : Main.cpp.s

board.o: board.cpp.o

.PHONY : board.o

# target to build an object file
board.cpp.o:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/board.cpp.o
.PHONY : board.cpp.o

board.i: board.cpp.i

.PHONY : board.i

# target to preprocess a source file
board.cpp.i:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/board.cpp.i
.PHONY : board.cpp.i

board.s: board.cpp.s

.PHONY : board.s

# target to generate assembly for a file
board.cpp.s:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/board.cpp.s
.PHONY : board.cpp.s

ucbnode.o: ucbnode.cpp.o

.PHONY : ucbnode.o

# target to build an object file
ucbnode.cpp.o:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/ucbnode.cpp.o
.PHONY : ucbnode.cpp.o

ucbnode.i: ucbnode.cpp.i

.PHONY : ucbnode.i

# target to preprocess a source file
ucbnode.cpp.i:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/ucbnode.cpp.i
.PHONY : ucbnode.cpp.i

ucbnode.s: ucbnode.cpp.s

.PHONY : ucbnode.s

# target to generate assembly for a file
ucbnode.cpp.s:
	$(MAKE) -f CMakeFiles/hahanogo.dir/build.make CMakeFiles/hahanogo.dir/ucbnode.cpp.s
.PHONY : ucbnode.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... hahanogo"
	@echo "... edit_cache"
	@echo "... MCTStree.o"
	@echo "... MCTStree.i"
	@echo "... MCTStree.s"
	@echo "... Main.o"
	@echo "... Main.i"
	@echo "... Main.s"
	@echo "... board.o"
	@echo "... board.i"
	@echo "... board.s"
	@echo "... ucbnode.o"
	@echo "... ucbnode.i"
	@echo "... ucbnode.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
