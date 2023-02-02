# File Types

To best organize code, it is important to understand the different C++ file types and their purposes.

## `.cpp`

The main C++ file type is `.cpp`. These files are for the majority of a program's source code. At least one of these `.cpp` files should have a main function for every C++ program.

## `.h`

Header files are typically used for class definitions, function prototypes, and other declarative uses. Typically, these files don't have the actual bodies of functions, rather just their prototype (though it is acceptable). These header files are what will be included by other files. For example, if a file `main.cpp` wants access to the function prototypes of `functions.h` it would include it (notice the lack of `<` as these are made by the programmer, not build into the compiler).

```C++
# include "functions.h"
```

### Header Guards

One important component of header files are header guards. These help avoid errors when the same header files is included multiple times.

```C++
# ifndef FUNCTIONS_H
# define FUNCTIONS_H

// class definitions, function prototypes, etc.

# endif
```

## `.c`

Though often not encountered, `.c` files are for C source code. It is possible to compile C source code with C++ source code, so it is useful to be familiar with the extension. Typically, C++ specific structures should not be in these files (such as classes). Interestingly. `.h` files can refer to C++ or C code.
