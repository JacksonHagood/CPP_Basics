# Namespaces

As programs grow in complexity, encapsulation can be a useful tool. One method of accomplishing this is with namespaces. **Namespaces** allow the programmer to place items within an identifier.

## `namespace` Definition

Definitions can be given inside a namespace by providing an identifier. Then, inside that namespace's scope, all functions, variables, classes, and other structures are attached to that namespace. Namespaces can also be nested (meaning a namespace can be defined inside another namespace). The below example defines two functions and a type alias inside the `math` namespace. Notice that when inside the namespace, other items do not need the `math::` prefix.

```C++
namespace math {
    using integer = unsigned long int;

    integer power(integer a, integer b);
    integer factorial(integer a);
}
```

## Using Namespaces

To make use of the elements of a namespace, the namespace's identifier must be given. Following the previous example, to make use of the `math` namespace, the `math::` prefix must be given before each use.

```C++
math::integer num = 3;
math::factorial(num);
```

If the programmer wants to access the entirety of a namespace they can write a `using namespace` statement. It is best to avoid this with multiple namespaces, as if two namespaces have an item with the same identifier, errors can arise.

```C++
using namespace math;
```

Instead, the programmer should specify what functions to be used, decreasing the likelihood of conflicts.

```C++
using math::integer;
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./namespaces.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language/namespace)
- [CPP](https://cplusplus.com/doc/oldtutorial/namespaces/)
