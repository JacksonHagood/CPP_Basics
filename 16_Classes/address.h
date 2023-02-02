# include <iostream>
# include <string>
using std::string, std::cout;

# ifndef ADDRESS_H
# define ADDRESS_H

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

# endif