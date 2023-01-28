# Makefiles

**Makefiles** are a way for the programmer to define how a C++ program should be compiled and run into more basic "make" commands. This allows the programmer to avoid typing long compile commands repeatedly and eliminate ambiguity for other programmers. This repository makes ample use of makefiles.

## Basic Syntax

As an example, say the programmer has a main program in `main.cpp` that uses functions from `functions.cpp`. To compile this program the below makefile could be used. Notice that under the all identifier is the compile command. This is what will run when the user issues `make` in the command line. The clean identifier is typically used to remove any executables or other files used to compile a program. This can be run with `make clean`.

```
all: main.cpp functions.cpp
	g++ -std=c++17 -Wextra -Weffc++ -pedantic -fsanitize=address,undefined -o program.exe main.cpp functions.cpp

clean:
	rm program.exe
```

This method of makefiles simply uses the full compile command to convert the program to an executable. While this is perfectly valid, makefile's typically compile differently.

## Advanced Syntax

The below makefile compiles the same program before in two steps. Before `program.exe` is generated, object files (`.o`) are generated for each of the `.cpp` files. These object files are not executable, but are the C++ code in machine code. Then, to generate the executable, these object files are compiled to an executable.

```C++
all: main.o functions.o
	g++ main.o functions.o -o program.exe

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

clean:
	rm *.o program.exe
```
