# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build

# Include any dependencies generated for this target.
include CMakeFiles/practica1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/practica1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practica1.dir/flags.make

CMakeFiles/practica1.dir/src/greedy.cpp.o: CMakeFiles/practica1.dir/flags.make
CMakeFiles/practica1.dir/src/greedy.cpp.o: ../src/greedy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/practica1.dir/src/greedy.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica1.dir/src/greedy.cpp.o -c /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/greedy.cpp

CMakeFiles/practica1.dir/src/greedy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica1.dir/src/greedy.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/greedy.cpp > CMakeFiles/practica1.dir/src/greedy.cpp.i

CMakeFiles/practica1.dir/src/greedy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica1.dir/src/greedy.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/greedy.cpp -o CMakeFiles/practica1.dir/src/greedy.cpp.s

CMakeFiles/practica1.dir/src/greedy.cpp.o.requires:

.PHONY : CMakeFiles/practica1.dir/src/greedy.cpp.o.requires

CMakeFiles/practica1.dir/src/greedy.cpp.o.provides: CMakeFiles/practica1.dir/src/greedy.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica1.dir/build.make CMakeFiles/practica1.dir/src/greedy.cpp.o.provides.build
.PHONY : CMakeFiles/practica1.dir/src/greedy.cpp.o.provides

CMakeFiles/practica1.dir/src/greedy.cpp.o.provides.build: CMakeFiles/practica1.dir/src/greedy.cpp.o


CMakeFiles/practica1.dir/src/agg.cpp.o: CMakeFiles/practica1.dir/flags.make
CMakeFiles/practica1.dir/src/agg.cpp.o: ../src/agg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/practica1.dir/src/agg.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica1.dir/src/agg.cpp.o -c /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/agg.cpp

CMakeFiles/practica1.dir/src/agg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica1.dir/src/agg.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/agg.cpp > CMakeFiles/practica1.dir/src/agg.cpp.i

CMakeFiles/practica1.dir/src/agg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica1.dir/src/agg.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/agg.cpp -o CMakeFiles/practica1.dir/src/agg.cpp.s

CMakeFiles/practica1.dir/src/agg.cpp.o.requires:

.PHONY : CMakeFiles/practica1.dir/src/agg.cpp.o.requires

CMakeFiles/practica1.dir/src/agg.cpp.o.provides: CMakeFiles/practica1.dir/src/agg.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica1.dir/build.make CMakeFiles/practica1.dir/src/agg.cpp.o.provides.build
.PHONY : CMakeFiles/practica1.dir/src/agg.cpp.o.provides

CMakeFiles/practica1.dir/src/agg.cpp.o.provides.build: CMakeFiles/practica1.dir/src/agg.cpp.o


CMakeFiles/practica1.dir/src/practica1.cpp.o: CMakeFiles/practica1.dir/flags.make
CMakeFiles/practica1.dir/src/practica1.cpp.o: ../src/practica1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/practica1.dir/src/practica1.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica1.dir/src/practica1.cpp.o -c /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/practica1.cpp

CMakeFiles/practica1.dir/src/practica1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica1.dir/src/practica1.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/practica1.cpp > CMakeFiles/practica1.dir/src/practica1.cpp.i

CMakeFiles/practica1.dir/src/practica1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica1.dir/src/practica1.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/practica1.cpp -o CMakeFiles/practica1.dir/src/practica1.cpp.s

CMakeFiles/practica1.dir/src/practica1.cpp.o.requires:

.PHONY : CMakeFiles/practica1.dir/src/practica1.cpp.o.requires

CMakeFiles/practica1.dir/src/practica1.cpp.o.provides: CMakeFiles/practica1.dir/src/practica1.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica1.dir/build.make CMakeFiles/practica1.dir/src/practica1.cpp.o.provides.build
.PHONY : CMakeFiles/practica1.dir/src/practica1.cpp.o.provides

CMakeFiles/practica1.dir/src/practica1.cpp.o.provides.build: CMakeFiles/practica1.dir/src/practica1.cpp.o


CMakeFiles/practica1.dir/src/localSearch.cpp.o: CMakeFiles/practica1.dir/flags.make
CMakeFiles/practica1.dir/src/localSearch.cpp.o: ../src/localSearch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/practica1.dir/src/localSearch.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica1.dir/src/localSearch.cpp.o -c /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/localSearch.cpp

CMakeFiles/practica1.dir/src/localSearch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica1.dir/src/localSearch.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/localSearch.cpp > CMakeFiles/practica1.dir/src/localSearch.cpp.i

CMakeFiles/practica1.dir/src/localSearch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica1.dir/src/localSearch.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/localSearch.cpp -o CMakeFiles/practica1.dir/src/localSearch.cpp.s

CMakeFiles/practica1.dir/src/localSearch.cpp.o.requires:

