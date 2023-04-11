# Lambdas

**Lambdas** are a method of defining functions like variables. They are similiar to function pointers in practice, but mirror the behavior of variables even more closely. They represent a major component of modern functional programming.

## Example

Say the programmer wants to write a function `countEqual()` that finds the number of values in an array that are equivalent to a provided value. The programmer wants this function to work for any equivalence relation. One way to accomplish this is with lambda expressions. The function can accept a templated expression `equality` that will represent whatever the equivalence relation is.

```C++
template <typename T, typename F>
unsigned int countEqual(T array[], unsigned int size, T value, F equality) {
    unsigned int count = 0;

    for (unsigned int i = 0; i < size; i++) {
        if (equality(value, array[i])) {
            count++;
        }
    }

    return count;
}
```

Now, to use this function, the programmer must first define the equivalence relation they want. If they simply want to see if two integers are equal, they could define the below lambda expression (the `auto` keyword is used to more easily define the type). The `[]` specify what should be captured. In this case, this expression depends only on the two parameters (`lhs` and `rhs`), so the `[]` are left empty. The expression is then given in the `{}`, including a `return` statement. Now, assuming `array`, `size`, and `value` variables, the `countEqual()` function can be called with this lambda expression.

```C++
auto equals = [](unsigned int lhs, unsigned int rhs) { return lhs == rhs; };
```

```C++
countEqual(array, size, value, equals); // counts the number of elements in the array that are equivalent to value
```

Another example of an equivalence relation is [congruence mod m](https://en.wikipedia.org/wiki/Modular_arithmetic). The programmer can define this relation with a modular base (`m`) and a lambda expression. Since the expression relies on the (in scope) variable `m`, it must be **caputed** in the `[]` to be accessible within the lambda. It would also be possible to capture this by reference using `&m`. Furthermore, `=` can be used to capture all variables by value, and `&` alone can capture all variables by reference.

```C++
unsigned int m = 3;
auto congruent = [m](unsigned int lhs, unsigned int rhs) { return lhs % m == rhs % m; };
```

```C++
countEqual(array, size, value, congruent); // counts the number of elements in the array that are congruent (mod m) to value
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./lambdas.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language/lambda)
