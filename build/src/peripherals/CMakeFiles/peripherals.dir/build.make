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

# Include any dependencies generated for this target.
include src/peripherals/CMakeFiles/peripherals.dir/depend.make

# Include the progress variables for this target.
include src/peripherals/CMakeFiles/peripherals.dir/progress.make

# Include the compile flags for this target's objects.
include src/peripherals/CMakeFiles/peripherals.dir/flags.make

src/peripherals/CMakeFiles/peripherals.dir/gpio-ioe.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/gpio-ioe.c.obj: ../src/peripherals/gpio-ioe.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/peripherals/CMakeFiles/peripherals.dir/gpio-ioe.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/gpio-ioe.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/gpio-ioe.c

src/peripherals/CMakeFiles/peripherals.dir/gpio-ioe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/gpio-ioe.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/gpio-ioe.c > CMakeFiles/peripherals.dir/gpio-ioe.c.i

src/peripherals/CMakeFiles/peripherals.dir/gpio-ioe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/gpio-ioe.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/gpio-ioe.c -o CMakeFiles/peripherals.dir/gpio-ioe.c.s

src/peripherals/CMakeFiles/peripherals.dir/mag3110.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/mag3110.c.obj: ../src/peripherals/mag3110.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/peripherals/CMakeFiles/peripherals.dir/mag3110.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/mag3110.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/mag3110.c

src/peripherals/CMakeFiles/peripherals.dir/mag3110.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/mag3110.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/mag3110.c > CMakeFiles/peripherals.dir/mag3110.c.i

src/peripherals/CMakeFiles/peripherals.dir/mag3110.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/mag3110.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/mag3110.c -o CMakeFiles/peripherals.dir/mag3110.c.s

src/peripherals/CMakeFiles/peripherals.dir/mma8451.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/mma8451.c.obj: ../src/peripherals/mma8451.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/peripherals/CMakeFiles/peripherals.dir/mma8451.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/mma8451.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/mma8451.c

src/peripherals/CMakeFiles/peripherals.dir/mma8451.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/mma8451.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/mma8451.c > CMakeFiles/peripherals.dir/mma8451.c.i

src/peripherals/CMakeFiles/peripherals.dir/mma8451.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/mma8451.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/mma8451.c -o CMakeFiles/peripherals.dir/mma8451.c.s

src/peripherals/CMakeFiles/peripherals.dir/mpl3115.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/mpl3115.c.obj: ../src/peripherals/mpl3115.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/peripherals/CMakeFiles/peripherals.dir/mpl3115.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/mpl3115.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/mpl3115.c

src/peripherals/CMakeFiles/peripherals.dir/mpl3115.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/mpl3115.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/mpl3115.c > CMakeFiles/peripherals.dir/mpl3115.c.i

src/peripherals/CMakeFiles/peripherals.dir/mpl3115.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/mpl3115.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/mpl3115.c -o CMakeFiles/peripherals.dir/mpl3115.c.s

src/peripherals/CMakeFiles/peripherals.dir/pam7q.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/pam7q.c.obj: ../src/peripherals/pam7q.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/peripherals/CMakeFiles/peripherals.dir/pam7q.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/pam7q.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/pam7q.c

src/peripherals/CMakeFiles/peripherals.dir/pam7q.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/pam7q.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/pam7q.c > CMakeFiles/peripherals.dir/pam7q.c.i

src/peripherals/CMakeFiles/peripherals.dir/pam7q.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/pam7q.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/pam7q.c -o CMakeFiles/peripherals.dir/pam7q.c.s

src/peripherals/CMakeFiles/peripherals.dir/soft-se/aes.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/soft-se/aes.c.obj: ../src/peripherals/soft-se/aes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/peripherals/CMakeFiles/peripherals.dir/soft-se/aes.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/soft-se/aes.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/aes.c

src/peripherals/CMakeFiles/peripherals.dir/soft-se/aes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/soft-se/aes.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/aes.c > CMakeFiles/peripherals.dir/soft-se/aes.c.i

