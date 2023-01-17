# Streams

**Streams** are a somewhat unique to C++. They are objects primarily intended for input / output operations. They can be thought of as containers from which data can be input and output. There are several main stream classes, with three main categories: input stream, output streams, and input / output streams.

## Input Streams

**Input streams** are used to extract data from some source. For example, the input stream `cin` can be used to obtain user input. To extract data from input streams, use the `>>` operator. Input streams separate data by spaces. So, for example, if the user entered "hello there" in a terminal and read values into strings, the first string would take the value "hello" and the second would take "there".

```C++
// input: "hello there"
cin >> str1 >> str2; // str1 = "hello", str2 = "there"
```

### `getline()`

Often it is useful to obtain entire lines from an input stream (marked by the newline character `'\n'`). To do this, the `getline()` function can be used. `getline()` accepts two arguments: an input stream and a string. The function takes the next line from the input streams and stores it into the string variable. For example, if the programmer wanted to store a line of input from `cin` into `str`, they could use the following code.

```C++
getline(cin, str); // stores line of input from cin into str
```

### Flags

Streams have flags that can be used to determine several properties. For example, the `eof` flag will be set to `true` when the stream has reached the end of its input (called with `.eof()`). Perhaps the most used flag is `.fail()` which is set to true when the stream cannot read a value into a provided variable. For example, if the user enters "hello" and the stream tries to read this value into an integer.

```C++
int num;
cin >> num;

if (cin.fail()) {
    // .fail() returns true if stream failed to read into variable
    cout << "Failed to read integer";
}
```

## Output Streams

Output streams allow data to be output to some destination. For example, `cout` outputs data to the terminal. Output streams can output data using the `<<` operator. Output streams can work with a wide variety of data types and objects. This makes it very easy to output data instead of using something like `printf()`.

```C++
string str = "ABC";
int num = 123;

cout << str << ' ' << num;
```

### `endl`

**Output streams** are not necessarily output at the exact moment the programmer issues the command. Instead, buffers are used to perform these output operations when ideal. To get around this, the programmer can "flush" the stream. One way to do this is with `endl`, which will also add a newline character.

```C++
cout << endl;
```

## Input / Output Streams

**Input / output streams** combine the functionality of input and output streams.

## Stream Classes

All the different stream classes implement these three basic stream types, with the difference being where the input comes from or where the output goes. Otherwise, they work functionally identically.

### `iostream`

Perhaps the most used stream objects in C++ can be found in `iostream`. This library includes the standard output (`cout`) and input (`cin`) streams which interact with the terminal.

### `sstream`

**String streams** are a way of using input and output streams with string variable. For example, if the user had a string str and wanted to read in words from it one by one, they could construct a `stringstream` and read in values using it.

```C++
# include <sstream>
```

```C++
std::stringstream ss(str); // constructs stringstream with str
ss >> word1 >> word2; // reads in words from stringstream one at a time
```

### `fstream`

**File streams** are ways of inputting and outputting data with files. They work similarly to other streams but are constructed with file names.

```C++
# include <fstream>
```

```C++
ofstream output("file.txt"); // opens output file stream with file.txt
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./streams.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)
