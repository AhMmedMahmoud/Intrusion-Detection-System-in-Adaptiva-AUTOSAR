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
include CMakeFiles/ids.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ids.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ids.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ids.dir/flags.make

CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.o: ../ids_protocol/ids_message.cpp
CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.o -MF CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.o.d -o CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.o -c /home/ahmed/coding/ids/ids_protocol/ids_message.cpp

CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/ids_protocol/ids_message.cpp > CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.i

CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/ids_protocol/ids_message.cpp -o CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.s

CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.o: ../ids_protocol/event_frame/event_frame.cpp
CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.o -MF CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.o.d -o CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.o -c /home/ahmed/coding/ids/ids_protocol/event_frame/event_frame.cpp

CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/ids_protocol/event_frame/event_frame.cpp > CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.i

CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/ids_protocol/event_frame/event_frame.cpp -o CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.s

CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.o: ../ids_protocol/event_frame/protocol_header.cpp
CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.o -MF CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.o.d -o CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.o -c /home/ahmed/coding/ids/ids_protocol/event_frame/protocol_header.cpp

CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/ids_protocol/event_frame/protocol_header.cpp > CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.i

CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/ids_protocol/event_frame/protocol_header.cpp -o CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.s

CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.o: ../ids_protocol/timestamp/timestamp.cpp
CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.o -MF CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.o.d -o CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.o -c /home/ahmed/coding/ids/ids_protocol/timestamp/timestamp.cpp

CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/ids_protocol/timestamp/timestamp.cpp > CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.i

CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/ids_protocol/timestamp/timestamp.cpp -o CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.s

CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.o: ../ids_protocol/context_data/context_data.cpp
CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.o -MF CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.o.d -o CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.o -c /home/ahmed/coding/ids/ids_protocol/context_data/context_data.cpp

CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/ids_protocol/context_data/context_data.cpp > CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.i

CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/ids_protocol/context_data/context_data.cpp -o CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.s

CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.o: ../ids_protocol/signature/signature.cpp
CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.o -MF CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.o.d -o CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.o -c /home/ahmed/coding/ids/ids_protocol/signature/signature.cpp

CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/ids_protocol/signature/signature.cpp > CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.i

CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/ids_protocol/signature/signature.cpp -o CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.s

CMakeFiles/ids.dir/event_reporter.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/event_reporter.cpp.o: ../event_reporter.cpp
CMakeFiles/ids.dir/event_reporter.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ids.dir/event_reporter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/event_reporter.cpp.o -MF CMakeFiles/ids.dir/event_reporter.cpp.o.d -o CMakeFiles/ids.dir/event_reporter.cpp.o -c /home/ahmed/coding/ids/event_reporter.cpp

CMakeFiles/ids.dir/event_reporter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/event_reporter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/event_reporter.cpp > CMakeFiles/ids.dir/event_reporter.cpp.i

CMakeFiles/ids.dir/event_reporter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/event_reporter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/event_reporter.cpp -o CMakeFiles/ids.dir/event_reporter.cpp.s

CMakeFiles/ids.dir/idsm/idsm.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/idsm/idsm.cpp.o: ../idsm/idsm.cpp
CMakeFiles/ids.dir/idsm/idsm.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ids.dir/idsm/idsm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/idsm/idsm.cpp.o -MF CMakeFiles/ids.dir/idsm/idsm.cpp.o.d -o CMakeFiles/ids.dir/idsm/idsm.cpp.o -c /home/ahmed/coding/ids/idsm/idsm.cpp

CMakeFiles/ids.dir/idsm/idsm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/idsm/idsm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/idsm/idsm.cpp > CMakeFiles/ids.dir/idsm/idsm.cpp.i

CMakeFiles/ids.dir/idsm/idsm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/idsm/idsm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/idsm/idsm.cpp -o CMakeFiles/ids.dir/idsm/idsm.cpp.s

CMakeFiles/ids.dir/idsr/idsr.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/idsr/idsr.cpp.o: ../idsr/idsr.cpp
CMakeFiles/ids.dir/idsr/idsr.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ids.dir/idsr/idsr.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/idsr/idsr.cpp.o -MF CMakeFiles/ids.dir/idsr/idsr.cpp.o.d -o CMakeFiles/ids.dir/idsr/idsr.cpp.o -c /home/ahmed/coding/ids/idsr/idsr.cpp

CMakeFiles/ids.dir/idsr/idsr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/idsr/idsr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/idsr/idsr.cpp > CMakeFiles/ids.dir/idsr/idsr.cpp.i

CMakeFiles/ids.dir/idsr/idsr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/idsr/idsr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/idsr/idsr.cpp -o CMakeFiles/ids.dir/idsr/idsr.cpp.s

CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.o: ../Manifest/manager/manifest_manager.cpp
CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.o -MF CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.o.d -o CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.o -c /home/ahmed/coding/ids/Manifest/manager/manifest_manager.cpp

CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/Manifest/manager/manifest_manager.cpp > CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.i

CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/Manifest/manager/manifest_manager.cpp -o CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.s

CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.o: ../Manifest/shared/shared_events.cpp
CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.o -MF CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.o.d -o CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.o -c /home/ahmed/coding/ids/Manifest/shared/shared_events.cpp

CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/Manifest/shared/shared_events.cpp > CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.i

CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/Manifest/shared/shared_events.cpp -o CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.s

CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.o: ../Manifest/shared/shared_filterchains.cpp
CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.o -MF CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.o.d -o CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.o -c /home/ahmed/coding/ids/Manifest/shared/shared_filterchains.cpp

CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/Manifest/shared/shared_filterchains.cpp > CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.i

CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/Manifest/shared/shared_filterchains.cpp -o CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.s

CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.o: ../Manifest/shared/shared_eventContextMappings.cpp
CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.o -MF CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.o.d -o CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.o -c /home/ahmed/coding/ids/Manifest/shared/shared_eventContextMappings.cpp

CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/Manifest/shared/shared_eventContextMappings.cpp > CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.i

CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/Manifest/shared/shared_eventContextMappings.cpp -o CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.s

CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.o: ../Manifest/shared/shared_stateFilters.cpp
CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.o -MF CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.o.d -o CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.o -c /home/ahmed/coding/ids/Manifest/shared/shared_stateFilters.cpp

CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/Manifest/shared/shared_stateFilters.cpp > CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.i

CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/Manifest/shared/shared_stateFilters.cpp -o CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.s

CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.o: ../Manifest/shared/shared_thresholdFilters.cpp
CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.o -MF CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.o.d -o CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.o -c /home/ahmed/coding/ids/Manifest/shared/shared_thresholdFilters.cpp

CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/Manifest/shared/shared_thresholdFilters.cpp > CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.i

CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/Manifest/shared/shared_thresholdFilters.cpp -o CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.s

CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.o: ../Manifest/shared/shared_aggregationFilters.cpp
CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.o -MF CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.o.d -o CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.o -c /home/ahmed/coding/ids/Manifest/shared/shared_aggregationFilters.cpp

CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/Manifest/shared/shared_aggregationFilters.cpp > CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.i

CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/Manifest/shared/shared_aggregationFilters.cpp -o CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.s

CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.o: CMakeFiles/ids.dir/flags.make
CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.o: ../Manifest/shared/shared_everyOneNFilters.cpp
CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.o: CMakeFiles/ids.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.o -MF CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.o.d -o CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.o -c /home/ahmed/coding/ids/Manifest/shared/shared_everyOneNFilters.cpp

CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ahmed/coding/ids/Manifest/shared/shared_everyOneNFilters.cpp > CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.i

CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ahmed/coding/ids/Manifest/shared/shared_everyOneNFilters.cpp -o CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.s

# Object files for target ids
ids_OBJECTS = \
"CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.o" \
"CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.o" \
"CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.o" \
"CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.o" \
"CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.o" \
"CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.o" \
"CMakeFiles/ids.dir/event_reporter.cpp.o" \
"CMakeFiles/ids.dir/idsm/idsm.cpp.o" \
"CMakeFiles/ids.dir/idsr/idsr.cpp.o" \
"CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.o" \
"CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.o" \
"CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.o" \
"CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.o" \
"CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.o" \
"CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.o" \
"CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.o" \
"CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.o"

# External object files for target ids
ids_EXTERNAL_OBJECTS =

libids.a: CMakeFiles/ids.dir/ids_protocol/ids_message.cpp.o
libids.a: CMakeFiles/ids.dir/ids_protocol/event_frame/event_frame.cpp.o
libids.a: CMakeFiles/ids.dir/ids_protocol/event_frame/protocol_header.cpp.o
libids.a: CMakeFiles/ids.dir/ids_protocol/timestamp/timestamp.cpp.o
libids.a: CMakeFiles/ids.dir/ids_protocol/context_data/context_data.cpp.o
libids.a: CMakeFiles/ids.dir/ids_protocol/signature/signature.cpp.o
libids.a: CMakeFiles/ids.dir/event_reporter.cpp.o
libids.a: CMakeFiles/ids.dir/idsm/idsm.cpp.o
libids.a: CMakeFiles/ids.dir/idsr/idsr.cpp.o
libids.a: CMakeFiles/ids.dir/Manifest/manager/manifest_manager.cpp.o
libids.a: CMakeFiles/ids.dir/Manifest/shared/shared_events.cpp.o
libids.a: CMakeFiles/ids.dir/Manifest/shared/shared_filterchains.cpp.o
libids.a: CMakeFiles/ids.dir/Manifest/shared/shared_eventContextMappings.cpp.o
libids.a: CMakeFiles/ids.dir/Manifest/shared/shared_stateFilters.cpp.o
libids.a: CMakeFiles/ids.dir/Manifest/shared/shared_thresholdFilters.cpp.o
libids.a: CMakeFiles/ids.dir/Manifest/shared/shared_aggregationFilters.cpp.o
libids.a: CMakeFiles/ids.dir/Manifest/shared/shared_everyOneNFilters.cpp.o
libids.a: CMakeFiles/ids.dir/build.make
libids.a: CMakeFiles/ids.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ahmed/coding/ids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX static library libids.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ids.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ids.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ids.dir/build: libids.a
.PHONY : CMakeFiles/ids.dir/build

CMakeFiles/ids.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ids.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ids.dir/clean

CMakeFiles/ids.dir/depend:
	cd /home/ahmed/coding/ids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/coding/ids /home/ahmed/coding/ids /home/ahmed/coding/ids/build /home/ahmed/coding/ids/build /home/ahmed/coding/ids/build/CMakeFiles/ids.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ids.dir/depend

