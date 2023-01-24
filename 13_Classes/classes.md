# Object-oriented Programming

As programs grow in complexity, additional layers of abstraction can be useful. One way to consolidate programs into manageable units is using object-oriented programming. What is important to realize is that object-oriented programming, unlike more primitive components (like variables and flow control), is not central to solving any problem. Object-oriented programming is only a tool, and there can be detrimental ways to use this tool. Furthermore, any problem can be solved without object-oriented programming. Programmers should learn object-oriented programming and grow comfortable with it, but it is counter-productive to become so reliant on it that one cannot program without it.

## Structs

Structs are the most primitive way of implementing object-oriented programming. While they can be used to the same extent as classes, they are most often used to just combine multiple data fields into a single structure. For example, if the programmer wanted a container to store the information of a person, they could define the following struct.

```C++
struct Person {
    string name;
    int age;
}
```

Notice how each component of the struct is indicated with a type and identifier. The programmer can now declare instances of this person struct. To obtain the component, they simply type the instance's identifier followed by the identifier of what they want.

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
        Address(string NAME, string LINE_ONE, string LINE_TWO, string CITY, string STATE, int ZIP_CODE, string COUNTRY);

        // getter functions
        string getName();
        string getLineOne();
        string getLineTwo();
        string getCity();
        string getState();
        int getZipCode();
        string getCountry();

        // setter functions
        void setName(string NAME);
        void setLineOne(string LINE_ONE);
        void setLineTwo(string LINE_TWO);
        void setCity(string CITY);
        void setState(string STATE);
        void setZipCode(int ZIP_CODE);
        void setCountry(string COUNTRY);

        // other functions / operations
        string toString();
};
```

Each component of a class needs an **access specifier**. These tell the compiler whether or not the component can be accessed from outside the class. A `private` component can only be accessed from within the class and a `public` component can be accessed anywhere. Typically, **member variables** are `private` and **member functions** are `public` (there are exceptions). In this class, there are 7 member variables, each denoted by a type and identifier. The definitions of the member functions are often given in `.cpp` files separate from the `.h` file.

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
Address::Address(string NAME, string LINE_ONE, string LINE_TWO, string CITY, string STATE, int ZIP_CODE, string COUNTRY) :
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

The next categories of member functions are the **getters** and **setters** these are typically one line functions used to obtain and set the value of member variables (as they are private and cannot be directly accessed).

```C++
// getter functions
string Address::getName() { return name; }
string Address::getLineOne() { return line_one; }
string Address::getLineTwo() { return line_two; }
string Address::getCity() { return city; }
string Address::getState() { return state; }
int Address::getZipCode() { return zip_code; }
string Address::getCountry() { return country; }
```

```C++
// setter functions
void Address::setName(string NAME) { name = NAME; }
void Address::setLineOne(string LINE_ONE) { line_one = LINE_ONE; }
void Address::setLineTwo(string LINE_TWO) { line_two = LINE_TWO; }
void Address::setCity(string CITY) { city = CITY; }
void Address::setState(string STATE) { state = STATE; }
void Address::setZipCode(int ZIP_CODE) { zip_code = ZIP_CODE; }
void Address::setCountry(string COUNTRY) { country = COUNTRY; }
```

Finally, there is one more function that falls under the category of miscellaneous operations specific to that class. In this example, a `toString()` function is given to return the object's representation as a string.

```C++
// other functions / operations
string Address::toString() {
    return name + '\n' + line_one + '\n' + (line_two == "" ? "" : line_two + '\n') + city + ", " + state + '\n' + std::to_string(zip_code) + '\n' + country + '\n';
}
```

All of these functions (outside of the constructors) can be called by giving the identifier of an instance along with the function name.

```C++
addr1.setName("Jackson Hagood");
cout << addr1.getName();
```