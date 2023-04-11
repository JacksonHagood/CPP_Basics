# Class Templates

Like functions, classes can be templated in C++. This allows for a class definition, that is written once, to be compatible with multiple types. One commonly used example is the `vector` class.

## Example

To create a templated class, add a template statement directly before the class definition. As an example, say the programmer wants to make a `Pair` class that stores two items of any two types. They could do so with a template. Notice how multiple member variables, functions, and parameters make use of this template within the class.

```C++
template <typename T, typename U>
class Pair {
    private:
        T left;
        U right;
    
    public:
        // constructor
        Pair(T LEFT, U RIGHT) : left(LEFT), right(RIGHT) {}

        // getter / setter functions
        T getLeft() const { return left; }
        U getRight() const { return right; }
        void setLeft(const T LEFT) { left = LEFT; }
        void setRight(const U RIGHT) { right = RIGHT; }
};
```

To make an instance of this class, the programmer must specify the types of `T` and `U`. They can do so with `<>`. For example, to make a pair of `int` and `float`, the programmer can specify it as follows.

```C++
Pair<int, float> p1(5, 6.0);
p1.getLeft(); // returns int
p1.getRight(); // returns float
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./class_templates.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language/class_template)
- [CPP](https://cplusplus.com/doc/oldtutorial/templates/)
