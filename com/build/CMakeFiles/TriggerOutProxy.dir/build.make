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
include CMakeFiles/TriggerOutProxy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TriggerOutProxy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TriggerOutProxy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TriggerOutProxy.dir/flags.make

CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.o: CMakeFiles/TriggerOutProxy.dir/flags.make
CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.o: ../samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp
CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.o: CMakeFiles/TriggerOutProxy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/com/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.o -MF CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.o.d -o CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.o -c /home/ahmed/coding/com/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp

CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/com/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp > CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.i

CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/com/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp -o CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.s

# Object files for target TriggerOutProxy
TriggerOutProxy_OBJECTS = \
"CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.o"

# External object files for target TriggerOutProxy
TriggerOutProxy_EXTERNAL_OBJECTS =

TriggerOutProxy: CMakeFiles/TriggerOutProxy.dir/samples/sm_interfaces_demos/demo_TriggerOutProxy.cpp.o
TriggerOutProxy: CMakeFiles/TriggerOutProxy.dir/build.make
TriggerOutProxy: libaraCom.a
TriggerOutProxy: CMakeFiles/TriggerOutProxy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/com/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TriggerOutProxy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TriggerOutProxy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TriggerOutProxy.dir/build: TriggerOutProxy
.PHONY : CMakeFiles/TriggerOutProxy.dir/build

CMakeFiles/TriggerOutProxy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TriggerOutProxy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TriggerOutProxy.dir/clean

CMakeFiles/TriggerOutProxy.dir/depend:
	cd /home/ahmed/coding/com/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/com /home/ahmed/coding/com /home/ahmed/coding/com/build /home/ahmed/coding/com/build /home/ahmed/coding/com/build/CMakeFiles/TriggerOutProxy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TriggerOutProxy.dir/depend

