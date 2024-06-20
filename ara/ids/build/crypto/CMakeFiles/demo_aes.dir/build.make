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
include crypto/CMakeFiles/demo_aes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include crypto/CMakeFiles/demo_aes.dir/compiler_depend.make

# Include the progress variables for this target.
include crypto/CMakeFiles/demo_aes.dir/progress.make

# Include the compile flags for this target's objects.
include crypto/CMakeFiles/demo_aes.dir/flags.make

crypto/CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.o: crypto/CMakeFiles/demo_aes.dir/flags.make
crypto/CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.o: /home/ahmed/coding/myAdatpivePlatform/crypto/samples/Demos/demo_aes.cpp
crypto/CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.o: crypto/CMakeFiles/demo_aes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object crypto/CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.o"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT crypto/CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.o -MF CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.o.d -o CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.o -c /home/ahmed/coding/myAdatpivePlatform/crypto/samples/Demos/demo_aes.cpp

crypto/CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.i"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/myAdatpivePlatform/crypto/samples/Demos/demo_aes.cpp > CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.i

crypto/CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.s"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/myAdatpivePlatform/crypto/samples/Demos/demo_aes.cpp -o CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.s

# Object files for target demo_aes
demo_aes_OBJECTS = \
"CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.o"

# External object files for target demo_aes
demo_aes_EXTERNAL_OBJECTS =

crypto/demo_aes: crypto/CMakeFiles/demo_aes.dir/samples/Demos/demo_aes.cpp.o
crypto/demo_aes: crypto/CMakeFiles/demo_aes.dir/build.make
crypto/demo_aes: core/libCore.a
crypto/demo_aes: crypto/libCrypto.a
crypto/demo_aes: /usr/lib/x86_64-linux-gnu/libcryptopp.so
crypto/demo_aes: crypto/CMakeFiles/demo_aes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/myAdatpivePlatform/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable demo_aes"
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo_aes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crypto/CMakeFiles/demo_aes.dir/build: crypto/demo_aes
.PHONY : crypto/CMakeFiles/demo_aes.dir/build

crypto/CMakeFiles/demo_aes.dir/clean:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto && $(CMAKE_COMMAND) -P CMakeFiles/demo_aes.dir/cmake_clean.cmake
.PHONY : crypto/CMakeFiles/demo_aes.dir/clean

crypto/CMakeFiles/demo_aes.dir/depend:
	cd /home/ahmed/coding/myAdatpivePlatform/ids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/myAdatpivePlatform/ids /home/ahmed/coding/myAdatpivePlatform/crypto /home/ahmed/coding/myAdatpivePlatform/ids/build /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto /home/ahmed/coding/myAdatpivePlatform/ids/build/crypto/CMakeFiles/demo_aes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crypto/CMakeFiles/demo_aes.dir/depend

