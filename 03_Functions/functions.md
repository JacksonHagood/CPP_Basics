# Functions

Often when programming, it is useful to re-use sections of code and assign names to them. **Functions** are a mechanism that allows for this within C++. As expected, they work similiarly to functions in Python, but with some key differences.

## Function Signature

A function's **signature** is comprised of the function's name, type, and parameters (not the actual body of the function). Function's in C++ have an associated type which denotes what data type the function returns. If the programmer wishes to write a function without a returned value, they can make it `void` (can still have a `return` statement, just without a value).

```C++
int foo() {
    return 0; // returned value must match function type
}
```

```C++
void hello_world() {
    cout << "Hello, World!\n";
}
```

## Parameters

Function's in C++ can have **parameters** each containing a name and a type. These parameters comprise the input(s) of the function and can be provided in multiple ways. There are three ways parameters can be passed into functions: pass by value, pass by reference, and pass by pointer.

### Pass by Value

The most common way of passing parameters into functions is through **pass by value**. Here, when using the parameter inside the function, any operations on that variable do not persist or change the original variable used when calling the function. Instead, operations are done on a copy that is made when the function begins.

```C++
void foo(int num) {
    num = 1; // changes only num, which is a copy of original
}

int main() {
    int original = 0;
    foo(original);
    // original is still 0
}
```

### Pass by Reference

**Pass by reference** is a way of providing parameters so that operations on the parameters affect the original variables used to call the function. In other words, the paramter variable is just another name for the same variable that was used outside the function (not a copy). To pass a variable by reference, add `&` after the type.

```C++
void foo(int& num) {
    num = 1; // operations on num change both
}

int main() {
    int original = 0;
    foo(original);
    // original is now 1
}
```

### Pass by Pointer

> Note: pass by pointer is discussed more in Section 09: Pointers.

A final way to pass parameters is with **pass by pointer**. Pass by pointer is really just a special case of pass by value that leverages how pointers work to change a specific location in memory. In practice, this will produce the same results as pass by reference, but it does require the data type to be changed to a pointer. A side effect of arrays being pointers is that arrays are always passed by pointer (functions will change the original arrays).

```C++
void foo(int* ptr) {
    *ptr = 1; // operations on the memory address of original
}

int main() {
    int original = 0;
    foo(&original);
    // original is now 1
}
```

## Function Pointers

TODO
