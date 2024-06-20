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
include crypto/CMakeFiles/demo_loadingECDSAKeys.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include crypto/CMakeFiles/demo_loadingECDSAKeys.dir/compiler_depend.make

# Include the progress variables for this target.
include crypto/CMakeFiles/demo_loadingECDSAKeys.dir/progress.make

# Include the compile flags for this target's objects.
include crypto/CMakeFiles/demo_loadingECDSAKeys.dir/flags.make

crypto/CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.o: crypto/CMakeFiles/demo_loadingECDSAKeys.dir/flags.make
crypto/CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.o: /home/ahmed/coding/myAdatpivePlatform/crypto/samples/Demos/demo_loadingECDSAKeys.cpp
crypto/CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.o: crypto/CMakeFiles/demo_loadingECDSAKeys.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object crypto/CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.o"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT crypto/CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.o -MF CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.o.d -o CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.o -c /home/ahmed/coding/myAdatpivePlatform/crypto/samples/Demos/demo_loadingECDSAKeys.cpp

crypto/CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.i"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/myAdatpivePlatform/crypto/samples/Demos/demo_loadingECDSAKeys.cpp > CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.i

crypto/CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.s"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/myAdatpivePlatform/crypto/samples/Demos/demo_loadingECDSAKeys.cpp -o CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.s

# Object files for target demo_loadingECDSAKeys
demo_loadingECDSAKeys_OBJECTS = \
"CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.o"

# External object files for target demo_loadingECDSAKeys
demo_loadingECDSAKeys_EXTERNAL_OBJECTS =

crypto/demo_loadingECDSAKeys: crypto/CMakeFiles/demo_loadingECDSAKeys.dir/samples/Demos/demo_loadingECDSAKeys.cpp.o
crypto/demo_loadingECDSAKeys: crypto/CMakeFiles/demo_loadingECDSAKeys.dir/build.make
crypto/demo_loadingECDSAKeys: core/libCore.a
crypto/demo_loadingECDSAKeys: crypto/libCrypto.a
crypto/demo_loadingECDSAKeys: /usr/lib/x86_64-linux-gnu/libcryptopp.so
crypto/demo_loadingECDSAKeys: crypto/CMakeFiles/demo_loadingECDSAKeys.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable demo_loadingECDSAKeys"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo_loadingECDSAKeys.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crypto/CMakeFiles/demo_loadingECDSAKeys.dir/build: crypto/demo_loadingECDSAKeys
.PHONY : crypto/CMakeFiles/demo_loadingECDSAKeys.dir/build

crypto/CMakeFiles/demo_loadingECDSAKeys.dir/clean:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && $(CMAKE_COMMAND) -P CMakeFiles/demo_loadingECDSAKeys.dir/cmake_clean.cmake
.PHONY : crypto/CMakeFiles/demo_loadingECDSAKeys.dir/clean

crypto/CMakeFiles/demo_loadingECDSAKeys.dir/depend:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/crypto /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto/CMakeFiles/demo_loadingECDSAKeys.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crypto/CMakeFiles/demo_loadingECDSAKeys.dir/depend

