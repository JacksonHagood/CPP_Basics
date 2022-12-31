# Setup

## What is C++?

C++ is a popular programming language, typically used for application development. C++ is built on top of the C programming language, with its largest addition being object-oriented programming. C++ is a high-level, compiled language that retains some lower-level functionality (such as memory management). C++ is faster than many other high-level languages and is supported on many platforms.

## Transitioning from Python to C++

> Note: much of this section assumes a background in Python. Even if without a Python background, much of this information might be helpful.

To better transition from Python to C++, it is important to understand the major differences between the languages. Python is an interpreted language, meaning a program called an interpreter converts each line of code to machine code one at a time during execution (runtime). C++, on the other hand, is a compiled language. A program called a compiler (g++) converts an entire C++ program to machine code (compile time) before runtime. What this means in practice is that C++ is lower-level (closer to machine code) and typically faster (often at the expense of memory). There are many differences in syntax between the languages as well.

It will soon become clear that often C++ takes more code to accomplish the same operation as Python, but this is not because C++ is "inefficient". Python will often take the same steps as more lengthy C++ code, the only difference is the interpreter fills in these gaps and does a lot of the heavy lifting. In truth, it is Python that is often the more inefficient of the two. Futhermore, C++ has more flexibility in what the programmer can accomplish (and how errors can occur).

> Takeaway: C++ must be compiled (g++) before it can be executed. C++ is closer to machine code (lower-level) than languages like Python.

## Using a Compiler

As previously stated, C++ code requires a compiler in order to be converted into an executable (machine code that the CPU can understand). g++ will be used here as it has great compatibility with many platforms. Each program in this repository has a corresponding makefile, but it is still useful to understand how to manually compile. The below command can be used to compile a C++ program called main.

```NA
g++ -std=c++17 -Wextra -Weffc++ -pedantic -fsanitize=address,undefined -o main.exe main.cpp
```

`g++` specifies the GNU C++ Compiler. The following 5 items are compiler flags (beginning with `-`). These flags are optional, but will give warnings during compile time that may help the programmer write better code and spot potential runtime errors. `-fsanitize=address,undefined` is particularly important, as it will notify of any memory errors such as memory leaks (this will become much more important later). Next, `-o main.exe` specifies the output file as main.exe (this is optional, the default name is `a.out`). Finally, `main.cpp` is the file that is to be compiled (multiple can be given, `*.cpp` will compile all the .cpp files in the current directory). After compilation, `./main.exe` can be used to run the program.

> Takeaway: Compile with `g++ -std=c++17 -Wextra -Weffc++ -pedantic -fsanitize=address,undefined *.cpp`, run with `./a.out`.

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

The first two lines import `cout`, the standard output stream which works similar to Python's `print()`. The body of the program is given in the `main()` function. Every C++ program needs a `main()` function as that is where execution always begins. Note that `main()` is given a type of `int` as functions in C++ must have a type. the line `cout << "Hello World\n";` sends the `"Hello World"` message to the standard output stream (terminal). The `"\n"` adds a new line after. Finally, `return 0` is given as `main()` is an `int` function (0 typically indicates successful completion, 1 indicates a problem).

## Example Program

An example program is provided to demonstrate Hello World.

### Usage
- compile: `make`
- run: `./main.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)
