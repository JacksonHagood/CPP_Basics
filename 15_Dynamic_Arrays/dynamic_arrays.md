# Dynamic Arrays

One interesting use for the heap section of memory is dynamic arrays. A **dynamic array** is an array that can be resized after declaration. This ability allows a greater range for what the programmer can do.

## Arrays on the Stack

Up to this point arrays have been declared on the stack. This results in arrays that cannot be resized once declared (static). The reason for this is due to how memory is allocated. Arrays are contiguous sections in memory (meaning each index is located directly next to the others in memory). This means that if the compiler allocates memory after the array for another purpose, it is no longer possible to give it to the array. Therefore, it is not feasible to resize arrays on the stack.

## Arrays on the Heap

To get around the issue of static arrays, the heap can be used. Recall that on the heap the programmer is in charge of when memory is allocated and deallocated. Also, remember that arrays are actually pointers. Therefore, programmers can use the heap to manually allocate memory for new arrays and change array pointers accordingly. This process involves four main steps that must be in the correct order. As an example, a programmer wants to resize an array of three integers to have room for a fourth (notice this array is on the heap).

```C++
// original array (on the heap)
int* array = new int[3]{0, 1, 2};
```

First, the programmer must allocate memory for the new array (with whatever size the programmer wants). This involves a second pointer variable.

```C++
// step 1: allocate memory for new array (on the heap)
int* newArray = new int[4];
```

Next, the programmer needs to copy the values from the old array to the new array.

```C++
// step 2: copy values from old array to new array
for (unsigned int i = 0; i < 3; i++) {
    newArray[i] = array[i];
}
```

Now, to avoid memory leaks, the programmer should deallocate the memory taken by the old array (using `delete[]`).

```C++
// step 3: deallocate memory of old array
delete[] array;
```

Finally, the programmer can point the original array pointer to point to the new array.

```C++
// step 4: update array pointer to new array
array = newArray;
```

Now, the programmer has successfully "resized" the array so that the array pointer variable points to an array with one more index. In reality, no actual array has been resized. Instead, the array pointer has been changed to point to a larger section of memory. This creates the illusion that the array has been resized, but the memory addresses are different.

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./dynamic_arrays.exe`
- cleanup: `make clean`

## References

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)
