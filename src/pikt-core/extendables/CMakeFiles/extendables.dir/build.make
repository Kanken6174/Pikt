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
CMAKE_SOURCE_DIR = /home/kanken/code/cpp-adv/Pikt/src/pikt-core

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanken/code/cpp-adv/Pikt/src/pikt-core

# Include any dependencies generated for this target.
include extendables/CMakeFiles/extendables.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include extendables/CMakeFiles/extendables.dir/compiler_depend.make

# Include the progress variables for this target.
include extendables/CMakeFiles/extendables.dir/progress.make

# Include the compile flags for this target's objects.
include extendables/CMakeFiles/extendables.dir/flags.make

extendables/CMakeFiles/extendables.dir/plugin.cpp.o: extendables/CMakeFiles/extendables.dir/flags.make
extendables/CMakeFiles/extendables.dir/plugin.cpp.o: extendables/plugin.cpp
extendables/CMakeFiles/extendables.dir/plugin.cpp.o: extendables/CMakeFiles/extendables.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/cpp-adv/Pikt/src/pikt-core/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object extendables/CMakeFiles/extendables.dir/plugin.cpp.o"
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT extendables/CMakeFiles/extendables.dir/plugin.cpp.o -MF CMakeFiles/extendables.dir/plugin.cpp.o.d -o CMakeFiles/extendables.dir/plugin.cpp.o -c /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables/plugin.cpp

extendables/CMakeFiles/extendables.dir/plugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/extendables.dir/plugin.cpp.i"
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables/plugin.cpp > CMakeFiles/extendables.dir/plugin.cpp.i

extendables/CMakeFiles/extendables.dir/plugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/extendables.dir/plugin.cpp.s"
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables/plugin.cpp -o CMakeFiles/extendables.dir/plugin.cpp.s

extendables/CMakeFiles/extendables.dir/pluginManager.cpp.o: extendables/CMakeFiles/extendables.dir/flags.make
extendables/CMakeFiles/extendables.dir/pluginManager.cpp.o: extendables/pluginManager.cpp
extendables/CMakeFiles/extendables.dir/pluginManager.cpp.o: extendables/CMakeFiles/extendables.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/cpp-adv/Pikt/src/pikt-core/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object extendables/CMakeFiles/extendables.dir/pluginManager.cpp.o"
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT extendables/CMakeFiles/extendables.dir/pluginManager.cpp.o -MF CMakeFiles/extendables.dir/pluginManager.cpp.o.d -o CMakeFiles/extendables.dir/pluginManager.cpp.o -c /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables/pluginManager.cpp

extendables/CMakeFiles/extendables.dir/pluginManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/extendables.dir/pluginManager.cpp.i"
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables/pluginManager.cpp > CMakeFiles/extendables.dir/pluginManager.cpp.i

extendables/CMakeFiles/extendables.dir/pluginManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/extendables.dir/pluginManager.cpp.s"
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables/pluginManager.cpp -o CMakeFiles/extendables.dir/pluginManager.cpp.s

# Object files for target extendables
extendables_OBJECTS = \
"CMakeFiles/extendables.dir/plugin.cpp.o" \
"CMakeFiles/extendables.dir/pluginManager.cpp.o"

# External object files for target extendables
extendables_EXTERNAL_OBJECTS =

extendables/libextendables.a: extendables/CMakeFiles/extendables.dir/plugin.cpp.o
extendables/libextendables.a: extendables/CMakeFiles/extendables.dir/pluginManager.cpp.o
extendables/libextendables.a: extendables/CMakeFiles/extendables.dir/build.make
extendables/libextendables.a: extendables/CMakeFiles/extendables.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/cpp-adv/Pikt/src/pikt-core/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libextendables.a"
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables && $(CMAKE_COMMAND) -P CMakeFiles/extendables.dir/cmake_clean_target.cmake
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/extendables.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extendables/CMakeFiles/extendables.dir/build: extendables/libextendables.a
.PHONY : extendables/CMakeFiles/extendables.dir/build

extendables/CMakeFiles/extendables.dir/clean:
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables && $(CMAKE_COMMAND) -P CMakeFiles/extendables.dir/cmake_clean.cmake
.PHONY : extendables/CMakeFiles/extendables.dir/clean

extendables/CMakeFiles/extendables.dir/depend:
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-core && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/cpp-adv/Pikt/src/pikt-core /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables /home/kanken/code/cpp-adv/Pikt/src/pikt-core /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables /home/kanken/code/cpp-adv/Pikt/src/pikt-core/extendables/CMakeFiles/extendables.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extendables/CMakeFiles/extendables.dir/depend

