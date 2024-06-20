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
include CMakeFiles/idsm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/idsm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/idsm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/idsm.dir/flags.make

CMakeFiles/idsm.dir/samples/demo_idsm.cpp.o: CMakeFiles/idsm.dir/flags.make
CMakeFiles/idsm.dir/samples/demo_idsm.cpp.o: ../samples/demo_idsm.cpp
CMakeFiles/idsm.dir/samples/demo_idsm.cpp.o: CMakeFiles/idsm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/idsm.dir/samples/demo_idsm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/idsm.dir/samples/demo_idsm.cpp.o -MF CMakeFiles/idsm.dir/samples/demo_idsm.cpp.o.d -o CMakeFiles/idsm.dir/samples/demo_idsm.cpp.o -c /home/ahmed/coding/myAdatpivePlatform/ids/samples/demo_idsm.cpp

CMakeFiles/idsm.dir/samples/demo_idsm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/idsm.dir/samples/demo_idsm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/myAdatpivePlatform/ids/samples/demo_idsm.cpp > CMakeFiles/idsm.dir/samples/demo_idsm.cpp.i

CMakeFiles/idsm.dir/samples/demo_idsm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/idsm.dir/samples/demo_idsm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/myAdatpivePlatform/ids/samples/demo_idsm.cpp -o CMakeFiles/idsm.dir/samples/demo_idsm.cpp.s

# Object files for target idsm
idsm_OBJECTS = \
"CMakeFiles/idsm.dir/samples/demo_idsm.cpp.o"

# External object files for target idsm
idsm_EXTERNAL_OBJECTS =

idsm: CMakeFiles/idsm.dir/samples/demo_idsm.cpp.o
idsm: CMakeFiles/idsm.dir/build.make
idsm: libids.a
idsm: com/libaraCom.a
idsm: core/libCore.a
idsm: crypto/libCrypto.a
idsm: CMakeFiles/idsm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable idsm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/idsm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/idsm.dir/build: idsm
.PHONY : CMakeFiles/idsm.dir/build

CMakeFiles/idsm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/idsm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/idsm.dir/clean

CMakeFiles/idsm.dir/depend:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles/idsm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/idsm.dir/depend

