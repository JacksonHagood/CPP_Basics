# Flow Control

Flow control enables programmers to decide how a program executes according to data. In other words, data controls flow. There are two main types of flow control: simple branching and loops.

## Branch Statements

Like Python, C++ has mechanisms to branch programs depending on conditions. These enable the programmer to define behavior depending on data. In C++ this can be done with if statements or switch cases. Other branching statements, like `goto` are rarely used.

### If Statements

The most common way to branch is with **if statements**. These work very much like Python. The two parts of an if statement are the **condition** and the **body**. The condition is a boolean (or an expression that evaluates to a boolean) that controls whether the body will execute.

```C++
if (condition) {
    // executes if condition is true
}
```

Like Python, C++ supports else statements that will execute if the previous if statement(s) failed to. If statements can be nested and chained as the programmer wishes.

```C++
if (condition1) {
    // executes if condition 1 is true
} else if (condition2) {
    // executes if condition 1 is false and condition 2 is true
} else {
    // executes if condition 1 and condition 2 are both false
}
```

### Switch Statements

**Switch statements** are similar to if statements in that they execute code depending on conditions. Switch statements are best at executing one of many options depending on the value of a single value (each being a `case`). For example, determining what to output depending on the value of an integer. Each `case` must end with a `break` command (to exit the `switch`), otherwise the following cases will also be evaluated. A `default` case can be given for when no `break` has been executed previously.

```C++
switch(num) {
    case 0:
        // zero
        break;
    case 1:
        // one
        break;
    case 2:
        // two
        break;
    default:
        // not zero, one, or two
        break;
}
```

### Ternary Operator

The **ternary operator** is a special operator that works like an if-else statement. The operator uses a condition (ending with `?`) to execute one of two expressions (separated by `:`). The ternary operator provides a concise way to have in-line if statements.

```C++
// c is 'T' if condition is true, 'F' otherwise
char c = condition ? 'T' : 'F';
```

## Loops

> Note: iterators are not discussed here and are not within the scope of this repository.

C++ has three main mechanisms to loop according to a condition. These structures allow programmers to control how many times to execute code according to data. Two special commands can be used in all three loops: `continue` and `break`. The `continue` command can be used to skip to the next iteration in a loop. The `break` command will immediately exit the loop. Both commands only work on the inner-most loop at that time. like if statements, loops can be nested.

### While Loop

A **while loop** is the most primitive type of loop. Like if statements, the while loop has a **condition** and a **body**. The difference is that after the body is executed, the condition is checked again to determine whether the body will execute again. This is done repeatedly until the condition is false (or a `break` statement is encountered). It is important to realize that nothing prevents the programmer from writing an infinite loop (which will often not cause an error).

```C++
while (condition) {
    // executes once at a time with condition checked before each iteration
}
```

### Do While Loop

A **do while loop** works the same as a standard while loop except the condition is checked after the body (not before). This means the first iteration will execute regardless of the condition and only following iterations are dependent on it. For this reason, do while loops are not very common.

```C++
do {
    // executes once at a time with condition checked after each iteration
} while (condition);
```

### For Loop

A **for loop** is a useful way of shortening some while loops. The for loop has 4 parts: **initialization**, **condition**, **updation**, and the **body**. A for loop starts with the initialization step, typically where a variable is setup for controlling the loop. Then, the condition is what is used to control whether the body should be executed before each iteration (like while loops). Finally, the updation step is executed after each iteration (before the condition is checked).

```C++
for (/* initialization */; /* condition */; /* updation */) {
    // executes while condition is true
}
```

To illustrate for loops, the below while and for loops are equivalent in execution.

```C++
int i = 0;
while (i < 5) {
    cout << i;
    i++
}
```

```C++
for (int i = 0; i < 5; i++) {
    cout << i; 
}
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./flow_control.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/book/intro/control)
- [CPP](https://cplusplus.com/doc/tutorial/control/)
