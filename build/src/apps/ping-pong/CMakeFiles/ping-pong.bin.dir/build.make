# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jimmy/Documents/GitHub/LoRaMac-node

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jimmy/Documents/GitHub/LoRaMac-node/build

# Utility rule file for ping-pong.bin.

# Include the progress variables for this target.
include src/apps/ping-pong/CMakeFiles/ping-pong.bin.dir/progress.make

src/apps/ping-pong/CMakeFiles/ping-pong.bin: src/apps/ping-pong/ping-pong
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node/build/src/apps/ping-pong && /usr/local/bin/arm-none-eabi-objcopy -Obinary ping-pong ping-pong.bin

ping-pong.bin: src/apps/ping-pong/CMakeFiles/ping-pong.bin
ping-pong.bin: src/apps/ping-pong/CMakeFiles/ping-pong.bin.dir/build.make

.PHONY : ping-pong.bin

# Rule to build all files generated by this target.
src/apps/ping-pong/CMakeFiles/ping-pong.bin.dir/build: ping-pong.bin

.PHONY : src/apps/ping-pong/CMakeFiles/ping-pong.bin.dir/build

src/apps/ping-pong/CMakeFiles/ping-pong.bin.dir/clean:
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node/build/src/apps/ping-pong && $(CMAKE_COMMAND) -P CMakeFiles/ping-pong.bin.dir/cmake_clean.cmake
.PHONY : src/apps/ping-pong/CMakeFiles/ping-pong.bin.dir/clean

src/apps/ping-pong/CMakeFiles/ping-pong.bin.dir/depend:
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jimmy/Documents/GitHub/LoRaMac-node /Users/jimmy/Documents/GitHub/LoRaMac-node/src/apps/ping-pong /Users/jimmy/Documents/GitHub/LoRaMac-node/build /Users/jimmy/Documents/GitHub/LoRaMac-node/build/src/apps/ping-pong /Users/jimmy/Documents/GitHub/LoRaMac-node/build/src/apps/ping-pong/CMakeFiles/ping-pong.bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/apps/ping-pong/CMakeFiles/ping-pong.bin.dir/depend
