# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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


# Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = /home/stratis/Documents/dev/c++/Euler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stratis/Documents/dev/c++/Euler/build

# Include any dependencies generated for this target.
include problem20/CMakeFiles/problem20.dir/depend.make

# Include the progress variables for this target.
include problem20/CMakeFiles/problem20.dir/progress.make

# Include the compile flags for this target's objects.
include problem20/CMakeFiles/problem20.dir/flags.make

problem20/CMakeFiles/problem20.dir/main.cpp.o: problem20/CMakeFiles/problem20.dir/flags.make
problem20/CMakeFiles/problem20.dir/main.cpp.o: ../problem20/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stratis/Documents/dev/c++/Euler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object problem20/CMakeFiles/problem20.dir/main.cpp.o"
	cd /home/stratis/Documents/dev/c++/Euler/build/problem20 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/problem20.dir/main.cpp.o -c /home/stratis/Documents/dev/c++/Euler/problem20/main.cpp

problem20/CMakeFiles/problem20.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem20.dir/main.cpp.i"
	cd /home/stratis/Documents/dev/c++/Euler/build/problem20 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stratis/Documents/dev/c++/Euler/problem20/main.cpp > CMakeFiles/problem20.dir/main.cpp.i

problem20/CMakeFiles/problem20.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem20.dir/main.cpp.s"
	cd /home/stratis/Documents/dev/c++/Euler/build/problem20 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stratis/Documents/dev/c++/Euler/problem20/main.cpp -o CMakeFiles/problem20.dir/main.cpp.s

# Object files for target problem20
problem20_OBJECTS = \
"CMakeFiles/problem20.dir/main.cpp.o"

# External object files for target problem20
problem20_EXTERNAL_OBJECTS =

problem20/problem20: problem20/CMakeFiles/problem20.dir/main.cpp.o
problem20/problem20: problem20/CMakeFiles/problem20.dir/build.make
problem20/problem20: problem20/CMakeFiles/problem20.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stratis/Documents/dev/c++/Euler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable problem20"
	cd /home/stratis/Documents/dev/c++/Euler/build/problem20 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/problem20.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
problem20/CMakeFiles/problem20.dir/build: problem20/problem20

.PHONY : problem20/CMakeFiles/problem20.dir/build

problem20/CMakeFiles/problem20.dir/clean:
	cd /home/stratis/Documents/dev/c++/Euler/build/problem20 && $(CMAKE_COMMAND) -P CMakeFiles/problem20.dir/cmake_clean.cmake
.PHONY : problem20/CMakeFiles/problem20.dir/clean

problem20/CMakeFiles/problem20.dir/depend:
	cd /home/stratis/Documents/dev/c++/Euler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stratis/Documents/dev/c++/Euler /home/stratis/Documents/dev/c++/Euler/problem20 /home/stratis/Documents/dev/c++/Euler/build /home/stratis/Documents/dev/c++/Euler/build/problem20 /home/stratis/Documents/dev/c++/Euler/build/problem20/CMakeFiles/problem20.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : problem20/CMakeFiles/problem20.dir/depend

