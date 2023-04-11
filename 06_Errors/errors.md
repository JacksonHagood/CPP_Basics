# Errors

No programmer is immune from errors and it is therefore important to understand them. Errors in C++ can be split into three main categories: compile-time errors, runtime errors, and logical errors.

## Compile-time Errors

**Compile-time** errors are any errors that occur during the attempted compilation of a program. Essentially, the compiler attempts to compile the C++ program into an executable but encounters some issue with the user's code and fails to compile. Most compilers are good at alerting the programmer of these issues. Two main types of compile-time errors are syntax errors and linker errors.

### Syntax Errors

**Syntax errors** are errors caused by the programmer writing incorrect C++ code. Perhaps the singly most encountered syntax error is the programmer forgetting a semicolon after a statement. These issues are typically the easiest to fix.

```C++
int a = 1 // forgot semicolon
int b = 2;
```

```
main.cpp:5:5: error: expected ‘,’ or ‘;’ before ‘int’
    5 |     int b = 2;
      |
```

### Linker Errors

**Linker errors** occur when the compiler looks for the definition of a function or header file but cannot find it. A very common example of this is when the programmer forgets to define a main function (as every C++ program starts at the main function). Another common example is attempting to use `cout` without including `iostream`.

```C++
using std::cout; // iostream never included

int main() {
    cout << "A";
}
```

```
main.cpp:1:12: error: ‘std::cout’ has not been declared
    1 | using std::cout; // iostream never included
      |
```

### Warnings

When compiling a C++ program, often programmers will compile with several flags. Some of these flags alert the compiler to notify them of any warnings (`-Wextra`, `-Weffc++`, `-pedantic`, etc.). **Warnings** are not errors, but they often alert the programmer of code that could cause errors (runtime errors). Warnings do not prevent the compilation of a program either, but they should usually not be ignored. A common example of a warning is a function missing a return statement for some path.

```C++
int foo() {
    if (false) {
        return 0;
    }
    // no return statement
}
```

```
main.cpp:8:1: warning: control reaches end of non-void function [-Wreturn-type]
    8 | }
      |
```

## Runtime Errors

**Runtime errors** are errors that occur during the execution of a C++ program. These errors do not prevent compilation, but stop the program from continuing to execute because of some software error. These errors are typically harder to debug than compile-time errors. One common example of a runtime error is a **segmentation fault**. A segmentation fault occurs when a C++ program attempts to access memory that is not available to it (like accessing an array beyond its bounds).

```C++
int nums[3] = {0, 1, 2};
cout << nums[10]; // can cause segmentaiton fault at runtime
```

```
main.cpp:5:20: runtime error: index 10 out of bounds for type 'int [3]'
```

Another example of a runtime error is divide by zero (though warnings can help spot this).

```C++
cout << 1 / 0; // divide by zero error at runtime
```

```
main.cpp:4:15: runtime error: division by zero
```

## Logical Errors

> Note: memory leaks are discussed in [10: The Heap](../10_The_Heap/heap.md)

The final category of errors are logical errors. **Logical errors** are not "real" errors as they do not prevent the compilation or execution of a C++ program. Instead, logical errors are discrepancies between what the programmer intends to occur and what they actually programmed. These are typically the hardest errors to debug as the compiler has no real sense of when they occur. One example of a logical error the programmer expecting `5 / 2` to result in `2.5`, but instead get `2` as they forgot about integer division.

```C++
cout << 5 / 2; // possible logical error
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./errors.exe`
- cleanup: `make clean`
