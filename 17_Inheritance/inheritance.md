# Inheritance

One useful form of abstraction with object-oriented programming is **inheritance**. By allowing classes to derive other classes, relationships can be defined in the structure of the type.

## Inheritance and Polymorphism

As an example, consider an `Employee` class that stores an employee's `name` and `age`. This class implements a parameterized constructor, getter / setter functions, and a `toString()` function. Notice that the member variables are `protected`, rather than `private`. This means that classes which derive this class can access these fields (though other functions can still not access them).

```C++
class Employee {
    protected:
        std::string name;
        unsigned int age;
    
    public:
        // employee constructor
        Employee(const std::string NAME, const unsigned int AGE) : name(NAME), age(AGE) {}

        // getter functions
        std::string getName() const { return name; }
        unsigned int getAge() const { return age; }

        // setter functions
        void setName(const std::string NAME) { name = NAME; }
        void setAge(const unsigned int AGE) { age = AGE; }

        // other functions
        std::string toString() const {
            return "Employee: " + name + ", " + std::to_string(age);
        }
};
```

```C++
Employee john("John Jones", 38);
```

Now, consider the programmer wishes to make a `Engineer` class that would implement many of the same variables and functions as `Employee`. One way to accomplish this is with inheritance. The `Engineer` class can **derive** the `Employee` class, meaning all the protected and public fields are a part of the object. The `Engineer` class is considered a **child** of the `Employee` class. Notice that the `Engineer` constructor uses the `Employee` constructor to initialize the `name` and `age` variables. In addition, the programmer adds a `title` member variable along with corresponding functions.

```C++
class Engineer : public Employee { // engineer derives employee
    protected:
        std::string title;

    public:
        // engineer constructor (invokes employee constructor)
        Engineer(const std::string NAME, const unsigned int AGE, const std::string TITLE) : Employee(NAME, AGE), title(TITLE) {}

        // getter / setter functions
        std::string getTitle() const { return title; }
        void setTitle(const std::string TITLE) { title = TITLE; }
};
```

```C++
Engineer stuart("Stuart Smith", 32, "Web Developer");
```

## Polymorphism

If the `toString()` function were called with the above class definition for an `Engineer`, the `title` member variable would not be output as the `Employee`'s function has no concept of it. To get around this, the programmer can use **polymorphism** to implement an `Engineer` `toString()` function. This function can make use of the `Employee` `toString()` function by specifying the `Employee::` namespace. Now, if the `toString()` function were called with an instance of the `Engineer` class, the `Engineer()` `toString()` function would be called, and the `title` would be output.

```C++
std::string toString() const {
    return "Engineer: (" + Employee::toString() + "), " + title; // calls the employee to string function
}
```

## Mult-level Inheritance

C++ supports mult-level inheritance. If the programmer then wished to implement a `SoftwareEngineer` class that implements the functionality of `Employee` and `Engineer` they could derive the `Engineer` class. The `SoftwareEngineer` class would be considered a child of the `Engineer` class and a **grandchild** of the `Employee` class. Like before, this class can utilize polymorphism in the `toString()` function. Such a function will call the `Engineer` `toString()` function which will then call the `Employee` `toString()` function.

```C++
class SoftwareEngineer : public Engineer { // software engineer derives engineer (which derives employee)
    private:
        std::string tech;

    public:
        // software engineer constructor (invokes engineer constructor)
        SoftwareEngineer(const std::string NAME, const unsigned int AGE, const std::string TITLE, const std::string TECH) : Engineer(NAME, AGE, TITLE), tech(TECH) {}

        // getter / setter functions
        std::string getTech() const { return tech; }
        void setTech(const std::string TECH) { tech = TECH; }

        // other functions
        std::string toString() const {
            return "Software Engineer: (" + Engineer::toString() + "), " + tech; // calls the engineer to string function (which calls the employee to string function)
        }
};
```

```C++
SoftwareEngineer jackson("Jackson Hagood", 21, "Front-end Developer", "JavaScript, React, Redux");
```

### Class Hierarchies

Inheritance can lead to complex trees of relationships between classes. For example, the following is the hierarchy for the stream classes.

```
                              ios
                 ┌─────────────┴─────────────┐
              istream                     ostream
   ┌────────────┤ └────────────┬────────────┘ ├────────────┐ 
ifstream   istringstream    iostream   ostringstream    ofstream
```
