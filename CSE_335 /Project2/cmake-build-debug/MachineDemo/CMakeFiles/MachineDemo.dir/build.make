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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/varunreddy/Desktop/Project2Starter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug

# Include any dependencies generated for this target.
include MachineDemo/CMakeFiles/MachineDemo.dir/depend.make
# Include the progress variables for this target.
include MachineDemo/CMakeFiles/MachineDemo.dir/progress.make

# Include the compile flags for this target's objects.
include MachineDemo/CMakeFiles/MachineDemo.dir/flags.make

MachineDemo/MachineDemo.app/Contents/Resources/MachineDemoIcon.icns: MachineDemo/MachineDemoIcon.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content MachineDemo/MachineDemo.app/Contents/Resources/MachineDemoIcon.icns"
	$(CMAKE_COMMAND) -E copy /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/MachineDemoIcon.icns MachineDemo/MachineDemo.app/Contents/Resources/MachineDemoIcon.icns

MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch: MachineDemo/CMakeFiles/MachineDemo.dir/flags.make
MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch: MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.cxx
MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch: MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch"
	cd /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -emit-pch -Xclang -include -Xclang /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx -x c++-header -o CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch -c /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.cxx

MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MachineDemo.dir/cmake_pch.hxx.i"
	cd /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -emit-pch -Xclang -include -Xclang /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx -x c++-header -E /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.cxx > CMakeFiles/MachineDemo.dir/cmake_pch.hxx.i

MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MachineDemo.dir/cmake_pch.hxx.s"
	cd /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -emit-pch -Xclang -include -Xclang /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx -x c++-header -S /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.cxx -o CMakeFiles/MachineDemo.dir/cmake_pch.hxx.s

MachineDemo/CMakeFiles/MachineDemo.dir/main.cpp.o: MachineDemo/CMakeFiles/MachineDemo.dir/flags.make
MachineDemo/CMakeFiles/MachineDemo.dir/main.cpp.o: ../MachineDemo/main.cpp
MachineDemo/CMakeFiles/MachineDemo.dir/main.cpp.o: MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx
MachineDemo/CMakeFiles/MachineDemo.dir/main.cpp.o: MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object MachineDemo/CMakeFiles/MachineDemo.dir/main.cpp.o"
	cd /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx -o CMakeFiles/MachineDemo.dir/main.cpp.o -c /Users/varunreddy/Desktop/Project2Starter/MachineDemo/main.cpp

MachineDemo/CMakeFiles/MachineDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MachineDemo.dir/main.cpp.i"
	cd /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx -E /Users/varunreddy/Desktop/Project2Starter/MachineDemo/main.cpp > CMakeFiles/MachineDemo.dir/main.cpp.i

MachineDemo/CMakeFiles/MachineDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MachineDemo.dir/main.cpp.s"
	cd /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx -S /Users/varunreddy/Desktop/Project2Starter/MachineDemo/main.cpp -o CMakeFiles/MachineDemo.dir/main.cpp.s

# Object files for target MachineDemo
MachineDemo_OBJECTS = \
"CMakeFiles/MachineDemo.dir/main.cpp.o"

# External object files for target MachineDemo
MachineDemo_EXTERNAL_OBJECTS =

MachineDemo/MachineDemo.app/Contents/MacOS/MachineDemo: MachineDemo/CMakeFiles/MachineDemo.dir/cmake_pch.hxx.pch
MachineDemo/MachineDemo.app/Contents/MacOS/MachineDemo: MachineDemo/CMakeFiles/MachineDemo.dir/main.cpp.o
MachineDemo/MachineDemo.app/Contents/MacOS/MachineDemo: MachineDemo/CMakeFiles/MachineDemo.dir/build.make
MachineDemo/MachineDemo.app/Contents/MacOS/MachineDemo: MachineLib/libMachineLib.a
MachineDemo/MachineDemo.app/Contents/MacOS/MachineDemo: _deps/machinedemolib-build/libMachineDemoLib.a
MachineDemo/MachineDemo.app/Contents/MacOS/MachineDemo: MachineDemo/CMakeFiles/MachineDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MachineDemo.app/Contents/MacOS/MachineDemo"
	cd /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MachineDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MachineDemo/CMakeFiles/MachineDemo.dir/build: MachineDemo/MachineDemo.app/Contents/MacOS/MachineDemo
MachineDemo/CMakeFiles/MachineDemo.dir/build: MachineDemo/MachineDemo.app/Contents/Resources/MachineDemoIcon.icns
.PHONY : MachineDemo/CMakeFiles/MachineDemo.dir/build

MachineDemo/CMakeFiles/MachineDemo.dir/clean:
	cd /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo && $(CMAKE_COMMAND) -P CMakeFiles/MachineDemo.dir/cmake_clean.cmake
.PHONY : MachineDemo/CMakeFiles/MachineDemo.dir/clean

MachineDemo/CMakeFiles/MachineDemo.dir/depend:
	cd /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/varunreddy/Desktop/Project2Starter /Users/varunreddy/Desktop/Project2Starter/MachineDemo /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo /Users/varunreddy/Desktop/Project2Starter/cmake-build-debug/MachineDemo/CMakeFiles/MachineDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : MachineDemo/CMakeFiles/MachineDemo.dir/depend
