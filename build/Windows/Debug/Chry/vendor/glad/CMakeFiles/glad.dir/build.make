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
include Chry/vendor/glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Chry/vendor/glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include Chry/vendor/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include Chry/vendor/glad/CMakeFiles/glad.dir/flags.make

Chry/vendor/glad/CMakeFiles/glad.dir/glad/src/glad.c.obj: Chry/vendor/glad/CMakeFiles/glad.dir/flags.make
Chry/vendor/glad/CMakeFiles/glad.dir/glad/src/glad.c.obj: Chry/vendor/glad/CMakeFiles/glad.dir/includes_C.rsp
Chry/vendor/glad/CMakeFiles/glad.dir/glad/src/glad.c.obj: ../../../Chry/vendor/glad/glad/src/glad.c
Chry/vendor/glad/CMakeFiles/glad.dir/glad/src/glad.c.obj: Chry/vendor/glad/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chry/Dev/c++/Chry/build/Windows/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Chry/vendor/glad/CMakeFiles/glad.dir/glad/src/glad.c.obj"
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/glad && /usr/bin/x86_64-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Chry/vendor/glad/CMakeFiles/glad.dir/glad/src/glad.c.obj -MF CMakeFiles/glad.dir/glad/src/glad.c.obj.d -o CMakeFiles/glad.dir/glad/src/glad.c.obj -c /home/chry/Dev/c++/Chry/Chry/vendor/glad/glad/src/glad.c

Chry/vendor/glad/CMakeFiles/glad.dir/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/glad/src/glad.c.i"
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/glad && /usr/bin/x86_64-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chry/Dev/c++/Chry/Chry/vendor/glad/glad/src/glad.c > CMakeFiles/glad.dir/glad/src/glad.c.i

Chry/vendor/glad/CMakeFiles/glad.dir/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/glad/src/glad.c.s"
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/glad && /usr/bin/x86_64-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chry/Dev/c++/Chry/Chry/vendor/glad/glad/src/glad.c -o CMakeFiles/glad.dir/glad/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/glad/src/glad.c.obj"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

Chry/vendor/glad/libglad.dll: Chry/vendor/glad/CMakeFiles/glad.dir/glad/src/glad.c.obj
Chry/vendor/glad/libglad.dll: Chry/vendor/glad/CMakeFiles/glad.dir/build.make
Chry/vendor/glad/libglad.dll: Chry/vendor/glad/CMakeFiles/glad.dir/linklibs.rsp
Chry/vendor/glad/libglad.dll: Chry/vendor/glad/CMakeFiles/glad.dir/objects1.rsp
Chry/vendor/glad/libglad.dll: Chry/vendor/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chry/Dev/c++/Chry/build/Windows/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libglad.dll"
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Chry/vendor/glad/CMakeFiles/glad.dir/build: Chry/vendor/glad/libglad.dll
.PHONY : Chry/vendor/glad/CMakeFiles/glad.dir/build

Chry/vendor/glad/CMakeFiles/glad.dir/clean:
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : Chry/vendor/glad/CMakeFiles/glad.dir/clean

Chry/vendor/glad/CMakeFiles/glad.dir/depend:
	cd /home/chry/Dev/c++/Chry/build/Windows/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chry/Dev/c++/Chry /home/chry/Dev/c++/Chry/Chry/vendor/glad /home/chry/Dev/c++/Chry/build/Windows/Debug /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/glad /home/chry/Dev/c++/Chry/build/Windows/Debug/Chry/vendor/glad/CMakeFiles/glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Chry/vendor/glad/CMakeFiles/glad.dir/depend