.PHONY : CMakeFiles/practica1.dir/src/localSearch.cpp.o.requires

CMakeFiles/practica1.dir/src/localSearch.cpp.o.provides: CMakeFiles/practica1.dir/src/localSearch.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica1.dir/build.make CMakeFiles/practica1.dir/src/localSearch.cpp.o.provides.build
.PHONY : CMakeFiles/practica1.dir/src/localSearch.cpp.o.provides

CMakeFiles/practica1.dir/src/localSearch.cpp.o.provides.build: CMakeFiles/practica1.dir/src/localSearch.cpp.o


CMakeFiles/practica1.dir/src/age.cpp.o: CMakeFiles/practica1.dir/flags.make
CMakeFiles/practica1.dir/src/age.cpp.o: ../src/age.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/practica1.dir/src/age.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica1.dir/src/age.cpp.o -c /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/age.cpp

CMakeFiles/practica1.dir/src/age.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica1.dir/src/age.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/age.cpp > CMakeFiles/practica1.dir/src/age.cpp.i

CMakeFiles/practica1.dir/src/age.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica1.dir/src/age.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/age.cpp -o CMakeFiles/practica1.dir/src/age.cpp.s

CMakeFiles/practica1.dir/src/age.cpp.o.requires:

.PHONY : CMakeFiles/practica1.dir/src/age.cpp.o.requires

CMakeFiles/practica1.dir/src/age.cpp.o.provides: CMakeFiles/practica1.dir/src/age.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica1.dir/build.make CMakeFiles/practica1.dir/src/age.cpp.o.provides.build
.PHONY : CMakeFiles/practica1.dir/src/age.cpp.o.provides

CMakeFiles/practica1.dir/src/age.cpp.o.provides.build: CMakeFiles/practica1.dir/src/age.cpp.o


CMakeFiles/practica1.dir/src/genetico.cpp.o: CMakeFiles/practica1.dir/flags.make
CMakeFiles/practica1.dir/src/genetico.cpp.o: ../src/genetico.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/practica1.dir/src/genetico.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica1.dir/src/genetico.cpp.o -c /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/genetico.cpp

CMakeFiles/practica1.dir/src/genetico.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica1.dir/src/genetico.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/genetico.cpp > CMakeFiles/practica1.dir/src/genetico.cpp.i

CMakeFiles/practica1.dir/src/genetico.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica1.dir/src/genetico.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/genetico.cpp -o CMakeFiles/practica1.dir/src/genetico.cpp.s

CMakeFiles/practica1.dir/src/genetico.cpp.o.requires:

.PHONY : CMakeFiles/practica1.dir/src/genetico.cpp.o.requires

CMakeFiles/practica1.dir/src/genetico.cpp.o.provides: CMakeFiles/practica1.dir/src/genetico.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica1.dir/build.make CMakeFiles/practica1.dir/src/genetico.cpp.o.provides.build
.PHONY : CMakeFiles/practica1.dir/src/genetico.cpp.o.provides

CMakeFiles/practica1.dir/src/genetico.cpp.o.provides.build: CMakeFiles/practica1.dir/src/genetico.cpp.o


CMakeFiles/practica1.dir/src/solution.cpp.o: CMakeFiles/practica1.dir/flags.make
CMakeFiles/practica1.dir/src/solution.cpp.o: ../src/solution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/practica1.dir/src/solution.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica1.dir/src/solution.cpp.o -c /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/solution.cpp

CMakeFiles/practica1.dir/src/solution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica1.dir/src/solution.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/solution.cpp > CMakeFiles/practica1.dir/src/solution.cpp.i

CMakeFiles/practica1.dir/src/solution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica1.dir/src/solution.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/solution.cpp -o CMakeFiles/practica1.dir/src/solution.cpp.s

CMakeFiles/practica1.dir/src/solution.cpp.o.requires:

.PHONY : CMakeFiles/practica1.dir/src/solution.cpp.o.requires

CMakeFiles/practica1.dir/src/solution.cpp.o.provides: CMakeFiles/practica1.dir/src/solution.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica1.dir/build.make CMakeFiles/practica1.dir/src/solution.cpp.o.provides.build
.PHONY : CMakeFiles/practica1.dir/src/solution.cpp.o.provides

CMakeFiles/practica1.dir/src/solution.cpp.o.provides.build: CMakeFiles/practica1.dir/src/solution.cpp.o


CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o: CMakeFiles/practica1.dir/flags.make
CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o: ../src/localSearchDLB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o -c /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/localSearchDLB.cpp

CMakeFiles/practica1.dir/src/localSearchDLB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica1.dir/src/localSearchDLB.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/localSearchDLB.cpp > CMakeFiles/practica1.dir/src/localSearchDLB.cpp.i

