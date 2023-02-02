# Object-oriented Programming

As programs grow in complexity, additional layers of abstraction can be useful. One way to consolidate programs into manageable units is using object-oriented programming. What is important to realize is that object-oriented programming, unlike more primitive components (like variables and flow control), is not central to solving any problem. Object-oriented programming is only a tool, and there can be detrimental ways to use this tool. Furthermore, any problem can be solved without object-oriented programming. Programmers should learn object-oriented programming and grow comfortable with it, but it is counter-productive to become so reliant on it that one cannot program without it.

## Structs

Structs are the most primitive way of implementing object-oriented programming. While they can be used to the same extent as classes, they are most often used to just combine multiple data fields into a single structure. For example, if the programmer wanted a container to store the information of a person, they could define the following struct.

```C++
struct Person {
    string name;
    int age;
};
```

Notice how each component of the struct is indicated with a type and identifier. The programmer can now declare instances of this person struct. To obtain the component, they simply type the instance's identifier followed by the identifier of what they want. By default, each element in a struct is public and structs can also have member functions. These functionalities are best explained with classes.

## Classes

The single most important addition C++ adds to the C programming language is **classes**, the main method of object-oriented programming. Classes are containers for the programmer to consolidate data in the same place as operations on that data. These **objects** are useful as they allow the programmer to make instances that call these operations, reducing the complexity of many programs. An example class for addresses is given below.

```C++
class Address {
    private:
        // private components: member variables
        string name;
        string line_one;
        string line_two;
        string city;
        string state;
        int zip_code;
        string country;

    public:
        // public components: member functions

        // constructors
        Address();
        Address(const string NAME, const string LINE_ONE, const string LINE_TWO, const string CITY, const string STATE, const int ZIP_CODE, const string COUNTRY);

        // getter functions
        string getName() const;
        string getLineOne() const;
        string getLineTwo() const;
        string getCity() const;
        string getState() const;
        int getZipCode() const;
        string getCountry() const;

        // setter functions
        void setName(const string NAME);
        void setLineOne(const string LINE_ONE);
        void setLineTwo(const string LINE_TWO);
        void setCity(const string CITY);
        void setState(const string STATE);
        void setZipCode(const int ZIP_CODE);
        void setCountry(const string COUNTRY);

        // other functions / operations
        string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Address& in);
};
```

Each component of a class needs an **access specifier**. These tell the compiler whether or not the component can be accessed from outside the class. A `private` component can only be accessed from within the class and a `public` component can be accessed anywhere. Typically, **member variables** are `private` and **member functions** are `public` (there are exceptions). In this class, there are 7 member variables, each denoted by a type and identifier. The definitions of the member functions are often given in `.cpp` files separate from the `.h` file.

### Constructors

This class has four main categories of functions. First, there are two constructors. **Constructors** are used when declaring objects to give them some initial value. This class has a **default constructor** and a **parameterized constructor**. Both functions use a **member initialization list** to quickly initialize each of the member variables. 

```C++
// default constructor
Address::Address() :
    name(""),
    line_one(""),
    line_two(""),
    city(""),
    state(""),
    zip_code(-1),
    country("")
{
    cout << "Address constructed\n";
}
```

```C++
// parameterized constructor
Address::Address(const string NAME, const string LINE_ONE, const string LINE_TWO, const string CITY, const string STATE, const int ZIP_CODE, const string COUNTRY) :
    name(NAME),
    line_one(LINE_ONE),
    line_two(LINE_TWO),
    city(CITY),
    state(STATE),
    zip_code(ZIP_CODE),
    country(COUNTRY)
{
    cout << name << "'s address constructed\n";
}
```

The appropriate constructor is called depending on how the programmer declares an object.

```C++
// default constructor call
Address addr1();
```

```C++
// parameterized constructor call
Address addr2("Administration Building", "400 Bizzell St", "", "College Station", "TX", 77843, "USA");
```

### Getters & Setters

The next categories of member functions are the **getters** and **setters** these are typically one line functions used to obtain and set the value of member variables (as they are private and cannot be directly accessed). Notice that the getter functions have the `const` keyword after the function identifier and parameters. This makes what is know as a constant member function. **Constant member functions** are member functions that do not change any of the member variables in a class. For example, it would be a compile-time error to change the `name` member variable in the `getName()` member function as it is `const`.

```C++
// getter functions
string Address::getName() const { return name; }
string Address::getLineOne() const{ return line_one; }
string Address::getLineTwo() const { return line_two; }
string Address::getCity() const { return city; }
string Address::getState() const { return state; }
int Address::getZipCode() const { return zip_code; }
string Address::getCountry() const { return country; }
```

