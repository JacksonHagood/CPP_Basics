# Variables

> Note: all the variables in this section are on the stack (static memory). Section 10: The Heap discusses variables on the heap (dynamic memory).

## Creation

### Declaration

To declare a variable in C++, two things are needed: a type and a name (**identifier**). For example, the below code **declares** two variables. Data types in C++ have a size associated with them (in bytes).

```C++
int num1; // integer variable
char c1; // character variable
```

### Initialization

When declaring a variable in C++ without giving an initial value (**initializing**), the variable will take on a "**garbage value**". This garbage value is whatever happens to be stored in that memory previously. Therefore, it is often important to give an initial value before performing operations on the variable. This can be done when the variable is declared using the `=` operator (assignment operator).

```C++
int num2 = 0;
char char2 = 'A'; // single quotes denote a char
```

### Constants

In addition to having a name and a type, variables can be constant in C++. As expected, a constant variable is one that cannot be altered after it is initialized. To make a variable constant, use the `const` keyword during declaration.

```C++
const int num3 = 0;
```

## Types

### Primitives

Booleans (`bool`), characters (`char`), integers (`int`), and floating point nubers (`float`) are the four main primitive types in C++. Once a variable is declared in C++ its type cannot be changed.

```C++
// 4 main primitive types
bool boolean = true;
char character = 'a';
int integer = 1;
float floating = 0.1;
```

### Size

Each type in C++ has an associated size (in bytes) that cannot be altered. For example, a standard integer (`int`) takes up 4 bytes (32 bits) of memory. If the programmer wishes to have an integer with a different size, they can use the **short** and **long** keywords. For a 1 byte integer, the `char` type can be used as characters are represented as 1 byte numbers in ASCII. Depending on the operating system, the size of types can vary slightly. If the programmer wants an integer that can only be positive (or 0) they can use the **unsigned** keyword.

```C++
char num1; // 1 byte
short num2; // 2 bytes
int num3; // typically 4 bytes
long num4; // typically 8 bytes

unsigned int num5; // unsigned 4 byte integer
```

### Overflow

Due to this static size, there is a finite set of the values that can be stored in an variables of a certain type. For a 4 byte integer, these values range from `INT32_MIN` to `INT32_MAX`. `INT32_MIN` is one greater in absolute value than `INT32_MAX` as there must be space to store the value `0`. If either of these values are exceeded, the variable will **overflow**. This will not always cause an error, but will likely produce undesired behavior.

```C++
int min = INT32_MIN; // minimum integer value (-2147483648)
int max = INT32_MAX; // maximum integer value (2147483647)

min--; // overflow: minimum value exceeded
max++; // overflow: maximum value exceeded
```

### Bases

Integers in C++ are typically output in base 10, but other bases can be used. This can be done by giving a prefix (`0b` for binary, `0x` for hex).

```C++
// different bases
10; // decimal
0b1010; // binary
0xA; // hex
```

## Operators

### Arithmetic

In order to change the values of variables after declaration, operators can be used. These operators work very similiarly to those in Python. For example, integer and floating point variables have the standard arithmetic operators (`+`, `-`, `*`, `/`, and `%`).

```C++
// arithmetic operators
8 + 2; // 10
8 - 2; // 6
8 * 2; // 16
8 / 2; // 4
8 % 2; // 0
```

C++ also comes with **increment** (`++`) and **decrement** (`--`) operators. This means there are three ways to increment a variable in C++. These two operators can be placed before or after the variable depending on whether the programmer wants the previous value as part of another operation.

```C++
num = num + 1; // assignment and addition
num += 1; // add and assignment
num++; // increment
```

### Bitwise

Another set of operators can be used on integers: bitwise operators. These operators perform operations on each of the bits in a number. For example, bitwise and (`&`) performs the equivalent of logical and on each of the bits. There are also bitwise operators for or (`|`), xor (`^`), and not (`~`). The left shift (`<<`) and right shift (`>>`) operators will move the bits over a provided number of spaces (same as raising two a power or root).

```C++
// bitwise operators
8 & 2; // 0
8 | 2; // 10
8 ^ 2; // 10
~8; // -9
8 << 2; // 32
8 >> 2; // 2
```

### Logical

The logical operators work like counterparts in Python (`&&`, `||`, and `!`). Unlike bitwise operators, these perform the logical function over the variable as a whole, not the individual bits (evaluate to a boolean).

```C++
8 && 2; // 1
8 || 2; // 1
!8; // 0
```

### Comparison

A final set of operators can be used to compare values. These operators (`>`, `<`, `>=`, `<=`, `==`, and `!=`) evaluate to a boolean.

```C++
8 > 2; // 1
8 < 2; // 0
8 >= 2; // 1
8 <= 2; // 0
8 == 2; // 0
8 != 2; // 1
```

## Arrays

Arrays in C++ are very different from arrays in Python. An array in C++ is a **pointer** to a contiguous block of memory. Pointers will be discussed more in Section 09: Pointers. One result from this is that arrays in C++ cannot be resized once made (as the memory before and after the block might be in use). Techniques will be discussed later on how to get around this, but for now arrays are static. Arrays can be made similiar to other variables. the `[]` operator can be used to index an array.

```C++
int numArray[4]{5, 9, 12, 7}; // 4 * 4 = 16 bytes of memory
```

> Note: There are no built in array functions such as size() or at() as arrays are not objects.

## Example Program

A program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./variables.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)