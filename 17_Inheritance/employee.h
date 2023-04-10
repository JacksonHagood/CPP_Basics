# ifndef EMPLOYEE_H
# define EMPLOYEE_H

# include <iostream>
# include <string>

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

class Engineer : public Employee { // engineer derives employee
    protected:
        std::string title;

    public:
        // engineer constructor (invokes employee constructor)
        Engineer(const std::string NAME, const unsigned int AGE, const std::string TITLE) : Employee(NAME, AGE), title(TITLE) {}

        // getter / setter functions
        std::string getTitle() const { return title; }
        void setTitle(const std::string TITLE) { title = TITLE; }

        // other functions
        std::string toString() const {
            return "Engineer: (" + Employee::toString() + "), " + title; // calls the employee to string function
        }
};

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

# endif