# Exceptions

**Exceptions** are useful tools for avoiding errors in C++ while handling special situations. Essentially, by replacing errors with exceptions, the program can recover from potential issues instead of encountering a runtime error which stops execution. This is because exceptions that are "thrown" can be "caught" and handled accordingly.

## Throwing Exceptions

Exceptions are typically thrown when a function or section of code encounters input that will cause a runtime error or is invalid for some usage. Issues such as this must first be detected by the program (typically with an if statement). When such an issue is detected, an exception can then be **thrown**. Throwing an exception is done with the `throw` command followed by the exception type and a description of what occurred.

```C++
throw std::invalid_argument("Integer is zero");
```

If a thrown exception is never handled, it becomes a runtime error. The runtime error will display the exception type and the description. For example, if the previous exception was not handled, the below error would occur.

```
terminate called after throwing an instance of 'std::invalid_argument'
  what():  Integer is zero
Aborted (core dumped)
```

## Handling Exceptions

To prevent exceptions from becoming runtime errors, they must be handled. If the programmer suspects a function or section of code might thrown an exception, they can place it inside a **try-catch** block. A try-catch block is a way of containing code that can cause an exception and specifying what should happen if that exception occurs. The body of the `try` block contains the code that may cause an exception. Then, the `catch` block accepts an exception type (`...` if the programmer wishes to handle all exceptions) and its body executes if that exception occurs. For example, if a function `foo()` was suspected to throw an exception, it would be placed inside the `try` block with a `catch` block stating what should happen if an exception is thrown. An important observation is that if part of the `try` body causes an exception, the rest of the `try` body will fail to execute.

```C++
try {
    foo();
} catch(...) {
    cout << "Exception Occurred"; // executes if foo() throws exception
}
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./exceptions.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language/exceptions)
- [CPP](https://cplusplus.com/doc/oldtutorial/exceptions/)
