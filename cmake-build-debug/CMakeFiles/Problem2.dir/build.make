# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Problem2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Problem2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Problem2.dir/flags.make

CMakeFiles/Problem2.dir/p2.c.obj: CMakeFiles/Problem2.dir/flags.make
CMakeFiles/Problem2.dir/p2.c.obj: ../p2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Problem2.dir/p2.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Problem2.dir\p2.c.obj   -c "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2\p2.c"

CMakeFiles/Problem2.dir/p2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Problem2.dir/p2.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2\p2.c" > CMakeFiles\Problem2.dir\p2.c.i

CMakeFiles/Problem2.dir/p2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Problem2.dir/p2.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2\p2.c" -o CMakeFiles\Problem2.dir\p2.c.s

# Object files for target Problem2
Problem2_OBJECTS = \
"CMakeFiles/Problem2.dir/p2.c.obj"

# External object files for target Problem2
Problem2_EXTERNAL_OBJECTS =

Problem2.exe: CMakeFiles/Problem2.dir/p2.c.obj
Problem2.exe: CMakeFiles/Problem2.dir/build.make
Problem2.exe: CMakeFiles/Problem2.dir/linklibs.rsp
Problem2.exe: CMakeFiles/Problem2.dir/objects1.rsp
Problem2.exe: CMakeFiles/Problem2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Problem2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Problem2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Problem2.dir/build: Problem2.exe

.PHONY : CMakeFiles/Problem2.dir/build

CMakeFiles/Problem2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Problem2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Problem2.dir/clean

CMakeFiles/Problem2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2" "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2" "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2\cmake-build-debug" "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2\cmake-build-debug" "C:\Users\Connor Giles\Dropbox\COP3275\PA3\Problem2\cmake-build-debug\CMakeFiles\Problem2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Problem2.dir/depend

