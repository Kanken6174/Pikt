# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kanken/code/tcpp-adv/Pikt/src/pikt-core

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanken/code/tcpp-adv/Pikt/src/pikt-core

# Include any dependencies generated for this target.
include dependencies/CMakeFiles/dependencies.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dependencies/CMakeFiles/dependencies.dir/compiler_depend.make

# Include the progress variables for this target.
include dependencies/CMakeFiles/dependencies.dir/progress.make

# Include the compile flags for this target's objects.
include dependencies/CMakeFiles/dependencies.dir/flags.make

# Object files for target dependencies
dependencies_OBJECTS =

# External object files for target dependencies
dependencies_EXTERNAL_OBJECTS =

dependencies/libdependencies.a: dependencies/CMakeFiles/dependencies.dir/build.make
dependencies/libdependencies.a: dependencies/CMakeFiles/dependencies.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/tcpp-adv/Pikt/src/pikt-core/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libdependencies.a"
	cd /home/kanken/code/tcpp-adv/Pikt/src/pikt-core/dependencies && $(CMAKE_COMMAND) -P CMakeFiles/dependencies.dir/cmake_clean_target.cmake
	cd /home/kanken/code/tcpp-adv/Pikt/src/pikt-core/dependencies && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dependencies.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dependencies/CMakeFiles/dependencies.dir/build: dependencies/libdependencies.a
.PHONY : dependencies/CMakeFiles/dependencies.dir/build

dependencies/CMakeFiles/dependencies.dir/clean:
	cd /home/kanken/code/tcpp-adv/Pikt/src/pikt-core/dependencies && $(CMAKE_COMMAND) -P CMakeFiles/dependencies.dir/cmake_clean.cmake
.PHONY : dependencies/CMakeFiles/dependencies.dir/clean

dependencies/CMakeFiles/dependencies.dir/depend:
	cd /home/kanken/code/tcpp-adv/Pikt/src/pikt-core && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/tcpp-adv/Pikt/src/pikt-core /home/kanken/code/tcpp-adv/Pikt/src/pikt-core/dependencies /home/kanken/code/tcpp-adv/Pikt/src/pikt-core /home/kanken/code/tcpp-adv/Pikt/src/pikt-core/dependencies /home/kanken/code/tcpp-adv/Pikt/src/pikt-core/dependencies/CMakeFiles/dependencies.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dependencies/CMakeFiles/dependencies.dir/depend

