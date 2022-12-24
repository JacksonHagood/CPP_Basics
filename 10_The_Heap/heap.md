# Heap

## Sections of Memory

The **stack** and **heap** are regions of memory in a C++ program. The stack is memory that is managed by the compiler (done automatically), while the heap is memory managed explicitly by the programmer. Alternatively, the stack is for **"static"** memory while the heap is for **"dynamic"** memory. The stack and heap grow towards one another from opposite ends of a continuous section of memory. Static variables and the program's code are stored in other areas of memory separate from the stack and heap.

### Stack Region

When starting out, most of the variables made by C++ programmers are made on the stack. A variable is made on the stack by giving a type and a variable name (an initial value can optionally be given). Though the programmer does state when the variable should be "made" (memory is allocated), the programmer does not state when the variable should be "destroyed" (memory is deallocated). Instead, variables on the stack are automatically deleted once out of scope. For example, if a variable were created on the stack within the body of the if statement, it would be destroyed once the body of the if statement ends.

```C++
if (true) {
    int num = 1; // integer on the stack

    /* num exists */
}

/* num does not exist */
```

### Heap Region

While it is useful for variables on the stack to be automatically managed by the compiler, this limits what the programmer can do. The alternative is the heap, where the programmer has more freedom, but also more responsibility. To create a variable on the heap, the **new** keyword must be used. This will allocate memory for a provided type on the heap and return the memory address (an initial value can also be given). To use the memory on the heap, this memory address must be stored in a pointer variable. This pointer variable can then be used to manipulate and access the memory on the heap using the dereference operator. It is important to realize that the pointer variable itself is located on the stack, while the memory it points to is on the heap.

```C++
int* ptr = new int{1}; // allocate integer on the heap (and integer pointer on the stack)
```

At some point, the programmer should deallocate the memory on the heap. This is done using the **delete** keyword (**delete[]** for arrays). This will deallocate the memory a pointer variable references. It is important that this is done before every reference to that variable is lost (the pointer(s) on the stack are deallocated by the compiler). If every reference to a location on the heap is lost before it is deallocated there is a **memory leak**. It is also good practice to set pointers to deallocated memory to **nullptr**. This is done to avoid a **dangling pointer**.

```C++
delete ptr; // deallocate integer on the heap (pointed to by ptr)
ptr = nullptr; // avoid dangling pointer
```

## Example Program

An example program is provided to demonstrate some of these concepts

### Usage
- compile: `make`
- run: `./heap`
- cleanup: `make clean`

## References

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)