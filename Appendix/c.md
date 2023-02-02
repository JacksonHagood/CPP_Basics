# C

While C++ is the focus of this repository, it is useful to understand some basics of the C programming language. C++ is built on top of C with its largest addition being object-oriented programming. The C language was developed primarily for operating system development, meaning (by modern standards) it is low-level. While not everything in C++ is available in C, everything in C is available in C++. This makes it useful to know some C alternatives when solving C++ problems. This document covers some of these differences.

## `stdio.h`

As C has no classes, there are no stream types. Therefore, input and output in C is handled differently. `stdio.h` has some simple input and output functions. Like with `iostream` in C++, this must first be included.

```C
# include <stdio.h>
```

### `printf()`

The `printf()` function is the standard way of outputting to the terminal in C. This function is capable of outputting strings along with any variables or values the user wishes. First, the argument accepts a string with all the specifier flags on where subsequent variables / values should be (as well as their type). Below is an example of `printf()` being used to output a string with some values.

```C
printf("%c in ASCII is %d\n", 'a', 97);
```

Below is a table showing some possible specifier flags.

| specifier | type      |
| --------- | --------- |
| `%d`      | integer   |
| `%f`      | float     |
| `%c`      | character |
| `%s`      | string    |
| `%p`      | pointer   |

### `scanf()`

The `scanf()` function is the standard way of obtaining user input in C. This function first accepts a string of all the specifier flags outlining all the values to be read in. Then, the function accepts the addresses of variables to populate with these values. For example, the below command reads an integer value into a variable num.

```C
scanf("%d", &num);
```

### Example Program

Below is a program to demonstrate C I/O.

```C
# include <stdio.h>

int main() {
    printf("Enter your age: ");

    int age;

    scanf("%d", &age);
    printf("Your age is: %d\n", age);
}
```

## Memory Management

The main method of memory management in C++ is with `new` and `delete`. C has no concept of these commands and instead makes use of `malloc()` and `free()`. To use these functions, the standard library header must be included.

```C
#include <stdlib.h>
```

### `malloc()`

The `malloc()` function is the main method of allocating memory on the heap in C. This function accepts a parameter indicating the number of bytes to allocate. The function will then return a `void*` indicating the memory address where this has been allocated to. As an example, if the programmer wanted a single integer on the heap, they would call `malloc()` with 4 as the parameter (as integers are 4 bytes). Then, this result would be cast to an `int*` (as `malloc()` returns a `void*`) and stored inside a pointer variable.

```C
int* ptr = (int*) malloc(4);
```

At this point, this pointer variable can be used just like C++ (such as using the dereference operator).

```C
*ptr = 5;
```

### `free()`

The `free()` function is the main way to deallocate memory in C. The function accepts a `void*` indicating memory to be deallocated.

```C
free(ptr);
```

### Example Program

Below is a program to demonstrate C memory management.

```C
# include <stdio.h>
# include <stdlib.h>

int main() {
    int* ptr = (int*) malloc(20);

    printf("Enter 5 numbers: ");

    for (unsigned char i = 0; i < 5; i++) {
        scanf("%d", &ptr[i]);
        printf("Number %d: %d\n", i, ptr[i]);
    }

    free(ptr);
}
```

## Structures

C++ has extensive object-oriented programming functionality. While C lacks the vast majority of this functionality, it still makes use of `structs`.

### `struct`

While structs in C++ can make use of member functions, private and public fields, and many other features, structs in C are much more primitive. In C, a `struct` defines a group of variables (identifiers and types) into one container. That is the full extent of the functionality.

### Example Program

Below is a program to demonstrate C structs.

```C
# include <stdio.h>

struct Person {
    char firstInitial;
    char lastInitial;
    int age;
};

int main() {
  struct Person p;

  p.firstInitial = 'J';
  p.lastInitial = 'H';
  p.age = 21;

  printf("%c%c is %d years old\n", p.firstInitial, p.lastInitial, p.age);

  return 0;
}
```

## Sources and Further Material

- [C documentation from CPP Reference](https://en.cppreference.com/w/c/language)
