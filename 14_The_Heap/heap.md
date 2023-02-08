# The Heap

## Sections of Memory

The **stack** and **heap** are regions of memory in a C++ program. The stack is memory that is managed by the compiler (done automatically), while the heap is memory managed explicitly by the programmer. Alternatively, the stack is for **"static"** memory while the heap is for **"dynamic"** memory. The stack and heap grow towards one another from opposite ends of a continuous section of memory. Static variables and the program's code are stored in other areas of memory separate from the stack and heap.

### Stack Region

Up to this point in this guide, all variables have been made on the stack. This means they occupy a region of memory that is automatically managed by the compiler (static memory). In other words, the programmer does not explicitly create (allocate) and destroy (deallocate) memory, instead they declare variables which are automatically deleted once out of scope. For example, if a variable were created on the stack within the body of the if statement, it would be destroyed once the body of the if statement ends.

```C++
if (true) {
    int num = 1; // integer on the stack

    // num is within scope
}

// num out of scope (is deallocated)
```

### Heap Region

While it is often useful for variables on the stack to be automatically managed by the compiler, this limits what the programmer can do. An alternative way of allocating variables is with the heap. Here the programmer has more freedom, but also more responsibility. To create a variable on the heap, the `new` keyword must be used. This will allocate memory for a provided type on the heap and return the memory address (an initial value can also be given). To use the memory on the heap, this memory address must be stored in a pointer variable. This pointer variable can then be used to manipulate and access the memory on the heap using the dereference operator. It is important to realize that the pointer variable itself is located on the stack, while the memory it points to is on the heap.

```C++
int* ptr = new int{1}; // allocate integer on the heap (and integer pointer on the stack)
```

At some point, the programmer should deallocate the memory on the heap (as this is not done automatically). This is done using the `delete` keyword (`delete[]` for arrays). This will deallocate the memory a pointer variable references. It is important that this is done before every reference to that variable is lost (all the corresponding pointer(s) on the stack are deallocated by the compiler). If every reference to a location on the heap is lost before it is deallocated there is a **memory leak**. It is also good practice to set pointers to deallocated memory to **nullptr**. This is done to avoid a **dangling pointer**.

```C++
delete ptr; // deallocate integer on the heap (pointed to by ptr)
ptr = nullptr; // avoid dangling pointer (best practice)
```

## Memory Leaks

If memory is allocated on the heap but never deallocated, then there is a memory leak. Memory leaks are somewhere between a runtime error and a logical error as they do not stop the execution of a program, but cause problems with memory management. When there is a memory leak, the memory that was not deallocated cannot be allocated again and this can cause a variety of issues. As they do not cause an explicit error, the compiler will not alert the programmer of memory leaks. Instead, if they want to be notified of when a memory leak occurs, they must compile with a memory checker. One example of this is fsanitize.

```
-fsanitize=address,undefined
```

With this compile flag, a memory leak will cause error messages like this to appear.

```
==263==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    ...

SUMMARY: AddressSanitizer: 4 byte(s) leaked in 1 allocation(s).
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./heap.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/language/new)
- [CPP](https://cplusplus.com/reference/new/)