CMakeFiles/practica1.dir/src/localSearchDLB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica1.dir/src/localSearchDLB.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/localSearchDLB.cpp -o CMakeFiles/practica1.dir/src/localSearchDLB.cpp.s

CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o.requires:

.PHONY : CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o.requires

CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o.provides: CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica1.dir/build.make CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o.provides.build
.PHONY : CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o.provides

CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o.provides.build: CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o


CMakeFiles/practica1.dir/src/solver.cpp.o: CMakeFiles/practica1.dir/flags.make
CMakeFiles/practica1.dir/src/solver.cpp.o: ../src/solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/practica1.dir/src/solver.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica1.dir/src/solver.cpp.o -c /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/solver.cpp

CMakeFiles/practica1.dir/src/solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica1.dir/src/solver.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/solver.cpp > CMakeFiles/practica1.dir/src/solver.cpp.i

CMakeFiles/practica1.dir/src/solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica1.dir/src/solver.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/src/solver.cpp -o CMakeFiles/practica1.dir/src/solver.cpp.s

CMakeFiles/practica1.dir/src/solver.cpp.o.requires:

.PHONY : CMakeFiles/practica1.dir/src/solver.cpp.o.requires

CMakeFiles/practica1.dir/src/solver.cpp.o.provides: CMakeFiles/practica1.dir/src/solver.cpp.o.requires
	$(MAKE) -f CMakeFiles/practica1.dir/build.make CMakeFiles/practica1.dir/src/solver.cpp.o.provides.build
.PHONY : CMakeFiles/practica1.dir/src/solver.cpp.o.provides

CMakeFiles/practica1.dir/src/solver.cpp.o.provides.build: CMakeFiles/practica1.dir/src/solver.cpp.o


# Object files for target practica1
practica1_OBJECTS = \
"CMakeFiles/practica1.dir/src/greedy.cpp.o" \
"CMakeFiles/practica1.dir/src/agg.cpp.o" \
"CMakeFiles/practica1.dir/src/practica1.cpp.o" \
"CMakeFiles/practica1.dir/src/localSearch.cpp.o" \
"CMakeFiles/practica1.dir/src/age.cpp.o" \
"CMakeFiles/practica1.dir/src/genetico.cpp.o" \
"CMakeFiles/practica1.dir/src/solution.cpp.o" \
"CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o" \
"CMakeFiles/practica1.dir/src/solver.cpp.o"

# External object files for target practica1
practica1_EXTERNAL_OBJECTS =

../bin/practica1: CMakeFiles/practica1.dir/src/greedy.cpp.o
../bin/practica1: CMakeFiles/practica1.dir/src/agg.cpp.o
../bin/practica1: CMakeFiles/practica1.dir/src/practica1.cpp.o
../bin/practica1: CMakeFiles/practica1.dir/src/localSearch.cpp.o
../bin/practica1: CMakeFiles/practica1.dir/src/age.cpp.o
../bin/practica1: CMakeFiles/practica1.dir/src/genetico.cpp.o
../bin/practica1: CMakeFiles/practica1.dir/src/solution.cpp.o
../bin/practica1: CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o
../bin/practica1: CMakeFiles/practica1.dir/src/solver.cpp.o
../bin/practica1: CMakeFiles/practica1.dir/build.make
../bin/practica1: CMakeFiles/practica1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ../bin/practica1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/practica1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practica1.dir/build: ../bin/practica1

.PHONY : CMakeFiles/practica1.dir/build

CMakeFiles/practica1.dir/requires: CMakeFiles/practica1.dir/src/greedy.cpp.o.requires
CMakeFiles/practica1.dir/requires: CMakeFiles/practica1.dir/src/agg.cpp.o.requires
CMakeFiles/practica1.dir/requires: CMakeFiles/practica1.dir/src/practica1.cpp.o.requires
CMakeFiles/practica1.dir/requires: CMakeFiles/practica1.dir/src/localSearch.cpp.o.requires
CMakeFiles/practica1.dir/requires: CMakeFiles/practica1.dir/src/age.cpp.o.requires
CMakeFiles/practica1.dir/requires: CMakeFiles/practica1.dir/src/genetico.cpp.o.requires
CMakeFiles/practica1.dir/requires: CMakeFiles/practica1.dir/src/solution.cpp.o.requires
CMakeFiles/practica1.dir/requires: CMakeFiles/practica1.dir/src/localSearchDLB.cpp.o.requires
CMakeFiles/practica1.dir/requires: CMakeFiles/practica1.dir/src/solver.cpp.o.requires

.PHONY : CMakeFiles/practica1.dir/requires

CMakeFiles/practica1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/practica1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/practica1.dir/clean

CMakeFiles/practica1.dir/depend:
	cd /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build /home/salva/Dropbox/UGR/3/2nd/MH/Practicas/UGR-MH/build/CMakeFiles/practica1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practica1.dir/depend

