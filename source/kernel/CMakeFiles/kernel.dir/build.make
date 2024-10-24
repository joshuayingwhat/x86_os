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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/joshuayingwhat/diy-x86os-master/start/start

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/joshuayingwhat/diy-x86os-master/start/start

# Include any dependencies generated for this target.
include source/kernel/CMakeFiles/kernel.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/kernel/CMakeFiles/kernel.dir/compiler_depend.make

# Include the progress variables for this target.
include source/kernel/CMakeFiles/kernel.dir/progress.make

# Include the compile flags for this target's objects.
include source/kernel/CMakeFiles/kernel.dir/flags.make

source/kernel/CMakeFiles/kernel.dir/init/start.S.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/init/start.S.o: source/kernel/init/start.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ASM object source/kernel/CMakeFiles/kernel.dir/init/start.S.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/kernel.dir/init/start.S.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/init/start.S

source/kernel/CMakeFiles/kernel.dir/init/start.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing ASM source to CMakeFiles/kernel.dir/init/start.S.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/init/start.S > CMakeFiles/kernel.dir/init/start.S.i

source/kernel/CMakeFiles/kernel.dir/init/start.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling ASM source to assembly CMakeFiles/kernel.dir/init/start.S.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/init/start.S -o CMakeFiles/kernel.dir/init/start.S.s

source/kernel/CMakeFiles/kernel.dir/core/memory.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/core/memory.c.o: source/kernel/core/memory.c
source/kernel/CMakeFiles/kernel.dir/core/memory.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/kernel/CMakeFiles/kernel.dir/core/memory.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/core/memory.c.o -MF CMakeFiles/kernel.dir/core/memory.c.o.d -o CMakeFiles/kernel.dir/core/memory.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/core/memory.c

source/kernel/CMakeFiles/kernel.dir/core/memory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/core/memory.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/core/memory.c > CMakeFiles/kernel.dir/core/memory.c.i

source/kernel/CMakeFiles/kernel.dir/core/memory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/core/memory.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/core/memory.c -o CMakeFiles/kernel.dir/core/memory.c.s

source/kernel/CMakeFiles/kernel.dir/core/task.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/core/task.c.o: source/kernel/core/task.c
source/kernel/CMakeFiles/kernel.dir/core/task.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object source/kernel/CMakeFiles/kernel.dir/core/task.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/core/task.c.o -MF CMakeFiles/kernel.dir/core/task.c.o.d -o CMakeFiles/kernel.dir/core/task.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/core/task.c

source/kernel/CMakeFiles/kernel.dir/core/task.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/core/task.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/core/task.c > CMakeFiles/kernel.dir/core/task.c.i

source/kernel/CMakeFiles/kernel.dir/core/task.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/core/task.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/core/task.c -o CMakeFiles/kernel.dir/core/task.c.s

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.o: source/kernel/cpu/cpu.c
source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.o -MF CMakeFiles/kernel.dir/cpu/cpu.c.o.d -o CMakeFiles/kernel.dir/cpu/cpu.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/cpu/cpu.c

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/cpu/cpu.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/cpu/cpu.c > CMakeFiles/kernel.dir/cpu/cpu.c.i

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/cpu/cpu.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/cpu/cpu.c -o CMakeFiles/kernel.dir/cpu/cpu.c.s

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.o: source/kernel/cpu/irq.c
source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.o -MF CMakeFiles/kernel.dir/cpu/irq.c.o.d -o CMakeFiles/kernel.dir/cpu/irq.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/cpu/irq.c

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/cpu/irq.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/cpu/irq.c > CMakeFiles/kernel.dir/cpu/irq.c.i

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/cpu/irq.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/cpu/irq.c -o CMakeFiles/kernel.dir/cpu/irq.c.s

source/kernel/CMakeFiles/kernel.dir/dev/time.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/dev/time.c.o: source/kernel/dev/time.c
source/kernel/CMakeFiles/kernel.dir/dev/time.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object source/kernel/CMakeFiles/kernel.dir/dev/time.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/dev/time.c.o -MF CMakeFiles/kernel.dir/dev/time.c.o.d -o CMakeFiles/kernel.dir/dev/time.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/dev/time.c

source/kernel/CMakeFiles/kernel.dir/dev/time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/dev/time.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/dev/time.c > CMakeFiles/kernel.dir/dev/time.c.i

source/kernel/CMakeFiles/kernel.dir/dev/time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/dev/time.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/dev/time.c -o CMakeFiles/kernel.dir/dev/time.c.s

source/kernel/CMakeFiles/kernel.dir/init/init.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/init/init.c.o: source/kernel/init/init.c
source/kernel/CMakeFiles/kernel.dir/init/init.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object source/kernel/CMakeFiles/kernel.dir/init/init.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/init/init.c.o -MF CMakeFiles/kernel.dir/init/init.c.o.d -o CMakeFiles/kernel.dir/init/init.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/init/init.c

source/kernel/CMakeFiles/kernel.dir/init/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/init/init.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/init/init.c > CMakeFiles/kernel.dir/init/init.c.i

source/kernel/CMakeFiles/kernel.dir/init/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/init/init.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/init/init.c -o CMakeFiles/kernel.dir/init/init.c.s

source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.o: source/kernel/ipc/mutex.c
source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.o -MF CMakeFiles/kernel.dir/ipc/mutex.c.o.d -o CMakeFiles/kernel.dir/ipc/mutex.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/ipc/mutex.c

source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/ipc/mutex.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/ipc/mutex.c > CMakeFiles/kernel.dir/ipc/mutex.c.i

