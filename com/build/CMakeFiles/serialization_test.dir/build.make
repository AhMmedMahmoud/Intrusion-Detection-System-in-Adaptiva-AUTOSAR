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
CMAKE_SOURCE_DIR = /home/ahmed/coding/com

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmed/coding/com/build

# Include any dependencies generated for this target.
include CMakeFiles/serialization_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/serialization_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/serialization_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serialization_test.dir/flags.make

CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.o: CMakeFiles/serialization_test.dir/flags.make
CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.o: ../samples/serialization_test.cpp
CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.o: CMakeFiles/serialization_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/com/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.o -MF CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.o.d -o CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.o -c /home/ahmed/coding/com/samples/serialization_test.cpp

CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/com/samples/serialization_test.cpp > CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.i

CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/com/samples/serialization_test.cpp -o CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.s

# Object files for target serialization_test
serialization_test_OBJECTS = \
"CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.o"

# External object files for target serialization_test
serialization_test_EXTERNAL_OBJECTS =

serialization_test: CMakeFiles/serialization_test.dir/samples/serialization_test.cpp.o
serialization_test: CMakeFiles/serialization_test.dir/build.make
serialization_test: libaraCom.a
serialization_test: CMakeFiles/serialization_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/com/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable serialization_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serialization_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serialization_test.dir/build: serialization_test
.PHONY : CMakeFiles/serialization_test.dir/build

CMakeFiles/serialization_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serialization_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serialization_test.dir/clean

CMakeFiles/serialization_test.dir/depend:
	cd /home/ahmed/coding/com/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/com /home/ahmed/coding/com /home/ahmed/coding/com/build /home/ahmed/coding/com/build /home/ahmed/coding/com/build/CMakeFiles/serialization_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serialization_test.dir/depend

