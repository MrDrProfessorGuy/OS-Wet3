# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Wet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Wet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wet.dir/flags.make

CMakeFiles/Wet.dir/segel.c.o: CMakeFiles/Wet.dir/flags.make
CMakeFiles/Wet.dir/segel.c.o: ../segel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Wet.dir/segel.c.o"
	/usr/local/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wet.dir/segel.c.o -c "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/segel.c"

CMakeFiles/Wet.dir/segel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wet.dir/segel.c.i"
	/usr/local/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/segel.c" > CMakeFiles/Wet.dir/segel.c.i

CMakeFiles/Wet.dir/segel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wet.dir/segel.c.s"
	/usr/local/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/segel.c" -o CMakeFiles/Wet.dir/segel.c.s

CMakeFiles/Wet.dir/request.c.o: CMakeFiles/Wet.dir/flags.make
CMakeFiles/Wet.dir/request.c.o: ../request.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Wet.dir/request.c.o"
	/usr/local/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wet.dir/request.c.o -c "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/request.c"

CMakeFiles/Wet.dir/request.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wet.dir/request.c.i"
	/usr/local/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/request.c" > CMakeFiles/Wet.dir/request.c.i

CMakeFiles/Wet.dir/request.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wet.dir/request.c.s"
	/usr/local/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/request.c" -o CMakeFiles/Wet.dir/request.c.s

CMakeFiles/Wet.dir/QueueManager.cpp.o: CMakeFiles/Wet.dir/flags.make
CMakeFiles/Wet.dir/QueueManager.cpp.o: ../QueueManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Wet.dir/QueueManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet.dir/QueueManager.cpp.o -c "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/QueueManager.cpp"

CMakeFiles/Wet.dir/QueueManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet.dir/QueueManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/QueueManager.cpp" > CMakeFiles/Wet.dir/QueueManager.cpp.i

CMakeFiles/Wet.dir/QueueManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet.dir/QueueManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/QueueManager.cpp" -o CMakeFiles/Wet.dir/QueueManager.cpp.s

CMakeFiles/Wet.dir/threadQueue.cpp.o: CMakeFiles/Wet.dir/flags.make
CMakeFiles/Wet.dir/threadQueue.cpp.o: ../threadQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Wet.dir/threadQueue.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet.dir/threadQueue.cpp.o -c "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/threadQueue.cpp"

CMakeFiles/Wet.dir/threadQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet.dir/threadQueue.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/threadQueue.cpp" > CMakeFiles/Wet.dir/threadQueue.cpp.i

CMakeFiles/Wet.dir/threadQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet.dir/threadQueue.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/threadQueue.cpp" -o CMakeFiles/Wet.dir/threadQueue.cpp.s

CMakeFiles/Wet.dir/JobQueue.cpp.o: CMakeFiles/Wet.dir/flags.make
CMakeFiles/Wet.dir/JobQueue.cpp.o: ../JobQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Wet.dir/JobQueue.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet.dir/JobQueue.cpp.o -c "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/JobQueue.cpp"

CMakeFiles/Wet.dir/JobQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet.dir/JobQueue.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/JobQueue.cpp" > CMakeFiles/Wet.dir/JobQueue.cpp.i

CMakeFiles/Wet.dir/JobQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet.dir/JobQueue.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/JobQueue.cpp" -o CMakeFiles/Wet.dir/JobQueue.cpp.s

CMakeFiles/Wet.dir/Worker.cpp.o: CMakeFiles/Wet.dir/flags.make
CMakeFiles/Wet.dir/Worker.cpp.o: ../Worker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Wet.dir/Worker.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet.dir/Worker.cpp.o -c "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/Worker.cpp"

CMakeFiles/Wet.dir/Worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet.dir/Worker.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/Worker.cpp" > CMakeFiles/Wet.dir/Worker.cpp.i

CMakeFiles/Wet.dir/Worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet.dir/Worker.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/Worker.cpp" -o CMakeFiles/Wet.dir/Worker.cpp.s

CMakeFiles/Wet.dir/shit.cpp.o: CMakeFiles/Wet.dir/flags.make
CMakeFiles/Wet.dir/shit.cpp.o: ../shit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Wet.dir/shit.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Wet.dir/shit.cpp.o -c "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/shit.cpp"

CMakeFiles/Wet.dir/shit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wet.dir/shit.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/shit.cpp" > CMakeFiles/Wet.dir/shit.cpp.i

CMakeFiles/Wet.dir/shit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wet.dir/shit.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/shit.cpp" -o CMakeFiles/Wet.dir/shit.cpp.s

# Object files for target Wet
Wet_OBJECTS = \
"CMakeFiles/Wet.dir/segel.c.o" \
"CMakeFiles/Wet.dir/request.c.o" \
"CMakeFiles/Wet.dir/QueueManager.cpp.o" \
"CMakeFiles/Wet.dir/threadQueue.cpp.o" \
"CMakeFiles/Wet.dir/JobQueue.cpp.o" \
"CMakeFiles/Wet.dir/Worker.cpp.o" \
"CMakeFiles/Wet.dir/shit.cpp.o"

# External object files for target Wet
Wet_EXTERNAL_OBJECTS =

Wet: CMakeFiles/Wet.dir/segel.c.o
Wet: CMakeFiles/Wet.dir/request.c.o
Wet: CMakeFiles/Wet.dir/QueueManager.cpp.o
Wet: CMakeFiles/Wet.dir/threadQueue.cpp.o
Wet: CMakeFiles/Wet.dir/JobQueue.cpp.o
Wet: CMakeFiles/Wet.dir/Worker.cpp.o
Wet: CMakeFiles/Wet.dir/shit.cpp.o
Wet: CMakeFiles/Wet.dir/build.make
Wet: CMakeFiles/Wet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Wet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wet.dir/build: Wet

.PHONY : CMakeFiles/Wet.dir/build

CMakeFiles/Wet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wet.dir/clean

CMakeFiles/Wet.dir/depend:
	cd "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet" "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet" "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug" "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug" "/Users/guycohen/Library/CloudStorage/OneDrive-Technion/1 Courses/Operating Systems/Homework/HW3/Wet/cmake-build-debug/CMakeFiles/Wet.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Wet.dir/depend

