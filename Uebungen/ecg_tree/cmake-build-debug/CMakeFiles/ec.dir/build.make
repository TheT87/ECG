# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
include CMakeFiles/ec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ec.dir/flags.make

CMakeFiles/ec.dir/main.cpp.obj: CMakeFiles/ec.dir/flags.make
CMakeFiles/ec.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ec.dir/main.cpp.obj"
	C:\IDEs\mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ec.dir\main.cpp.obj -c D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\main.cpp

CMakeFiles/ec.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ec.dir/main.cpp.i"
	C:\IDEs\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\main.cpp > CMakeFiles\ec.dir\main.cpp.i

CMakeFiles/ec.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ec.dir/main.cpp.s"
	C:\IDEs\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\main.cpp -o CMakeFiles\ec.dir\main.cpp.s

# Object files for target ec
ec_OBJECTS = \
"CMakeFiles/ec.dir/main.cpp.obj"

# External object files for target ec
ec_EXTERNAL_OBJECTS =

ec.exe: CMakeFiles/ec.dir/main.cpp.obj
ec.exe: CMakeFiles/ec.dir/build.make
ec.exe: CMakeFiles/ec.dir/linklibs.rsp
ec.exe: CMakeFiles/ec.dir/objects1.rsp
ec.exe: CMakeFiles/ec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ec.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ec.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ec.dir/build: ec.exe

.PHONY : CMakeFiles/ec.dir/build

CMakeFiles/ec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ec.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ec.dir/clean

CMakeFiles/ec.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug D:\Zeug\Uni\S2\ECG\Uebungen\ecg_tree\cmake-build-debug\CMakeFiles\ec.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ec.dir/depend

