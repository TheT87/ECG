# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\IDEs\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\IDEs\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ecg_tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ecg_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ecg_tree.dir/flags.make

CMakeFiles/ecg_tree.dir/src/main.cpp.obj: CMakeFiles/ecg_tree.dir/flags.make
CMakeFiles/ecg_tree.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ecg_tree.dir/src/main.cpp.obj"
	C:\IDEs\mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ecg_tree.dir\src\main.cpp.obj -c D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\src\main.cpp

CMakeFiles/ecg_tree.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ecg_tree.dir/src/main.cpp.i"
	C:\IDEs\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\src\main.cpp > CMakeFiles\ecg_tree.dir\src\main.cpp.i

CMakeFiles/ecg_tree.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ecg_tree.dir/src/main.cpp.s"
	C:\IDEs\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\src\main.cpp -o CMakeFiles\ecg_tree.dir\src\main.cpp.s

# Object files for target ecg_tree
ecg_tree_OBJECTS = \
"CMakeFiles/ecg_tree.dir/src/main.cpp.obj"

# External object files for target ecg_tree
ecg_tree_EXTERNAL_OBJECTS =

ecg_tree.exe: CMakeFiles/ecg_tree.dir/src/main.cpp.obj
ecg_tree.exe: CMakeFiles/ecg_tree.dir/build.make
ecg_tree.exe: CMakeFiles/ecg_tree.dir/linklibs.rsp
ecg_tree.exe: CMakeFiles/ecg_tree.dir/objects1.rsp
ecg_tree.exe: CMakeFiles/ecg_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ecg_tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ecg_tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ecg_tree.dir/build: ecg_tree.exe

.PHONY : CMakeFiles/ecg_tree.dir/build

CMakeFiles/ecg_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ecg_tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ecg_tree.dir/clean

CMakeFiles/ecg_tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug\CMakeFiles\ecg_tree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ecg_tree.dir/depend

