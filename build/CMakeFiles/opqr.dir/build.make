# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /opt/cmake-3.24.2-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.24.2-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/caozhanhao/dev/opqr-python

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caozhanhao/dev/opqr-python/build

# Include any dependencies generated for this target.
include CMakeFiles/opqr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/opqr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/opqr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opqr.dir/flags.make

CMakeFiles/opqr.dir/opqr-python.cpp.o: CMakeFiles/opqr.dir/flags.make
CMakeFiles/opqr.dir/opqr-python.cpp.o: /home/caozhanhao/dev/opqr-python/opqr-python.cpp
CMakeFiles/opqr.dir/opqr-python.cpp.o: CMakeFiles/opqr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caozhanhao/dev/opqr-python/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opqr.dir/opqr-python.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/opqr.dir/opqr-python.cpp.o -MF CMakeFiles/opqr.dir/opqr-python.cpp.o.d -o CMakeFiles/opqr.dir/opqr-python.cpp.o -c /home/caozhanhao/dev/opqr-python/opqr-python.cpp

CMakeFiles/opqr.dir/opqr-python.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opqr.dir/opqr-python.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caozhanhao/dev/opqr-python/opqr-python.cpp > CMakeFiles/opqr.dir/opqr-python.cpp.i

CMakeFiles/opqr.dir/opqr-python.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opqr.dir/opqr-python.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caozhanhao/dev/opqr-python/opqr-python.cpp -o CMakeFiles/opqr.dir/opqr-python.cpp.s

# Object files for target opqr
opqr_OBJECTS = \
"CMakeFiles/opqr.dir/opqr-python.cpp.o"

# External object files for target opqr
opqr_EXTERNAL_OBJECTS =

libopqr.a: CMakeFiles/opqr.dir/opqr-python.cpp.o
libopqr.a: CMakeFiles/opqr.dir/build.make
libopqr.a: CMakeFiles/opqr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caozhanhao/dev/opqr-python/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libopqr.a"
	$(CMAKE_COMMAND) -P CMakeFiles/opqr.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opqr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opqr.dir/build: libopqr.a
.PHONY : CMakeFiles/opqr.dir/build

CMakeFiles/opqr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opqr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opqr.dir/clean

CMakeFiles/opqr.dir/depend:
	cd /home/caozhanhao/dev/opqr-python/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caozhanhao/dev/opqr-python /home/caozhanhao/dev/opqr-python /home/caozhanhao/dev/opqr-python/build /home/caozhanhao/dev/opqr-python/build /home/caozhanhao/dev/opqr-python/build/CMakeFiles/opqr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opqr.dir/depend
