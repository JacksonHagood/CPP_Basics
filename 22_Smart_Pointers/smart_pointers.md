# Smart Pointers

Though dynamic memory management is an important skill, it is often useful to use pre-written objects to manage it automatically. C++ offers a few classes that allows dynamically allocated objects to be automatically deallocated.

## Unique Pointers

The `memory` header file provides two main pointer classes. The first of these is the `unique_ptr` templated this class. To create a `unique_ptr` object, a type must be given for what is being pointed to. Then, a constructor can be used to initialize the pointer to an address on the heap.

```C++
std::unique_ptr<int> ptr(new int(3));
```

Now, the unique ptr can be used to interact with the value on the heap. To get the value the dereference (`*`) operator can be used like with standard pointers. To get the memory address, the `.get()` function can be used.

```C++
*ptr; // gets value
ptr.get(); // gets memory address
```

The `unique_ptr` object will automatically delete the memory on the heap once it goes out of scope.

```C++
{
    std::unique_ptr<int> ptr(new int(3));
    // memory on heap is automatically deallocated when unique_ptr is out of scope
}
```

## Shared Pointers

One shortcoming of `unique_ptr` is that only a single `unique_ptr` can manage each address at a time. An alternative is a `shared_ptr`, which will only deallocate the memory when the final `shared_ptr` is out of scope.

```C++
std::shared_ptr<int> ptr1;

{
    std::shared_ptr<int> ptr2(new int(3));
    ptr1 = ptr2;

    // memory on heap is not deallocated as another shared pointer is still in scope
}

// memory on heap is automatically deallocated as the final shared pointer is out of scope
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./smart_pointers.exe`
- cleanup: `make clean`

## Sources and Further Material

- [CPP Reference](https://en.cppreference.com/w/cpp/header/memory)
