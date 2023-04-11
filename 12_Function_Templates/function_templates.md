# Templates

**Templates** allow for generic types to be given for function and class definitions. This allows for these definitions to work for any compatible type instead of just a single one.

## Function Templates

A function can be defined using templates. This makes the function executable independent from a specific type. To specify a function using a template, a `template` command must be given directly before the function prototype. As an example, say the programmer wants to define an `isEqual()` function to work with any type that has a `==` operator definition. They would first define a template for type-name `T` and then use this `T` type in the function.

```C++
template <typename T> // "T" is a generic type
bool isEqual(T a, T b) {
    return a == b;
}
```

This function can now be used like any other function, but it can be called with variables of any type (though they must be the same type). This is determined at compile-time. For example, if `isEqual()` were called with two integers, type `T` would be filled as `int`.

```C++
isEqual(5, -5); // calls isEqual() with "T" defined as int
```

### `auto`

Functions can have multiple type-names. For example, a sum function could be defined with two parameters of any (independent) generic type. Parameter `a` is given as type `A` and parameter `b` is given as type `B`. As the return type depends on what types `A` and `B` are, the `auto` keyword is used to determine the return type (during compile-time).

```C++
template <typename A, typename B> // "A" and "B" are generic types
auto sum(A a, B b) {
    return a + b;
}
```

For example, if an integer and float were passed to `sum()`, type `A` would be filled as `int` and type `B` would be filled as `float`. The return type would automatically be determined as a `float` (as an integer added with a float gives a float).

```C++
// calls sum() with "A" defined as int and "B" defined as float
sum(num1, num2);
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./templates.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language/templates)
- [CPP](https://cplusplus.com/doc/oldtutorial/templates/)
