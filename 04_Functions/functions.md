# Functions

Often when programming, it is useful to re-use sections of code and assign identifiers to them. **Functions** are a mechanism that allows for this within C++. As expected, they work similarly to functions in Python, but with some key differences.

## Function Signature

A function's **signature** is comprised of the function's name, type, and parameters (not the actual body of the function). Function's in C++ have an associated type which denotes what data type the function returns. If the programmer wishes to write a function without a returned value, they can make it `void` (can still have a `return` statement, just without a value).

```C++
int foo() {
    return 0; // returned value must match function type
}
```

```C++
void hello_world() {
    cout << "Hello, World!\n";
    return; // optional return that stops execution
}
```

## Parameters

Function's in C++ can have **parameters** each containing an identifier and a type. These parameters comprise the input(s) of the function and can be provided in multiple ways. There are three ways parameters can be passed into functions: pass by value, pass by reference, and pass by pointer.

### Pass by Value

The most common way of passing parameters into functions is through **pass by value**. Here, when using the parameter inside the function, any operations on that variable do not persist or change the original variable used when calling the function. Instead, operations are done on a copy that is made when the function begins.

```C++
void foo(int num) {
    num = 1; // changes only num, which is a copy of original
}
```

```C++
int main() {
    int original = 0;
    foo(original);
    // original is still 0
}
```

### Pass by Reference

**Pass by reference** is a way of providing parameters so that operations on the parameters affect the original variables used to call the function. In other words, the parameter variable is just another name for the same variable that was used outside the function (not a copy). To pass a variable by reference, add `&` after the type.

```C++
void foo(int& num) {
    num = 1; // operations on num change both
}
```

```C++
int main() {
    int original = 0;
    foo(original);
    // original is now 1
}
```

### Pass by Pointer

> Note: pointers are discussed more in [09: Pointers](../09_Pointers/pointers.md).

A final way to pass parameters is with **pass by pointer**. Pass by pointer is really just a special case of pass by value that leverages how pointers work to change a specific location in memory. In practice, this will produce the same results as pass by reference, but it does require the data type to be changed to a pointer. A side effect of arrays being pointers is that arrays are always passed by pointer (functions will change the original arrays).

```C++
void foo(int* ptr) {
    *ptr = 1; // operations on the memory address of original
}
```

```C++
int main() {
    int original = 0;
    foo(&original);
    // original is now 1
}
```

### Pass as Constant

Oustide of whether parameters can be pass by value, reference, or pointer, they can also be passed as a constant. If a variable is passed as a constant, it cannot be changed within that function (regardless of how else it was passed).

```C++
void pass_as_const(const int num) {
    // num cannot be changed
}
```

## Recursion

**Recursive** functions are functions that call themselves. Often, problems in C++ can be solved with recursion in a conceptually more intuitive way. To avoid infinite recursion, there must be a base case (some scenario where the function is no longer recursively called). As an example, a factorial function could be defined recursively as follows.

```C++
int recursive_factorial(int num) {
    if (num > 1) {
        // recursive call
        return num * recursive_factorial(num - 1);
    }

    // base case
    return num;
}
```

Though recursion can be useful, every recursive function can be defined iteratively (sometimes with the addition of a variable). Recursion has several downsides due to additional function calls requiring more memory and runtime. Therefore, for the best performance, iterative implementations are usually best.

```C++
int iterative_factorial(int num) {
    // additional variable
    int result = 1;

    for (int i = 2; i <= num; i++) {
        result *= i;
    }

    return result;
}
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./functions.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language/functions)
- [CPP](https://cplusplus.com/doc/tutorial/functions/)
