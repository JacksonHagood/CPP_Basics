# Setup

## What is C++?

C++ is a popular programming language, typically used for application development. C++ was designed by [Bjarne Stroustrup](https://www.stroustrup.com/) on top of the C programming language, with perhaps its largest addition being object-oriented programming. C++ is a high-level, compiled language that retains some lower-level functionality (such as memory management) from C. C++ is faster than many other high-level languages and is widely supported on many platforms.

## Transitioning from Python to C++

> Note: some of this section / repository assumes a background in Python or a similar language as a starting point.

To better transition from Python to C++, it is important to understand the major differences between the languages. Python is an interpreted language, meaning a program called an interpreter converts each line of code to machine code one at a time during execution (runtime). C++, on the other hand, is a compiled language. A program called a **compiler** (like g++) converts an entire C++ program to machine code (compile-time) before runtime. Then, this machine code is run using an executable file. What this means in practice is that C++ is "lower-level" (closer to machine code) and typically faster (sometimes at the expense of memory). There are many differences in syntax between the languages as well.

It will soon become clear that C++ often takes "more code" to accomplish the same operation in Python. This is not an "inefficiency" or poor design. Python will often take the same steps as more lengthy C++ code, the only difference is the interpreter fills in these gaps and does a lot of the heavy lifting. In truth, it is Python that is often the more inefficient of the two. Furthermore, C++ has more flexibility in what the programmer can accomplish (and how errors can occur).

C++ is unique in that it combines the freedom of a low-level language, like C, with the high-level structures and capabilities of a language like Python. This means the programmer has a lot of choice in how they want to program and C++ can be (comparatively) fast. For example, the programmer can implement their own dynamic array by managing dynamic memory, or simply use a vector class. This repository focuses on a C-flavored C++, with an emphasis on memory management and pointers.

## Using a Compiler

As previously stated, C++ code requires a compiler in order to be converted into an executable (machine code that the CPU can understand). There is no single "official" C++ compiler. When choosing a compiler, it is important to ensure it conforms to the ISO C++ Standard. The [GNU Compiler](https://gcc.gnu.org/) (**g++**) will be used here thanks to its compatibility and memory error detection. Each program in this repository has a corresponding makefile, but it is still useful to understand how to manually compile. The below command can be used to compile a C++ program called main.

```
g++ -std=c++17 -Wextra -Weffc++ -Wunused -pedantic -fsanitize=address,undefined -o main.exe main.cpp
```

`g++` is GNU C++ Compiler command. The following 6 items are compiler flags (beginning with `-`). These flags are optional, but notify the compiler of several things. The first flag, `-std=c++17`, specifies the version of C++. The Following 4 flags will give warnings during compile time that may help the programmer write better code and spot potential runtime errors. Finally, `-fsanitize=address,undefined` is particularly important, as it will notify of any memory errors such as memory leaks (this will become much more important later). Next, `-o main.exe` specifies the output file as `main.exe` (this is optional, the default name is `a.out`). Finally, `main.cpp` is the file that is to be compiled (multiple can be given, `*.cpp` will compile all the .cpp files in the current directory). After compilation, `./main.exe` can be used to run the program.

```
./main.exe
```

### Installing `g++`

`g++` can be installed in a Linux environment with the following command. If on Windows, WSL can be used to get a Linux shell.

```
sudo apt install build-essential
```

### Alternative Compilers

- [Microsoft Visual](https://visualstudio.microsoft.com/vs/features/cplusplus/)
- [Clang](https://clang.llvm.org/)
- Xcode (OS X)
- [Oracle C++](https://www.oracle.com/application-development/technologies/developerstudio.html)

## Hello World

With some background and setup completed, a simple C++ program can be made. See the below C++ code:

```C++
# include <iostream>
using std::cout;

int main() {
    cout << "Hello World\n";
    
    return 0;
}
```

The first two lines import `cout`, the standard output stream which works similar to Python's `print()`. The body of the program is given in the `main()` function. Every C++ program needs a `main()` function as that is where execution always begins. Note that `main()` is given a type of `int` as functions in C++ must have a type. the line `cout << "Hello World\n";` sends the `"Hello World"` message to the standard output stream (terminal). The `\n` adds a new line after. Finally, `return 0` is given as `main()` is an `int` function (`0` typically indicates successful completion, `1` indicates a problem).

## Example Program

An example program is provided to demonstrate this material.

### Usage (try compiling manually with the provided commands)
- compile: `make`
- run: `./main.exe`
- cleanup: `make clean`

## Sources and Further Material

- [g++](https://gcc.gnu.org/)
- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)
