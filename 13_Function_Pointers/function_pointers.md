# Function Pointers

Variables are not the only structures stored in memory. Among other items, the source code of programs are present in a section of memory for text. This section stores the compiled code for all the functions present in a C++ program. Therefore, like anything else in memory, these functions have an associated address. This is the basis for **function pointers**. Function pointers allow the programmer to treat functions like they would a variable, which enables many abilities in **functional programming**.

## Example

As an example, take a function `adder()`, which simply returns the sum of two integers.

```C++
int adder(int a, int b) {
    return a + b;
}
```

To output the address of `adder()`, the programmer can output the functions identifier (without `()`) and cast it as a `void*`.

```C++
cout << (void*) adder; // outputs address of adder() (0x...)
```

Access to function pointers provides some interesting use cases. One example is passing function pointers as function arguments. For example, a function `caller()` accepts two integers and a function pointer. The function pointer is outlined as a function that accepts two integers and returns an integer.

```C++
int caller(int a, int b, int (*function)(int, int)) {
    return function(a, b);
}
```

Since `adder()` meets these input and output requirements, it can be passed to caller as a function pointer. For example, if caller were invoked with `2`, `3`, and `&adder` it would return `5`.

```C++
caller(2, 3, &adder); // returns 5.
```

## Purpose

By allowing functions to be treated like variables and be passed into functions, like the previous example, C++ enables greater functional programming. As opposed to object-oriented programming (OOP), functional programming emphasizes a deterministic approach, with a clear separation of variables and functions. Though C++ is OOP in nature, it has several tools to enable functional programming and the programmer can choose the approach they wish.

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./function_pointers.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language/pointer)
