# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\simon.simon\CLionProjects\wp3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\simon.simon\CLionProjects\wp3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/wp3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wp3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wp3.dir/flags.make

CMakeFiles/wp3.dir/exerc__3_1.c.obj: CMakeFiles/wp3.dir/flags.make
CMakeFiles/wp3.dir/exerc__3_1.c.obj: ../exerc\ _3_1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\simon.simon\CLionProjects\wp3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/wp3.dir/exerc__3_1.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\wp3.dir\exerc__3_1.c.obj   -c "C:\Users\simon.simon\CLionProjects\wp3\exerc _3_1.c"

CMakeFiles/wp3.dir/exerc__3_1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wp3.dir/exerc__3_1.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\simon.simon\CLionProjects\wp3\exerc _3_1.c" > CMakeFiles\wp3.dir\exerc__3_1.c.i

CMakeFiles/wp3.dir/exerc__3_1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wp3.dir/exerc__3_1.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\simon.simon\CLionProjects\wp3\exerc _3_1.c" -o CMakeFiles\wp3.dir\exerc__3_1.c.s

# Object files for target wp3
wp3_OBJECTS = \
"CMakeFiles/wp3.dir/exerc__3_1.c.obj"

# External object files for target wp3
wp3_EXTERNAL_OBJECTS =

wp3.exe: CMakeFiles/wp3.dir/exerc__3_1.c.obj
wp3.exe: CMakeFiles/wp3.dir/build.make
wp3.exe: CMakeFiles/wp3.dir/linklibs.rsp
wp3.exe: CMakeFiles/wp3.dir/objects1.rsp
wp3.exe: CMakeFiles/wp3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\simon.simon\CLionProjects\wp3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable wp3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\wp3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wp3.dir/build: wp3.exe

.PHONY : CMakeFiles/wp3.dir/build

CMakeFiles/wp3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\wp3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/wp3.dir/clean

CMakeFiles/wp3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\simon.simon\CLionProjects\wp3 C:\Users\simon.simon\CLionProjects\wp3 C:\Users\simon.simon\CLionProjects\wp3\cmake-build-debug C:\Users\simon.simon\CLionProjects\wp3\cmake-build-debug C:\Users\simon.simon\CLionProjects\wp3\cmake-build-debug\CMakeFiles\wp3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wp3.dir/depend