source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/ipc/mutex.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/ipc/mutex.c -o CMakeFiles/kernel.dir/ipc/mutex.c.s

source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.o: source/kernel/ipc/sem.c
source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.o -MF CMakeFiles/kernel.dir/ipc/sem.c.o.d -o CMakeFiles/kernel.dir/ipc/sem.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/ipc/sem.c

source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/ipc/sem.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/ipc/sem.c > CMakeFiles/kernel.dir/ipc/sem.c.i

source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/ipc/sem.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/ipc/sem.c -o CMakeFiles/kernel.dir/ipc/sem.c.s

source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.o: source/kernel/tools/bitmap.c
source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.o -MF CMakeFiles/kernel.dir/tools/bitmap.c.o.d -o CMakeFiles/kernel.dir/tools/bitmap.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/bitmap.c

source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/bitmap.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/bitmap.c > CMakeFiles/kernel.dir/tools/bitmap.c.i

source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/bitmap.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/bitmap.c -o CMakeFiles/kernel.dir/tools/bitmap.c.s

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/klib.c.o: source/kernel/tools/klib.c
source/kernel/CMakeFiles/kernel.dir/tools/klib.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/klib.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/tools/klib.c.o -MF CMakeFiles/kernel.dir/tools/klib.c.o.d -o CMakeFiles/kernel.dir/tools/klib.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/klib.c

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/klib.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/klib.c > CMakeFiles/kernel.dir/tools/klib.c.i

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/klib.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/klib.c -o CMakeFiles/kernel.dir/tools/klib.c.s

source/kernel/CMakeFiles/kernel.dir/tools/list.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/list.c.o: source/kernel/tools/list.c
source/kernel/CMakeFiles/kernel.dir/tools/list.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/list.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/tools/list.c.o -MF CMakeFiles/kernel.dir/tools/list.c.o.d -o CMakeFiles/kernel.dir/tools/list.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/list.c

source/kernel/CMakeFiles/kernel.dir/tools/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/list.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/list.c > CMakeFiles/kernel.dir/tools/list.c.i

source/kernel/CMakeFiles/kernel.dir/tools/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/list.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/list.c -o CMakeFiles/kernel.dir/tools/list.c.s

source/kernel/CMakeFiles/kernel.dir/tools/log.c.o: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/log.c.o: source/kernel/tools/log.c
source/kernel/CMakeFiles/kernel.dir/tools/log.c.o: source/kernel/CMakeFiles/kernel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/log.c.o"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/kernel/CMakeFiles/kernel.dir/tools/log.c.o -MF CMakeFiles/kernel.dir/tools/log.c.o.d -o CMakeFiles/kernel.dir/tools/log.c.o -c /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/log.c

source/kernel/CMakeFiles/kernel.dir/tools/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/log.c.i"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/log.c > CMakeFiles/kernel.dir/tools/log.c.i

source/kernel/CMakeFiles/kernel.dir/tools/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/log.c.s"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && /usr/local/bin/x86_64-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/tools/log.c -o CMakeFiles/kernel.dir/tools/log.c.s

# Object files for target kernel
kernel_OBJECTS = \
"CMakeFiles/kernel.dir/init/start.S.o" \
"CMakeFiles/kernel.dir/core/memory.c.o" \
"CMakeFiles/kernel.dir/core/task.c.o" \
"CMakeFiles/kernel.dir/cpu/cpu.c.o" \
"CMakeFiles/kernel.dir/cpu/irq.c.o" \
"CMakeFiles/kernel.dir/dev/time.c.o" \
"CMakeFiles/kernel.dir/init/init.c.o" \
"CMakeFiles/kernel.dir/ipc/mutex.c.o" \
"CMakeFiles/kernel.dir/ipc/sem.c.o" \
"CMakeFiles/kernel.dir/tools/bitmap.c.o" \
"CMakeFiles/kernel.dir/tools/klib.c.o" \
"CMakeFiles/kernel.dir/tools/list.c.o" \
"CMakeFiles/kernel.dir/tools/log.c.o"

# External object files for target kernel
kernel_EXTERNAL_OBJECTS =

source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/init/start.S.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/core/memory.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/core/task.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/dev/time.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/init/init.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/klib.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/list.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/log.c.o
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/build.make
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/joshuayingwhat/diy-x86os-master/start/start/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable kernel"
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kernel.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && x86_64-elf-objcopy -S kernel.elf /Users/joshuayingwhat/diy-x86os-master/start/start/../../image/kernel.elf
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && x86_64-elf-objdump -x -d -S -m i386 /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/kernel.elf > kernel_dis.txt
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && x86_64-elf-readelf -a /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/kernel.elf > kernel_elf.txt

# Rule to build all files generated by this target.
source/kernel/CMakeFiles/kernel.dir/build: source/kernel/kernel
.PHONY : source/kernel/CMakeFiles/kernel.dir/build

source/kernel/CMakeFiles/kernel.dir/clean:
	cd /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel && $(CMAKE_COMMAND) -P CMakeFiles/kernel.dir/cmake_clean.cmake
.PHONY : source/kernel/CMakeFiles/kernel.dir/clean

source/kernel/CMakeFiles/kernel.dir/depend:
	cd /Users/joshuayingwhat/diy-x86os-master/start/start && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/joshuayingwhat/diy-x86os-master/start/start /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel /Users/joshuayingwhat/diy-x86os-master/start/start /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel /Users/joshuayingwhat/diy-x86os-master/start/start/source/kernel/CMakeFiles/kernel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/kernel/CMakeFiles/kernel.dir/depend

