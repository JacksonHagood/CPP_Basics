# C++ Structures

As programs grow in complexity, encapsulation can be a useful tool. Outside of functions and OOP, C++ supports several structures to achieve encapsulation. Three of these such structures are namespaces, enumerations, and unions.

## Namespaces

**Namespaces** allow the programmer to place items within an identifier. This identifier is then used when using components within that namespace. This allows for items to be clearly defined within a structure for organization.

### `namespace`

Definitions can be given inside a namespace by providing an identifier. Then, inside that namespace's scope, all functions, variables, classes, and other structures are attached to that namespace. Namespaces can also be nested (meaning a namespace can be defined inside another namespace). The below example defines two functions and a type alias inside the `math` namespace. Notice that when inside the namespace, other items do not need the `math::` prefix.

```C++
namespace math {
    using integer = unsigned long int;

    integer power(integer a, integer b);
    integer factorial(integer a);
}
```

### Using Namespaces

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

## Enumerations

One way of defining types is with `enum`. **Enumerations** allow the programmer to define a typename that can have one of a list of possible values. These values are given by enumerated identifiers (these are not variables, but possible values).

### `enum`

As an example, if the programmer wanted to define a `Color` type with six possible values, they could use `enum`. They simply give the typename, followed by a list of the possible values. In reality, these values are mapped to an underlying type to represent them. By default, this type is `int`. This means, each of these possible values can be mapped directly to an integer value. These values are assigned automatically starting at 0 (the programmer can specify values if they wish with `=`).

```C++
enum Color {
    red, // integer value 0
    orange, // integer value 1
    green,
    cyan,
    blue,
    magenta // itneger value 5
};
```

The programmer can now use this enumerated type as they wish. For example, they could write an `isPrimary()` functions like below. Notice how the enumerated values are given within the `Color` namespace. Depending on the context, this may not be necessary.

```C++
bool isPrimary(Color c) {
    return c == Color::red || c == Color::green || c == Color::blue;
}
```

This function can now be called with variables of type `Color`. Furthermore, as the underlying type of `Color` is still an `int`, a variable of type `int` can be used with a simple type casting statement.

```C++
Color c1 = Color::red;
isPrimary(c1)
```

```C++
int c2 = 1;
isPrimary((Color) c2) // casts 1 to Color::orange
```

## Unions

A somewhat obscure structure in C++ is `union`. **Unions** allow the programmer to create multiple identifiers within the same location in memory. Unlike `structs`, all of these components occupy the exact same memory address (not next to, but on top of).

### `union`

Defining a `union` is similar to a `struct`. Simply give the typename and list the different fields of the `union`. For example, a union containing the four main integer sizes could be defined as follows. As the `int64_t` field takes up the most memory, that will determine the size in memory of the `union`.

```C++
union Integer {
    int8_t charValue;
    int16_t shortValue;
    int32_t intValue;
    int64_t longValue; // union will be 8 bytes
};
```

Now, a variable of type `Integer` could be defined. Changing one field of this variable will change all the other fields as well (as they all occupy the same memory). Accessing types of smaller sizes will simply change that portion of the memory.

```C++
Integer num;
num.shortValue = INT16_MAX; // writes to the first 2 bytes of memory
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./structures.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language/namespace)
- [CPP](https://cplusplus.com/doc/oldtutorial/namespaces/)
