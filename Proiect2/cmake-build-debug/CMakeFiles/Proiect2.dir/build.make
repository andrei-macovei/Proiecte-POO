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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\andre\Desktop\Anul 2\POO\Proiect2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\andre\Desktop\Anul 2\POO\Proiect2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Proiect2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Proiect2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proiect2.dir/flags.make

CMakeFiles/Proiect2.dir/main.cpp.obj: CMakeFiles/Proiect2.dir/flags.make
CMakeFiles/Proiect2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\andre\Desktop\Anul 2\POO\Proiect2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Proiect2.dir/main.cpp.obj"
	C:\OJI\Codeblocks\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Proiect2.dir\main.cpp.obj -c "C:\Users\andre\Desktop\Anul 2\POO\Proiect2\main.cpp"

CMakeFiles/Proiect2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proiect2.dir/main.cpp.i"
	C:\OJI\Codeblocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\andre\Desktop\Anul 2\POO\Proiect2\main.cpp" > CMakeFiles\Proiect2.dir\main.cpp.i

CMakeFiles/Proiect2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proiect2.dir/main.cpp.s"
	C:\OJI\Codeblocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\andre\Desktop\Anul 2\POO\Proiect2\main.cpp" -o CMakeFiles\Proiect2.dir\main.cpp.s

# Object files for target Proiect2
Proiect2_OBJECTS = \
"CMakeFiles/Proiect2.dir/main.cpp.obj"

# External object files for target Proiect2
Proiect2_EXTERNAL_OBJECTS =

Proiect2.exe: CMakeFiles/Proiect2.dir/main.cpp.obj
Proiect2.exe: CMakeFiles/Proiect2.dir/build.make
Proiect2.exe: CMakeFiles/Proiect2.dir/linklibs.rsp
Proiect2.exe: CMakeFiles/Proiect2.dir/objects1.rsp
Proiect2.exe: CMakeFiles/Proiect2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\andre\Desktop\Anul 2\POO\Proiect2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Proiect2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Proiect2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proiect2.dir/build: Proiect2.exe

.PHONY : CMakeFiles/Proiect2.dir/build

CMakeFiles/Proiect2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Proiect2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Proiect2.dir/clean

CMakeFiles/Proiect2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\andre\Desktop\Anul 2\POO\Proiect2" "C:\Users\andre\Desktop\Anul 2\POO\Proiect2" "C:\Users\andre\Desktop\Anul 2\POO\Proiect2\cmake-build-debug" "C:\Users\andre\Desktop\Anul 2\POO\Proiect2\cmake-build-debug" "C:\Users\andre\Desktop\Anul 2\POO\Proiect2\cmake-build-debug\CMakeFiles\Proiect2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Proiect2.dir/depend
