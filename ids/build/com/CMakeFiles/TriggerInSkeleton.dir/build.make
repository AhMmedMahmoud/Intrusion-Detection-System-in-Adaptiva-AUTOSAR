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
CMAKE_SOURCE_DIR = /home/ahmed/coding/ids

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmed/coding/ids/build

# Include any dependencies generated for this target.
include com/CMakeFiles/TriggerInSkeleton.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include com/CMakeFiles/TriggerInSkeleton.dir/compiler_depend.make

# Include the progress variables for this target.
include com/CMakeFiles/TriggerInSkeleton.dir/progress.make

# Include the compile flags for this target's objects.
include com/CMakeFiles/TriggerInSkeleton.dir/flags.make

com/CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.o: com/CMakeFiles/TriggerInSkeleton.dir/flags.make
com/CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.o: /home/ahmed/coding/com/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp
com/CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.o: com/CMakeFiles/TriggerInSkeleton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object com/CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.o"
	cd /home/ahmed/coding/ids/build/com && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT com/CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.o -MF CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.o.d -o CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.o -c /home/ahmed/coding/com/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp

com/CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.i"
	cd /home/ahmed/coding/ids/build/com && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/com/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp > CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.i

com/CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.s"
	cd /home/ahmed/coding/ids/build/com && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/com/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp -o CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.s

# Object files for target TriggerInSkeleton
TriggerInSkeleton_OBJECTS = \
"CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.o"

# External object files for target TriggerInSkeleton
TriggerInSkeleton_EXTERNAL_OBJECTS =

com/TriggerInSkeleton: com/CMakeFiles/TriggerInSkeleton.dir/samples/sm_interfaces_demos/demo_TriggerInSkeleton.cpp.o
com/TriggerInSkeleton: com/CMakeFiles/TriggerInSkeleton.dir/build.make
com/TriggerInSkeleton: com/libaraCom.a
com/TriggerInSkeleton: com/CMakeFiles/TriggerInSkeleton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TriggerInSkeleton"
	cd /home/ahmed/coding/ids/build/com && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TriggerInSkeleton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
com/CMakeFiles/TriggerInSkeleton.dir/build: com/TriggerInSkeleton
.PHONY : com/CMakeFiles/TriggerInSkeleton.dir/build

com/CMakeFiles/TriggerInSkeleton.dir/clean:
	cd /home/ahmed/coding/ids/build/com && $(CMAKE_COMMAND) -P CMakeFiles/TriggerInSkeleton.dir/cmake_clean.cmake
.PHONY : com/CMakeFiles/TriggerInSkeleton.dir/clean

com/CMakeFiles/TriggerInSkeleton.dir/depend:
	cd /home/ahmed/coding/ids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/ids /home/ahmed/coding/com /home/ahmed/coding/ids/build /home/ahmed/coding/ids/build/com /home/ahmed/coding/ids/build/com/CMakeFiles/TriggerInSkeleton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : com/CMakeFiles/TriggerInSkeleton.dir/depend

