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
include CMakeFiles/IDSMessage.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/IDSMessage.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/IDSMessage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IDSMessage.dir/flags.make

CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.o: CMakeFiles/IDSMessage.dir/flags.make
CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.o: ../samples/demo_idsMessage.cpp
CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.o: CMakeFiles/IDSMessage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.o -MF CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.o.d -o CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.o -c /home/ahmed/coding/myAdatpivePlatform/ids/samples/demo_idsMessage.cpp

CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/myAdatpivePlatform/ids/samples/demo_idsMessage.cpp > CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.i

CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/myAdatpivePlatform/ids/samples/demo_idsMessage.cpp -o CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.s

# Object files for target IDSMessage
IDSMessage_OBJECTS = \
"CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.o"

# External object files for target IDSMessage
IDSMessage_EXTERNAL_OBJECTS =

IDSMessage: CMakeFiles/IDSMessage.dir/samples/demo_idsMessage.cpp.o
IDSMessage: CMakeFiles/IDSMessage.dir/build.make
IDSMessage: libids.a
IDSMessage: com/libaraCom.a
IDSMessage: core/libCore.a
IDSMessage: crypto/libCrypto.a
IDSMessage: CMakeFiles/IDSMessage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IDSMessage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IDSMessage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IDSMessage.dir/build: IDSMessage
.PHONY : CMakeFiles/IDSMessage.dir/build

CMakeFiles/IDSMessage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IDSMessage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IDSMessage.dir/clean

CMakeFiles/IDSMessage.dir/depend:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles/IDSMessage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IDSMessage.dir/depend

