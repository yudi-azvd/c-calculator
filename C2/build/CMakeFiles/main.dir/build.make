# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/yudi/Documents/programming/projetos/calculator/C2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yudi/Documents/programming/projetos/calculator/C2/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/tests/random_tests/main.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/tests/random_tests/main.c.o: ../tests/random_tests/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yudi/Documents/programming/projetos/calculator/C2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/tests/random_tests/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/tests/random_tests/main.c.o   -c /home/yudi/Documents/programming/projetos/calculator/C2/tests/random_tests/main.c

CMakeFiles/main.dir/tests/random_tests/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/tests/random_tests/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yudi/Documents/programming/projetos/calculator/C2/tests/random_tests/main.c > CMakeFiles/main.dir/tests/random_tests/main.c.i

CMakeFiles/main.dir/tests/random_tests/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/tests/random_tests/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yudi/Documents/programming/projetos/calculator/C2/tests/random_tests/main.c -o CMakeFiles/main.dir/tests/random_tests/main.c.s

CMakeFiles/main.dir/tests/random_tests/main.c.o.requires:

.PHONY : CMakeFiles/main.dir/tests/random_tests/main.c.o.requires

CMakeFiles/main.dir/tests/random_tests/main.c.o.provides: CMakeFiles/main.dir/tests/random_tests/main.c.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/tests/random_tests/main.c.o.provides.build
.PHONY : CMakeFiles/main.dir/tests/random_tests/main.c.o.provides

CMakeFiles/main.dir/tests/random_tests/main.c.o.provides.build: CMakeFiles/main.dir/tests/random_tests/main.c.o


CMakeFiles/main.dir/src/terminal_functions.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/terminal_functions.c.o: ../src/terminal_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yudi/Documents/programming/projetos/calculator/C2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/src/terminal_functions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/src/terminal_functions.c.o   -c /home/yudi/Documents/programming/projetos/calculator/C2/src/terminal_functions.c

CMakeFiles/main.dir/src/terminal_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/src/terminal_functions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yudi/Documents/programming/projetos/calculator/C2/src/terminal_functions.c > CMakeFiles/main.dir/src/terminal_functions.c.i

CMakeFiles/main.dir/src/terminal_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/src/terminal_functions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yudi/Documents/programming/projetos/calculator/C2/src/terminal_functions.c -o CMakeFiles/main.dir/src/terminal_functions.c.s

CMakeFiles/main.dir/src/terminal_functions.c.o.requires:

.PHONY : CMakeFiles/main.dir/src/terminal_functions.c.o.requires

CMakeFiles/main.dir/src/terminal_functions.c.o.provides: CMakeFiles/main.dir/src/terminal_functions.c.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/terminal_functions.c.o.provides.build
.PHONY : CMakeFiles/main.dir/src/terminal_functions.c.o.provides

CMakeFiles/main.dir/src/terminal_functions.c.o.provides.build: CMakeFiles/main.dir/src/terminal_functions.c.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/tests/random_tests/main.c.o" \
"CMakeFiles/main.dir/src/terminal_functions.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/tests/random_tests/main.c.o
main: CMakeFiles/main.dir/src/terminal_functions.c.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yudi/Documents/programming/projetos/calculator/C2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/tests/random_tests/main.c.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/terminal_functions.c.o.requires

.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/yudi/Documents/programming/projetos/calculator/C2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yudi/Documents/programming/projetos/calculator/C2 /home/yudi/Documents/programming/projetos/calculator/C2 /home/yudi/Documents/programming/projetos/calculator/C2/build /home/yudi/Documents/programming/projetos/calculator/C2/build /home/yudi/Documents/programming/projetos/calculator/C2/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

