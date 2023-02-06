# Vectors

As arrays in C++ are not objects, they are somewhat limited in what can be done with them as is. Even though the programmer can write their own operations (functional or object-oriented) for arrays, it is useful to have a standard and easy to use built-in class. C++ has several aggregate data types, but the one that most closely mirrors Python-like arrays is the vector class.

## Basics

To use the vector class, it must first be included (and give any using statements).

```C++
# include <vector>
using std::vector;
```

Vectors are sequences of elements with a dynamic size. Vectors are templated, meaning a vector of any type can be made. Therefore, when making a vector a type must be specified.

```C++
vector<int> nums = {1, 2, 3};
```

With an instance of the vector class, a wide variety of member functions are now available. Some of these include `.push_back()`, `.erase()`, `.at()`, and `.size()`. As many of these operate the same as counterparts in Python (and the string class), they will not be discussed here.

```C++
nums.push_back(4);
```

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/container/vector)
- [CPP](https://cplusplus.com/reference/vector/vector/?kw=vector)