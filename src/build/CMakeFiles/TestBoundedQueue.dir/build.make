# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/toyota/workspace/QueueTest/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/toyota/workspace/QueueTest/src/build

# Include any dependencies generated for this target.
include CMakeFiles/TestBoundedQueue.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestBoundedQueue.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestBoundedQueue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestBoundedQueue.dir/flags.make

CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.o: CMakeFiles/TestBoundedQueue.dir/flags.make
CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.o: ../test_bounded_queue.cpp
CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.o: CMakeFiles/TestBoundedQueue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/toyota/workspace/QueueTest/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.o -MF CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.o.d -o CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.o -c /home/toyota/workspace/QueueTest/src/test_bounded_queue.cpp

CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/toyota/workspace/QueueTest/src/test_bounded_queue.cpp > CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.i

CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/toyota/workspace/QueueTest/src/test_bounded_queue.cpp -o CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.s

# Object files for target TestBoundedQueue
TestBoundedQueue_OBJECTS = \
"CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.o"

# External object files for target TestBoundedQueue
TestBoundedQueue_EXTERNAL_OBJECTS =

TestBoundedQueue: CMakeFiles/TestBoundedQueue.dir/test_bounded_queue.cpp.o
TestBoundedQueue: CMakeFiles/TestBoundedQueue.dir/build.make
TestBoundedQueue: /usr/local/lib/libgtest.a
TestBoundedQueue: CMakeFiles/TestBoundedQueue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/toyota/workspace/QueueTest/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestBoundedQueue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestBoundedQueue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestBoundedQueue.dir/build: TestBoundedQueue
.PHONY : CMakeFiles/TestBoundedQueue.dir/build

CMakeFiles/TestBoundedQueue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestBoundedQueue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestBoundedQueue.dir/clean

CMakeFiles/TestBoundedQueue.dir/depend:
	cd /home/toyota/workspace/QueueTest/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/toyota/workspace/QueueTest/src /home/toyota/workspace/QueueTest/src /home/toyota/workspace/QueueTest/src/build /home/toyota/workspace/QueueTest/src/build /home/toyota/workspace/QueueTest/src/build/CMakeFiles/TestBoundedQueue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestBoundedQueue.dir/depend

