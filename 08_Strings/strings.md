# Strings

Lists of characters, or **strings**, are a very common data type in programming. C++ has two main ways of handling strings: C-style strings (or "c-strings") and C++ style strings. C++ strings are typically easier to use, but C-strings are used by many C functions and system calls. 

## Characters

Before diving into strings, it is important to understand how characters are stored in C++. **Characters** in C++ are 1 byte integers implicitly representing characters in ASCII. **ASCII** is a standard for storing characters as a numerical value. A chart of ASCII values can be found [here](https://en.cppreference.com/w/cpp/language/ascii). Character values can be given as an integer or the character itself in single quotes (`'`).

```C++
char a = 97; // 97 is 'a' in ASCII
```

```C++
char a = 'a';
```

### Special Characters

C++ has several special characters to support unique situations. For example, to move to a newline, character `'\n'` can be used. Below is a table of some of these characters.

| char   | name         |
| ------ | ------------ |
| `'\0'` | null         |
| `'\n'` | newline      |
| `'\t'` | tab          |
| `'\''` | single quote |
| `'\"'` | double quote |
| `'\\'` | backslash    |


## C-strings

**C-strings** are a built-in method of defining strings in C as an array of characters. As arrays in C++ do not have an automatic size property, the end of a C-string is denoted by a null character (`\0`). The end of the C-string is not necessarily the end of the array, but it can never exceed it. For example, the below c-string stores `"Hello"` in the first 5 indexes. The end of the c-string is then indicated by the null character in index 5. The last 4 indexes are therefore not part of the c-string, as they are part of the null character. This can be demonstrated by outputting the c-string which does not show any of the characters after `"Hello"`.

```C++
char array[10] = {'H', 'e', 'l', 'l', 'o', '\0', '-', '-', '-', '-'};
cout << array; // outputs "Hello"
```

Interestingly, when outputting the character array, C++ outputs the c-string instead of the address of the array (which would happen when outputting an array of any other type). This is because support for c-strings is built into the language itself. Even with this support, however, there is little that can be done with c-strings with plain C++. To do things like concatenate c-strings, the programmer must write their own functions or use a library. One built-in library is `string.h`. `string.h` provides functions such as `strcpy()`, `strlen()`, and `strcmp()` to help the use of c-strings.

```C++
# include <string.h>
```

```C++
int size = strlen(array); // gets the size of c-string array
```

## C++ Strings

> Note: object-oriented programming is covered in Section 13: Classes.

C++ strings are objects that most closely mirror strings in Python. Unlike c-strings, the programmer is no longer in charge of maintaining the actual character array, and can instead use several member functions. For example, to get the size of a string, one could use the `.size()` functions. As strings are objects, to use their member functions are used by giving the variable name followed by `.` and the function call. To use C++ style strings, they must first be included.

```C++
# include <string>
```

```C++
string str = "Hello";
str.size(); // gets the size of str1
```

### String Access

There are several functions available to the programmer to access parts of a string. To get the character at a position in a string, either the `.at()` function or the `[]` operator can be used. The major difference between these two methods is the `.at()` function has bounds checking (can throw exceptions) and the `[]` operator does not (can cause runtime errors). This typically makes the `.at()` function the better, if less efficient, choice.

```C++
str.at(1) // gets character at index 1
```

```C++
str[1] // gets character at index 1
```

To get the first and last characters in a string, the `.front()` and `.back()` functions can be used. Finally, to get a sequence of characters within the string, the `.substr()` function can be called with a starting position and the number of characters to obtain.

```C++
str.front(); // gets first character
str.back(); // gets last character
str.substr(1, 3); // gets substring in range [1, 4)
```

An often useful function when dealing with strings is `.find()`. `.find()` can be used to search for the first occurence of a given string. If no such string is found, the function will return the constant `string::npos`.

```C++

str.find("ello"); // returns 1
str.find("goodbye"); // returns 18446744073709551615 (string::npos)
```

### String Modification

C++ strings also have several ways to modify string values. First of all, concatenation is possible using the `+` operator with strings. The `+=` operator can also be used to add to the end of an already existing string (`.append()` can also be used).

```C++
string str3 = str1 + str2; // concatenates str1 and str2
```

To manipulate and change different parts of a string, functions like `.insert()`, `.push_front()`, `.push_back()`, `.erase()`, and `.resize()` can be used.

```C++
str.push_back('!'); // adds '!' to end
str.erase(2, 3); // erases 3 characters starting at index 2
str.insert(2, "y"); // inserts "y" at index 2
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./strings.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)
