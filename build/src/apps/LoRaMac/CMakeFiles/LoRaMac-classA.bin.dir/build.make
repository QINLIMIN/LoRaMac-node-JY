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
CMAKE_SOURCE_DIR = /Users/jimmy/Documents/GitHub/LoRaMac-node-JY

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build

# Utility rule file for LoRaMac-classA.bin.

# Include the progress variables for this target.
include src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin.dir/progress.make

src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin: src/apps/LoRaMac/LoRaMac-classA
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/apps/LoRaMac && /usr/local/bin/arm-none-eabi-objcopy -Obinary LoRaMac-classA LoRaMac-classA.bin

LoRaMac-classA.bin: src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin
LoRaMac-classA.bin: src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin.dir/build.make

.PHONY : LoRaMac-classA.bin

# Rule to build all files generated by this target.
src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin.dir/build: LoRaMac-classA.bin

.PHONY : src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin.dir/build

src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin.dir/clean:
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/apps/LoRaMac && $(CMAKE_COMMAND) -P CMakeFiles/LoRaMac-classA.bin.dir/cmake_clean.cmake
.PHONY : src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin.dir/clean

src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin.dir/depend:
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jimmy/Documents/GitHub/LoRaMac-node-JY /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/apps/LoRaMac /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/apps/LoRaMac /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/apps/LoRaMac/CMakeFiles/LoRaMac-classA.bin.dir/depend

