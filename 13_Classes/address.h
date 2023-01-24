# ifndef ADDRESS_H
# define ADDRESS_H

# include <iostream>
# include <string>
using std::string, std::cout;

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

# endif