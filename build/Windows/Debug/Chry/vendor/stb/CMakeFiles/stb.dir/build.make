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
CMAKE_SOURCE_DIR = /home/chry/Dev/c++/Chry

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chry/Dev/c++/Chry/build/Windows/Debug

# Include any dependencies generated for this target.
include Chry/vendor/stb/CMakeFiles/stb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Chry/vendor/stb/CMakeFiles/stb.dir/compiler_depend.make

# Include the progress variables for this target.
include Chry/vendor/stb/CMakeFiles/stb.dir/progress.make

# Include the compile flags for this target's objects.
include Chry/vendor/stb/CMakeFiles/stb.dir/flags.make

Chry/vendor/stb/CMakeFiles/stb.dir/stb_image.cpp.obj: Chry/vendor/stb/CMakeFiles/stb.dir/flags.make
Chry/vendor/stb/CMakeFiles/stb.dir/stb_image.cpp.obj: Chry/vendor/stb/CMakeFiles/stb.dir/includes_CXX.rsp
Chry/vendor/stb/CMakeFiles/stb.dir/stb_image.cpp.obj: ../../../Chry/vendor/stb/stb_image.cpp
Chry/vendor/stb/CMakeFiles/stb.dir/stb_image.cpp.obj: Chry/vendor/stb/CMakeFiles/stb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chry/Dev/c++/Chry/build/Windows/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Chry/vendor/stb/CMakeFiles/stb.dir/stb_image.cpp.obj"
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/stb && /usr/bin/x86_64-w64-mingw32-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Chry/vendor/stb/CMakeFiles/stb.dir/stb_image.cpp.obj -MF CMakeFiles/stb.dir/stb_image.cpp.obj.d -o CMakeFiles/stb.dir/stb_image.cpp.obj -c /home/chry/Dev/c++/Chry/Chry/vendor/stb/stb_image.cpp

Chry/vendor/stb/CMakeFiles/stb.dir/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stb.dir/stb_image.cpp.i"
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/stb && /usr/bin/x86_64-w64-mingw32-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chry/Dev/c++/Chry/Chry/vendor/stb/stb_image.cpp > CMakeFiles/stb.dir/stb_image.cpp.i

Chry/vendor/stb/CMakeFiles/stb.dir/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stb.dir/stb_image.cpp.s"
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/stb && /usr/bin/x86_64-w64-mingw32-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chry/Dev/c++/Chry/Chry/vendor/stb/stb_image.cpp -o CMakeFiles/stb.dir/stb_image.cpp.s

# Object files for target stb
stb_OBJECTS = \
"CMakeFiles/stb.dir/stb_image.cpp.obj"

# External object files for target stb
stb_EXTERNAL_OBJECTS =

Chry/vendor/stb/libstb.dll: Chry/vendor/stb/CMakeFiles/stb.dir/stb_image.cpp.obj
Chry/vendor/stb/libstb.dll: Chry/vendor/stb/CMakeFiles/stb.dir/build.make
Chry/vendor/stb/libstb.dll: Chry/vendor/stb/CMakeFiles/stb.dir/linklibs.rsp
Chry/vendor/stb/libstb.dll: Chry/vendor/stb/CMakeFiles/stb.dir/objects1.rsp
Chry/vendor/stb/libstb.dll: Chry/vendor/stb/CMakeFiles/stb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chry/Dev/c++/Chry/build/Windows/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libstb.dll"
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/stb && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Chry/vendor/stb/CMakeFiles/stb.dir/build: Chry/vendor/stb/libstb.dll
.PHONY : Chry/vendor/stb/CMakeFiles/stb.dir/build

Chry/vendor/stb/CMakeFiles/stb.dir/clean:
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/stb && $(CMAKE_COMMAND) -P CMakeFiles/stb.dir/cmake_clean.cmake
.PHONY : Chry/vendor/stb/CMakeFiles/stb.dir/clean

Chry/vendor/stb/CMakeFiles/stb.dir/depend:
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chry/Dev/c++/Chry /home/chry/Dev/c++/Chry/Chry/vendor/stb /home/chry/Dev/c++/Chry/build/Windows/Debug /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/stb /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/stb/CMakeFiles/stb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Chry/vendor/stb/CMakeFiles/stb.dir/depend