```C++
// setter functions
void Address::setName(const string NAME) { name = NAME; }
void Address::setLineOne(const string LINE_ONE) { line_one = LINE_ONE; }
void Address::setLineTwo(const string LINE_TWO) { line_two = LINE_TWO; }
void Address::setCity(const string CITY) { city = CITY; }
void Address::setState(const string STATE) { state = STATE; }
void Address::setZipCode(const int ZIP_CODE) { zip_code = ZIP_CODE; }
void Address::setCountry(const string COUNTRY) { country = COUNTRY; }
```

### Other Functions

Finally, there is one more function that falls under the category of miscellaneous operations specific to that class. In this example, a `toString()` function is given to return the object's representation as a string.

```C++
// other functions / operations
string Address::toString() const {
    return name + '\n' + line_one + '\n' + (line_two == "" ? "" : line_two + '\n') + city + ", " + state + '\n' + std::to_string(zip_code) + '\n' + country + '\n';
}
```

All of these functions (outside of the constructors) can be called by giving the identifier of an instance along with the function name.

```C++
addr1.setName("Jackson Hagood");
cout << addr1.getName();
```

### Operator Overloading

A special category of "functions" are operators. As the programmer is defining their own class, they can also define how certain operators behave with their new objects. This is called **operator overloading** and is a form of **polymorphism**. Operators appear just like functions (they accept arguments and return a value). The difference is their name specifies what operator this definition is for. In this example, the programmer is defining how the `<<` operator should work given an output stream and an address (`cout << addr1`). Notice that in the class definition this function is declared as a `friend`. **Friends** are functions that technically exist outside of the class, but have access to all the private members of the class. In this example, the `<<` operator definition has access to the address parameter's private member variables.

```C++
std::ostream& operator<<(std::ostream& os, const Address& in) {
    os << in.name << '\n' << in.line_one << '\n' << (in.line_two == "" ? "" : in.line_two + '\n') << in.city << ", " << in.state << '\n' << std::to_string(in.zip_code) << '\n' + in.country << '\n';
    return os;
}
```

## Special Class Properties

### `static`

**Static** members are member variables or member functions that are the same for every instance of the class. As an example, consider a ticket class that generates a special number for each ticket. This class also wants to keep track of how many tickets are sold, so it keeps a static count variable.

```C++
class Ticket {
    private:
        unsigned int num;

        // static member variables
        static unsigned int count;

    public:
        Ticket() : num(++count) {}
        unsigned int getNum() { return num; }

        // static member functions
        static unsigned int getSold() { return count; }
};
```

No matter how many instances of the Ticket class there are, they all share the same `count` variable and `getSold()` function. To demonstrate this, if three tickets were generated and their getSold() function were called, each of them would return the same value of 3.

```C++
t1.getSold(); // 3
t2.getSold(); // 3
t3.getSold(); // 3
```

### `this`

`this` is a special keyword for when inside a member function. `this` is a pointer to the current instance of the class. For example, if a `getAddress()` function were added to the ticket class, it could get the address of the current instance simply by returning `this`.

```C++
Ticket* getAddress() { return this; } // returns address of instance (0x...)
```

The `this` keyword can be used to obtain the member variables and member functions of the class. For example, if the user wanted to get the `num` attribute of the current instance, they could use `(*this).num` (notice the need to dereference).

### `->`

When the programmer makes a pointer to an instance of a class, they must dereference it to access the members. As an example, the programmer makes a pointer to a ticket object on the heap.

```C++
Ticket* t4 = new Ticket();
```

Now, to access the `getNum()` function of `t4`, the program must first dereference the pointer.

```C++
(*t4).getNum(); // dereference and get member
```

The `->` operator is another way to do this. This special dereference operator is used to dereference a pointer to an object and get a member from it.

```C++
t4->getNum(); // dereference and get member
```

## Namespaces

Something often used with object-oriented programming in C++ is namespaces. **Namespaces** allow the programmer to place functions, variables, classes, and other items within an identifier. These allow encapsulation when programming and allow for better organization.

### `namespace`

To place definitions inside a namespace, simply give the namespace identifier. The below example defined two functions and an alias inside the `math` namespace.

```C++
namespace math {
    using integer = unsigned long int;

    integer power(integer a, integer b);
    integer factorial(integer a);
}
```

Now, to use something inside this namespace in a function outside it (like main) the `math::` prefix must be included. As with `iostream`, `using` statements can also be used.

```C++
math::integer num = 3;
math::factorial(num);
```

## Example Program

An example program is provided to demonstrate this material.

### Usage
- compile: `make`
- run: `./classes.exe`
- cleanup: `make clean`

## References

- [CPP Reference](https://en.cppreference.com/)
- [CPP](https://www.cplusplus.com/doc/)
