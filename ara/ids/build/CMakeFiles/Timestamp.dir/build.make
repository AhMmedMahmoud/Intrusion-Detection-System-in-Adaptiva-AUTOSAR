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
include CMakeFiles/Timestamp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Timestamp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Timestamp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Timestamp.dir/flags.make

CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.o: CMakeFiles/Timestamp.dir/flags.make
CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.o: ../samples/internalClassesofIDSMessage/Timestamp.cpp
CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.o: CMakeFiles/Timestamp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.o -MF CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.o.d -o CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.o -c /home/ahmed/coding/myAdatpivePlatform/ids/samples/internalClassesofIDSMessage/Timestamp.cpp

CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/myAdatpivePlatform/ids/samples/internalClassesofIDSMessage/Timestamp.cpp > CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.i

CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/myAdatpivePlatform/ids/samples/internalClassesofIDSMessage/Timestamp.cpp -o CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.s

# Object files for target Timestamp
Timestamp_OBJECTS = \
"CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.o"

# External object files for target Timestamp
Timestamp_EXTERNAL_OBJECTS =

Timestamp: CMakeFiles/Timestamp.dir/samples/internalClassesofIDSMessage/Timestamp.cpp.o
Timestamp: CMakeFiles/Timestamp.dir/build.make
Timestamp: libids.a
Timestamp: com/libaraCom.a
Timestamp: core/libCore.a
Timestamp: crypto/libCrypto.a
Timestamp: CMakeFiles/Timestamp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Timestamp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Timestamp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Timestamp.dir/build: Timestamp
.PHONY : CMakeFiles/Timestamp.dir/build

CMakeFiles/Timestamp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Timestamp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Timestamp.dir/clean

CMakeFiles/Timestamp.dir/depend:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles/Timestamp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Timestamp.dir/depend