src/peripherals/CMakeFiles/peripherals.dir/soft-se/aes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/soft-se/aes.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/aes.c -o CMakeFiles/peripherals.dir/soft-se/aes.c.s

src/peripherals/CMakeFiles/peripherals.dir/soft-se/cmac.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/soft-se/cmac.c.obj: ../src/peripherals/soft-se/cmac.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/peripherals/CMakeFiles/peripherals.dir/soft-se/cmac.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/soft-se/cmac.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/cmac.c

src/peripherals/CMakeFiles/peripherals.dir/soft-se/cmac.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/soft-se/cmac.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/cmac.c > CMakeFiles/peripherals.dir/soft-se/cmac.c.i

src/peripherals/CMakeFiles/peripherals.dir/soft-se/cmac.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/soft-se/cmac.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/cmac.c -o CMakeFiles/peripherals.dir/soft-se/cmac.c.s

src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.obj: ../src/peripherals/soft-se/soft-se-hal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/soft-se-hal.c

src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/soft-se-hal.c > CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.i

src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/soft-se-hal.c -o CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.s

src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se.c.obj: ../src/peripherals/soft-se/soft-se.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/soft-se/soft-se.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/soft-se.c

src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/soft-se/soft-se.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/soft-se.c > CMakeFiles/peripherals.dir/soft-se/soft-se.c.i

src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/soft-se/soft-se.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/soft-se/soft-se.c -o CMakeFiles/peripherals.dir/soft-se/soft-se.c.s

src/peripherals/CMakeFiles/peripherals.dir/sx1509.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/sx1509.c.obj: ../src/peripherals/sx1509.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/peripherals/CMakeFiles/peripherals.dir/sx1509.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/sx1509.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/sx1509.c

src/peripherals/CMakeFiles/peripherals.dir/sx1509.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/sx1509.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/sx1509.c > CMakeFiles/peripherals.dir/sx1509.c.i

src/peripherals/CMakeFiles/peripherals.dir/sx1509.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/sx1509.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/sx1509.c -o CMakeFiles/peripherals.dir/sx1509.c.s

src/peripherals/CMakeFiles/peripherals.dir/sx9500.c.obj: src/peripherals/CMakeFiles/peripherals.dir/flags.make
src/peripherals/CMakeFiles/peripherals.dir/sx9500.c.obj: ../src/peripherals/sx9500.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/peripherals/CMakeFiles/peripherals.dir/sx9500.c.obj"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/peripherals.dir/sx9500.c.obj -c /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/sx9500.c

src/peripherals/CMakeFiles/peripherals.dir/sx9500.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/peripherals.dir/sx9500.c.i"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/sx9500.c > CMakeFiles/peripherals.dir/sx9500.c.i

src/peripherals/CMakeFiles/peripherals.dir/sx9500.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/peripherals.dir/sx9500.c.s"
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && /usr/local/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals/sx9500.c -o CMakeFiles/peripherals.dir/sx9500.c.s

peripherals: src/peripherals/CMakeFiles/peripherals.dir/gpio-ioe.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/mag3110.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/mma8451.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/mpl3115.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/pam7q.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/soft-se/aes.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/soft-se/cmac.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se-hal.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/soft-se/soft-se.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/sx1509.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/sx9500.c.obj
peripherals: src/peripherals/CMakeFiles/peripherals.dir/build.make

.PHONY : peripherals

# Rule to build all files generated by this target.
src/peripherals/CMakeFiles/peripherals.dir/build: peripherals

.PHONY : src/peripherals/CMakeFiles/peripherals.dir/build

src/peripherals/CMakeFiles/peripherals.dir/clean:
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals && $(CMAKE_COMMAND) -P CMakeFiles/peripherals.dir/cmake_clean.cmake
.PHONY : src/peripherals/CMakeFiles/peripherals.dir/clean

src/peripherals/CMakeFiles/peripherals.dir/depend:
	cd /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jimmy/Documents/GitHub/LoRaMac-node-JY /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/src/peripherals /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals /Users/jimmy/Documents/GitHub/LoRaMac-node-JY/build/src/peripherals/CMakeFiles/peripherals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/peripherals/CMakeFiles/peripherals.dir/depend

