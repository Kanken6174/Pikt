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
CMAKE_SOURCE_DIR = /home/kanken/code/tcpp-adv/Pikt/src/pikt-io

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanken/code/tcpp-adv/Pikt/src/pikt-io

# Include any dependencies generated for this target.
include CMakeFiles/pikt_io.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pikt_io.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pikt_io.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pikt_io.dir/flags.make

CMakeFiles/pikt_io.dir/_factory.cpp.o: CMakeFiles/pikt_io.dir/flags.make
CMakeFiles/pikt_io.dir/_factory.cpp.o: _factory.cpp
CMakeFiles/pikt_io.dir/_factory.cpp.o: CMakeFiles/pikt_io.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/tcpp-adv/Pikt/src/pikt-io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pikt_io.dir/_factory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pikt_io.dir/_factory.cpp.o -MF CMakeFiles/pikt_io.dir/_factory.cpp.o.d -o CMakeFiles/pikt_io.dir/_factory.cpp.o -c /home/kanken/code/tcpp-adv/Pikt/src/pikt-io/_factory.cpp

CMakeFiles/pikt_io.dir/_factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pikt_io.dir/_factory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/tcpp-adv/Pikt/src/pikt-io/_factory.cpp > CMakeFiles/pikt_io.dir/_factory.cpp.i

CMakeFiles/pikt_io.dir/_factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pikt_io.dir/_factory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/tcpp-adv/Pikt/src/pikt-io/_factory.cpp -o CMakeFiles/pikt_io.dir/_factory.cpp.s

# Object files for target pikt_io
pikt_io_OBJECTS = \
"CMakeFiles/pikt_io.dir/_factory.cpp.o"

# External object files for target pikt_io
pikt_io_EXTERNAL_OBJECTS =

/home/kanken/code/tcpp-adv/Pikt/bin/plugins/libpikt_io.so: CMakeFiles/pikt_io.dir/_factory.cpp.o
/home/kanken/code/tcpp-adv/Pikt/bin/plugins/libpikt_io.so: CMakeFiles/pikt_io.dir/build.make
/home/kanken/code/tcpp-adv/Pikt/bin/plugins/libpikt_io.so: CMakeFiles/pikt_io.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/tcpp-adv/Pikt/src/pikt-io/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/kanken/code/tcpp-adv/Pikt/bin/plugins/libpikt_io.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pikt_io.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pikt_io.dir/build: /home/kanken/code/tcpp-adv/Pikt/bin/plugins/libpikt_io.so
.PHONY : CMakeFiles/pikt_io.dir/build

CMakeFiles/pikt_io.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pikt_io.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pikt_io.dir/clean

CMakeFiles/pikt_io.dir/depend:
	cd /home/kanken/code/tcpp-adv/Pikt/src/pikt-io && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/tcpp-adv/Pikt/src/pikt-io /home/kanken/code/tcpp-adv/Pikt/src/pikt-io /home/kanken/code/tcpp-adv/Pikt/src/pikt-io /home/kanken/code/tcpp-adv/Pikt/src/pikt-io /home/kanken/code/tcpp-adv/Pikt/src/pikt-io/CMakeFiles/pikt_io.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pikt_io.dir/depend

