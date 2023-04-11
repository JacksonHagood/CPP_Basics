# Syntax

Before exploring the basic components in C++, it is advantageous to discuss the basics of the C++ syntax. Because C++ is a compiled language, its syntax differs greatly from a higher-level, interpreted language like Python.

## Basics

C++ is much more explicit with its syntax with Python. This leads to more well-defined code and less ambiguity.

### `;`

Perhaps the first observation made by newcomers to C++ is the prevalence of semicolons. Each statement in C++ must be terminated with a semicolon (`;`). In Python, the end of statements could be determined using whitespace, but C++ has no concept of whitespace as a part of syntax (beyond separating parts of statements). Therefore, the semicolon is used to determine where statements end.

```C++
int number = 1; // statement ends with semicolon
```

### `{}`

Core to C++ is the concept of **scope** as each variable in C++ has an associated scope with it. Once the scope of a variable is exceeded, the variable no longer exists and cannot be used. To best illustrate the start and end of these scopes, the curly brackets are used (`{}`). For example, the main function's start and end are shown by the open (`{`) and close (`}`) curly brackets.

```C++
int main()
{ // main starts here

} // main ends here
```

### Comments

Often when writing code it is useful to explain what is happening or provide documentation. Comments are a mechanism to do this in the same files as source code. C++ has two ways to write comments. Single line comments can be written with the `//` symbol. All of the text after this symbol on that line is considered a comment by the compiler and therefore ignored. These comments can be written on the same line as actual C++ statements (inline comments).

```C++
// this is a single line comment
```

```C++
1 + 1; // this is an inline comment
```

The other way to write comments is with the `/*` and `*/` symbols. These mark the beginning and end of a multi-line comment. These are more versatile in their use as the compiler knows exactly where the comment starts and ends.

```C++
/*
    this
    is
    a
    multi-line
    comment
*/
```

```C++
1 + 1; /* comment */ 2 + 2;
```

## Using `iostream`

### Includes

The `#include` command allows the inclusion of external (from this program) C++ **header** files. These files can be split into two main categories: the [standard library](https://en.cppreference.com/w/cpp/header) and user-defined header files. Perhaps the most commonly imported header file is `iostream` which provides basic **input** and **output** functionality.

```C++
# include <iostream>
```

### Namespaces

> Note: namespaces are covered in more detail in [05: Structures](../05_Strutures/structures.md).

Often when including header files, imported functions and objects are within a **namespace**. This means in order to use them, the namespace must be given before any identifiers. For example, to use `cout` as a part of `iostream`, the `std` namespace must be given. The `::` operator is used to denote a namespace.

```C++
# include <iostream>

int main() {
    std::cout << "A"; // std:: given before cout
}
```

Constantly writing the namespace before identifiers can often become unnecessary. To get around this issue, the `using` command can be used. This allows the programmer to define what namespaces or identifiers to use so they do not have to write them out later on. For example, if `iostream` was included and the user wishes to use `cout` without writing `std` before each command, they could instruct `using namespace std` so the entire standard namespace was available.

```C++
# include <iostream>
using namespace std; // all of namespace std used

int main() {
    cout << "B"; // std:: is no longer needed
}
```

It is not best practice to import entire namespaces when only a few functions are needed. In the previous example of `iostream`, only the `cout` identifier was needed. Therefore, it would be best to only import that part of the standard namespace.

```C++
# include <iostream>
using std::cout; // only std::cout is used

int main() {
    cout << "C";
}
```

### `cout` and `cin`

> Note: streams are covered more in depth in [20: Streams](../20_Streams/streams.md).

Finally, with `iostream` imported and its namespace available, the programmer can implement basic program input and output. `cout` is the standard output stream in C++. In other words, this "stream" object is the target for whenever the programmer wishes to output something (usually to a terminal). Data is output to `cout` using the `<<` operator. Values as well as variables can be used with `cout`. If the user wishes to move to the next line, they can use the `endl` command (as part of the standard namespace).

```C++
cout << "Hello" << endl; // endl is for a newline character
```

```C++
cout << number; // variables can be output to cout
```

`cin` is the standard input stream in C++. Whenever the user wishes to take user input from the terminal, they will most likely use `cin`. To extract data from standard input, the `>>` operator is used. The C++ program will wait for the user to enter data before continuing when there is a `cin` statement (they must also press enter).

```C++
cin >> number; // reads data from cin into variable number
```

## Language Components

For a more detailed look at the components of C++, refer to the [keywords](https://en.cppreference.com/w/cpp/keyword) and [operators](https://en.cppreference.com/w/cpp/language/operator_precedence) lists. The compiler goes through [several stages](https://en.cppreference.com/w/cpp/language/translation_phases) when attempting to generate machine code. This repository will not focus much on these specifics.

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./syntax.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language)
- [CPP](https://www.cplusplus.com/doc/)
