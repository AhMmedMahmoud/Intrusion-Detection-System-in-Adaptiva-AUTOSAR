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
CMAKE_SOURCE_DIR = /home/ahmed/coding/myAdatpivePlatform/ids

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmed/coding/myAdatpivePlatform/ids/build

# Include any dependencies generated for this target.
include crypto/CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include crypto/CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include crypto/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include crypto/CMakeFiles/test.dir/flags.make

crypto/CMakeFiles/test.dir/samples/test.cpp.o: crypto/CMakeFiles/test.dir/flags.make
crypto/CMakeFiles/test.dir/samples/test.cpp.o: /home/ahmed/coding/myAdatpivePlatform/crypto/samples/test.cpp
crypto/CMakeFiles/test.dir/samples/test.cpp.o: crypto/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object crypto/CMakeFiles/test.dir/samples/test.cpp.o"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT crypto/CMakeFiles/test.dir/samples/test.cpp.o -MF CMakeFiles/test.dir/samples/test.cpp.o.d -o CMakeFiles/test.dir/samples/test.cpp.o -c /home/ahmed/coding/myAdatpivePlatform/crypto/samples/test.cpp

crypto/CMakeFiles/test.dir/samples/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/samples/test.cpp.i"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/myAdatpivePlatform/crypto/samples/test.cpp > CMakeFiles/test.dir/samples/test.cpp.i

crypto/CMakeFiles/test.dir/samples/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/samples/test.cpp.s"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/myAdatpivePlatform/crypto/samples/test.cpp -o CMakeFiles/test.dir/samples/test.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/samples/test.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

crypto/test: crypto/CMakeFiles/test.dir/samples/test.cpp.o
crypto/test: crypto/CMakeFiles/test.dir/build.make
crypto/test: core/libCore.a
crypto/test: crypto/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crypto/CMakeFiles/test.dir/build: crypto/test
.PHONY : crypto/CMakeFiles/test.dir/build

crypto/CMakeFiles/test.dir/clean:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : crypto/CMakeFiles/test.dir/clean

crypto/CMakeFiles/test.dir/depend:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/crypto /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crypto/CMakeFiles/test.dir/depend

