# Testing

An crucial part of software engineering is the concept of testing. Being able to verify that a program works is just as important as being able to write the program itself.

## Test-driven Development

**Test driven development** is a way of writing software by considering test cases first. This helps mitigate situations where test cases arise during testing that were not considered when the program was written. For example, if one were to write a function `divide` to compute a number `a` divided by a number `b` they would want to first consider a variety of inputs and what their outputs should be. When writing these test cases, it is important to consider how they differ. For example, `2 / 4` and `1 / 2` are not fundamentally different from how they will likely be computed.

| input `a`  | input `b`  | output `a / b` |
| ---------- | ---------- | -------------- |
| `1`        | `2`        | `0.5`          |
| `-1`       | `2`        | `-0.5`         |
| `1`        | `-2`       | `-0.5`         |
| `2`        | `1`        | `2`            |
| `-2`       | `1`        | `-2`           |
| `2`        | `-1`       | `-2`           |
| `1`        | `0`        | exception      |
| `-1`       | `0`        | exception      |

With the above test cases in mind, the `division()` function could then be written.

## Types of Testing

As software increases in complexity, it becomes important to differentiate between types of tests. The two main categories considered here are unit testing and integration testing.

### Unit Testing

**Unit testing** is the practice of testing separate functions or sections of code, rather than the entire program. For example, if a `main` function calls function `A()` which calls function `B()`, the functionality of `A()` and `B()` can be confirmed with unit tests. A problem arises in that `A()` requires `B()` to work and therefore cannot be tested without `B()`. To get around this, **mock** functions are often used so that `A()` can be tested alone. Unit testing allows the programmer to verify and debug parts of their program instead of always debugging the program as a whole (which is far more difficult).

### Integration Testing

Though unit testing is useful, it alone cannot confirm the functionality of a program. **Integration testing** tests how units work with one another. Using the previous example, function `A()` can now be tested along with the real function `B()` and observe the outputs. Integration testing is typically done after unit testing to observe how units of code interact with one another.

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./testing.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)
