# Namespaces

Something often used with object-oriented programming in C++ is namespaces. **Namespaces** allow the programmer to place functions, variables, classes, and other items within an identifier. These allow encapsulation when programming and allow for better organization.

## `namespace`

To place definitions inside a namespace, simply give the namespace identifier. The below example defined two functions and an alias inside the `math` namespace.

```C++
namespace math {
    using integer = unsigned long int;

    integer power(integer a, integer b);
    integer factorial(integer a);
}
```

Now, to use something inside this namespace in a function outside it (like main) the `math::` prefix must be included. As with `iostream`, `using` statements can also be used.

```C++
math::integer num = 3;
math::factorial(num);
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./classes.exe`
- cleanup: `make clean`

## References

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)
