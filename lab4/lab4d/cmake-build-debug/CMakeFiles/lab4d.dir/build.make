# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\my stuff\itmo\algo\lab4\lab4d"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\my stuff\itmo\algo\lab4\lab4d\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\lab4d.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\lab4d.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\lab4d.dir\flags.make

CMakeFiles\lab4d.dir\main.cpp.obj: CMakeFiles\lab4d.dir\flags.make
CMakeFiles\lab4d.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\my stuff\itmo\algo\lab4\lab4d\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab4d.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\lab4d.dir\main.cpp.obj /FdCMakeFiles\lab4d.dir\ /FS -c "C:\my stuff\itmo\algo\lab4\lab4d\main.cpp"
<<

CMakeFiles\lab4d.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4d.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\lab4d.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\my stuff\itmo\algo\lab4\lab4d\main.cpp"
<<

CMakeFiles\lab4d.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4d.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab4d.dir\main.cpp.s /c "C:\my stuff\itmo\algo\lab4\lab4d\main.cpp"
<<

# Object files for target lab4d
lab4d_OBJECTS = \
"CMakeFiles\lab4d.dir\main.cpp.obj"

# External object files for target lab4d
lab4d_EXTERNAL_OBJECTS =

lab4d.exe: CMakeFiles\lab4d.dir\main.cpp.obj
lab4d.exe: CMakeFiles\lab4d.dir\build.make
lab4d.exe: CMakeFiles\lab4d.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\my stuff\itmo\algo\lab4\lab4d\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab4d.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\lab4d.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\lab4d.dir\objects1.rsp @<<
 /out:lab4d.exe /implib:lab4d.lib /pdb:"C:\my stuff\itmo\algo\lab4\lab4d\cmake-build-debug\lab4d.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\lab4d.dir\build: lab4d.exe
.PHONY : CMakeFiles\lab4d.dir\build

CMakeFiles\lab4d.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab4d.dir\cmake_clean.cmake
.PHONY : CMakeFiles\lab4d.dir\clean

CMakeFiles\lab4d.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\my stuff\itmo\algo\lab4\lab4d" "C:\my stuff\itmo\algo\lab4\lab4d" "C:\my stuff\itmo\algo\lab4\lab4d\cmake-build-debug" "C:\my stuff\itmo\algo\lab4\lab4d\cmake-build-debug" "C:\my stuff\itmo\algo\lab4\lab4d\cmake-build-debug\CMakeFiles\lab4d.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\lab4d.dir\depend
