# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/build

# Include any dependencies generated for this target.
include CMakeFiles/PhysicsExercises.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PhysicsExercises.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PhysicsExercises.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PhysicsExercises.dir/flags.make

CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.o: CMakeFiles/PhysicsExercises.dir/flags.make
CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.o: ../PhysicsExercises.cpp
CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.o: CMakeFiles/PhysicsExercises.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.o -MF CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.o.d -o CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.o -c /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/PhysicsExercises.cpp

CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/PhysicsExercises.cpp > CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.i

CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/PhysicsExercises.cpp -o CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.s

CMakeFiles/PhysicsExercises.dir/CVector.cpp.o: CMakeFiles/PhysicsExercises.dir/flags.make
CMakeFiles/PhysicsExercises.dir/CVector.cpp.o: ../CVector.cpp
CMakeFiles/PhysicsExercises.dir/CVector.cpp.o: CMakeFiles/PhysicsExercises.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PhysicsExercises.dir/CVector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PhysicsExercises.dir/CVector.cpp.o -MF CMakeFiles/PhysicsExercises.dir/CVector.cpp.o.d -o CMakeFiles/PhysicsExercises.dir/CVector.cpp.o -c /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/CVector.cpp

CMakeFiles/PhysicsExercises.dir/CVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PhysicsExercises.dir/CVector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/CVector.cpp > CMakeFiles/PhysicsExercises.dir/CVector.cpp.i

CMakeFiles/PhysicsExercises.dir/CVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PhysicsExercises.dir/CVector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/CVector.cpp -o CMakeFiles/PhysicsExercises.dir/CVector.cpp.s

# Object files for target PhysicsExercises
PhysicsExercises_OBJECTS = \
"CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.o" \
"CMakeFiles/PhysicsExercises.dir/CVector.cpp.o"

# External object files for target PhysicsExercises
PhysicsExercises_EXTERNAL_OBJECTS =

PhysicsExercises: CMakeFiles/PhysicsExercises.dir/PhysicsExercises.cpp.o
PhysicsExercises: CMakeFiles/PhysicsExercises.dir/CVector.cpp.o
PhysicsExercises: CMakeFiles/PhysicsExercises.dir/build.make
PhysicsExercises: CMakeFiles/PhysicsExercises.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PhysicsExercises"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PhysicsExercises.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PhysicsExercises.dir/build: PhysicsExercises
.PHONY : CMakeFiles/PhysicsExercises.dir/build

CMakeFiles/PhysicsExercises.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PhysicsExercises.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PhysicsExercises.dir/clean

CMakeFiles/PhysicsExercises.dir/depend:
	cd /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/build /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/build /home/neryst/Documents/Repos/PhysicsExercises/PhysicsExercises/build/CMakeFiles/PhysicsExercises.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PhysicsExercises.dir/depend
