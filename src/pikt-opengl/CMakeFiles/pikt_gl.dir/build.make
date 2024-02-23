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
CMAKE_SOURCE_DIR = /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl

# Include any dependencies generated for this target.
include CMakeFiles/pikt_gl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pikt_gl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pikt_gl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pikt_gl.dir/flags.make

CMakeFiles/pikt_gl.dir/_factory.cpp.o: CMakeFiles/pikt_gl.dir/flags.make
CMakeFiles/pikt_gl.dir/_factory.cpp.o: _factory.cpp
CMakeFiles/pikt_gl.dir/_factory.cpp.o: CMakeFiles/pikt_gl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanken/code/cpp-adv/Pikt/src/pikt-opengl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pikt_gl.dir/_factory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pikt_gl.dir/_factory.cpp.o -MF CMakeFiles/pikt_gl.dir/_factory.cpp.o.d -o CMakeFiles/pikt_gl.dir/_factory.cpp.o -c /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl/_factory.cpp

CMakeFiles/pikt_gl.dir/_factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pikt_gl.dir/_factory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl/_factory.cpp > CMakeFiles/pikt_gl.dir/_factory.cpp.i

CMakeFiles/pikt_gl.dir/_factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pikt_gl.dir/_factory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl/_factory.cpp -o CMakeFiles/pikt_gl.dir/_factory.cpp.s

# Object files for target pikt_gl
pikt_gl_OBJECTS = \
"CMakeFiles/pikt_gl.dir/_factory.cpp.o"

# External object files for target pikt_gl
pikt_gl_EXTERNAL_OBJECTS =

/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: CMakeFiles/pikt_gl.dir/_factory.cpp.o
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: CMakeFiles/pikt_gl.dir/build.make
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: /usr/lib/x86_64-linux-gnu/libGLEW.so
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: /usr/lib/x86_64-linux-gnu/libGLEW.so
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: /usr/lib/x86_64-linux-gnu/libOpenGL.so
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: /usr/lib/x86_64-linux-gnu/libGLX.so
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: /usr/lib/x86_64-linux-gnu/libGLU.so
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: /usr/lib/gcc/x86_64-linux-gnu/11/libgomp.so
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: /usr/lib/x86_64-linux-gnu/libpthread.a
/home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so: CMakeFiles/pikt_gl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanken/code/cpp-adv/Pikt/src/pikt-opengl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pikt_gl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pikt_gl.dir/build: /home/kanken/code/cpp-adv/Pikt/bin/plugins/libpikt_gl.so
.PHONY : CMakeFiles/pikt_gl.dir/build

CMakeFiles/pikt_gl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pikt_gl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pikt_gl.dir/clean

CMakeFiles/pikt_gl.dir/depend:
	cd /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl /home/kanken/code/cpp-adv/Pikt/src/pikt-opengl/CMakeFiles/pikt_gl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pikt_gl.dir/depend

