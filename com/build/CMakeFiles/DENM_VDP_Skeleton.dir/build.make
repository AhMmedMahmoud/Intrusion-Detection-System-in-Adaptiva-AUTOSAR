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
include CMakeFiles/DENM_VDP_Skeleton.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DENM_VDP_Skeleton.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DENM_VDP_Skeleton.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DENM_VDP_Skeleton.dir/flags.make

CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.o: CMakeFiles/DENM_VDP_Skeleton.dir/flags.make
CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.o: ../samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp
CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.o: CMakeFiles/DENM_VDP_Skeleton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/com/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.o -MF CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.o.d -o CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.o -c /home/ahmed/coding/com/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp

CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/com/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp > CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.i

CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/com/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp -o CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.s

# Object files for target DENM_VDP_Skeleton
DENM_VDP_Skeleton_OBJECTS = \
"CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.o"

# External object files for target DENM_VDP_Skeleton
DENM_VDP_Skeleton_EXTERNAL_OBJECTS =

DENM_VDP_Skeleton: CMakeFiles/DENM_VDP_Skeleton.dir/samples/V2X_interfaces_demos/demo_DENM_VDP_Skeleton.cpp.o
DENM_VDP_Skeleton: CMakeFiles/DENM_VDP_Skeleton.dir/build.make
DENM_VDP_Skeleton: libaraCom.a
DENM_VDP_Skeleton: CMakeFiles/DENM_VDP_Skeleton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/com/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DENM_VDP_Skeleton"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DENM_VDP_Skeleton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DENM_VDP_Skeleton.dir/build: DENM_VDP_Skeleton
.PHONY : CMakeFiles/DENM_VDP_Skeleton.dir/build

CMakeFiles/DENM_VDP_Skeleton.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DENM_VDP_Skeleton.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DENM_VDP_Skeleton.dir/clean

CMakeFiles/DENM_VDP_Skeleton.dir/depend:
	cd /home/ahmed/coding/com/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/com /home/ahmed/coding/com /home/ahmed/coding/com/build /home/ahmed/coding/com/build /home/ahmed/coding/com/build/CMakeFiles/DENM_VDP_Skeleton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DENM_VDP_Skeleton.dir/depend

