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
include com/CMakeFiles/DENM_Server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include com/CMakeFiles/DENM_Server.dir/compiler_depend.make

# Include the progress variables for this target.
include com/CMakeFiles/DENM_Server.dir/progress.make

# Include the compile flags for this target's objects.
include com/CMakeFiles/DENM_Server.dir/flags.make

com/CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.o: com/CMakeFiles/DENM_Server.dir/flags.make
com/CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.o: /home/ahmed/coding/myAdatpivePlatform/com/samples/V2X_interfaces_demos/demo_DENM_Server.cpp
com/CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.o: com/CMakeFiles/DENM_Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object com/CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.o"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/com && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT com/CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.o -MF CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.o.d -o CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.o -c /home/ahmed/coding/myAdatpivePlatform/com/samples/V2X_interfaces_demos/demo_DENM_Server.cpp

com/CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.i"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/com && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/myAdatpivePlatform/com/samples/V2X_interfaces_demos/demo_DENM_Server.cpp > CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.i

com/CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.s"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/com && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/myAdatpivePlatform/com/samples/V2X_interfaces_demos/demo_DENM_Server.cpp -o CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.s

# Object files for target DENM_Server
DENM_Server_OBJECTS = \
"CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.o"

# External object files for target DENM_Server
DENM_Server_EXTERNAL_OBJECTS =

com/DENM_Server: com/CMakeFiles/DENM_Server.dir/samples/V2X_interfaces_demos/demo_DENM_Server.cpp.o
com/DENM_Server: com/CMakeFiles/DENM_Server.dir/build.make
com/DENM_Server: com/libaraCom.a
com/DENM_Server: com/CMakeFiles/DENM_Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DENM_Server"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/com && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DENM_Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
com/CMakeFiles/DENM_Server.dir/build: com/DENM_Server
.PHONY : com/CMakeFiles/DENM_Server.dir/build

com/CMakeFiles/DENM_Server.dir/clean:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/com && $(CMAKE_COMMAND) -P CMakeFiles/DENM_Server.dir/cmake_clean.cmake
.PHONY : com/CMakeFiles/DENM_Server.dir/clean

com/CMakeFiles/DENM_Server.dir/depend:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/com /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build/com /home/ahmed/coding/myAdatpivePlatform/ids/build/com/CMakeFiles/DENM_Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : com/CMakeFiles/DENM_Server.dir/depend

