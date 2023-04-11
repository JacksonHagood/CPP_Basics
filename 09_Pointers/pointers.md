# Pointers

Core to a more well-rounded concept of memory in C++ is pointers. **Pointers** are variables that store memory addresses. Though they can be used in interesting ways, memory addresses are just numbers (typically denoted in hexadecimal). This means standard operators will work on pointers like they would on other integer types.

## Pointer Types

The types of pointers reference the type of memory they point to. For example, an integer pointer (`int*`) points to a location in memory for an integer. This is important as the compiler must know how many bytes to look for after the address (4 for integers). Void pointers (`void*`) are a special as they have no corresponding type. Void pointers are rarely seen but can have some interesting use cases.

```C++
int* intPtr; // pointer to an integer (4 bytes)
char* charPtr; // pointer to a char (1 byte)
void* voidPtr; // pointer with no type
```

## Address Operator

In order to effectively create pointers, the **address operator** (`&`) can be used. This operator returns the memory address of a variable (of any type). This can therefore be used to initialize pointers to the memory addresses of other variables.

```C++
int num = 1; // value of num is 1
int* ptr = &num; // value of ptr is the address of num (0x...)
```

## Dereference Operator

The **dereference operator** (`*`) allows effective use of pointers. Essentially, the dereference operator accepts a memory address and returns a reference to that address ("goes to where a variable points"). This means pointers can be used to both store the address of something and change the value of it.

```C++
*ptr = 2; // sets the value of num to 2
```

## Revisiting the `[]` Operator

It turns out the `[]` operator, used to index an array, is another type of dereference operator. This is because arrays are actually pointers. Array variables point to the beginning of a section of contiguous memory and the `[]` operator is used to access elements.

```C++
int numArray[3]; // value of numArray is address of first element
numArray[1]; // dereference operator adds to base address and dereferences (same as a combination of + and *)
```

## `nullptr`

Like normal variables, pointers have a special null value: `nullptr`. The programmer can use this value as they wish, but they are typically used for situations where pointers either point nowhere, or memory they used to point to has been deleted. Attempting to dereference a `nullptr` will cause an error as the value (`0x0`) is not allocated to the programmer.

```C++
int* ptr = nullptr; // special value
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./pointers.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/book/pointers)
- [CPP](https://cplusplus.com/doc/tutorial/pointers/)
