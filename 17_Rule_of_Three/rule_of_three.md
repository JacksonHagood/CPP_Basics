# Rule of Three

> Note: The rule of five is an alternative that implements two more functions. The rule of three is covered here instead as it implements the base functionality.

One interesting result of the heap and object-oriented programming in C++ is the rule of three. The **rule of three** is a name for 3 functions that should be implemented when dealing with dynamic memory in a class. These three functions accomplish two things: avoids memory leaks and ensures a deep copy.

## Shallow Copy vs Deep Copy

To better understand why the rule of three is needed, it is important to understand what shallow and deep copies are. As an example, an integer is declared on the heap and is initialized to 1.

```C++
int* original = new int{1};
```

The programmer wishes to make a copy of this integer. There are two main ways to do this. First of all, they can make what is called a shallow copy. A **shallow copy** refers to a variable that points to the same variable or object as the original. This means that any changes made to the original will affect the copy, even after the copy is made. This is a result of both variables pointing to the same location in memory.

```C++
// shallow copy
int* shallowCopy = original;
```

To make a copy that is unaffected by changes to the original, the programmer should make a deep copy. A **deep copy** has its own memory that must be declared separate from the original. This means any changes to the original will not change the copy after it is made.

```C++
// deep copy
int* deepCopy = new int;
*deepCopy = *original;
```

With these two copies, if the original were changed to another value, the shallow copy would be changed but the deep copy would not. Another result of this is that both the original and the deep copy must be deleted, but the shallow copy does not (as deleting the original deletes it as well).

```C++
delete original;
delete deepCopy;
```

> Note: In practice, most of the time the programmer wants a "copy" they want a deep copy.

## Functions

To demonstrate each of the rule of three, a Byte class will be used. This class has a single variable that points to an unsigned char on the heap. This class must do two things: have a method to ensure deep copies and avoid memory leaks.

```C++
class Byte {
    private:
        unsigned char* value;

    public:
        // default constructor
        Byte(unsigned char VALUE) : value(new unsigned char{VALUE}) {}

        // getter and setter
        int getByte() { return *value; }
        void setByte(unsigned char VALUE) { *value = VALUE; }
};
```

The steps outlined for each function are mostly universal, but the specifics will differ. Still, the same general steps will be followed for almost every implementation of the rule of the three.

### Copy Constructor

The first function in the rule of three is the copy constructor. The **copy constructor**'s job is to construct a new instance of the object as a deep copy of another instance. There are two major steps to do this: allocate memory and copy values.

```C++
// copy constructor (ensure deep copy)
Byte(const Byte& original) : value() {
    // step 1: allocate memory
    this->value = new unsigned char;

    // step 2: copy values
    *(this->value) = *original.value;
}
```

### Copy Assignment Operator

The second function in the rule of three is the **copy assignment operator** which must avoid memory leaks and ensure deep copies. This function follows 5 main steps. First, the operator must avoid self assignment as this can cause unique errors. Second, the operator must deallocate memory to make room for its new value. Next, the code from the copy constructor can be used for steps 3 and 4. Finally, the copy assignment operator returns the reference to the object.

```C++
// copy assignment operator
Byte& operator=(const Byte& original) {
    // step 1: self assignment check
    if (this != &original) {
        // step 2: deallocate memory
        delete this->value;

        // step 3: allocate memory
        this->value = new unsigned char;

        // step 4: copy values
        *(this->value) = *original.value;
    }

    // step 5: return self
    return *this;
}
```

### Destructor

The final part of the rule of three is the destructor. The **destructor** is a special function that is called once an object is out of scope or the `delete` keyword is used. This function must therefore deallocate all of the dynamic memory associated with the object. It follows two simple steps: deallocate memory and handling dangling pointers.

```C++
// destructor
~Byte() {
    // step 1: deallocate memory
    delete this->value;

    // step 2: handle dangling pointers
    this->value = nullptr;
}
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./rule_of_three.exe`
- cleanup: `make clean`

## References

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)
