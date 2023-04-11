# ifndef ADDRESS_H
# define ADDRESS_H

# include <iostream>
# include <string>

class Address {
    private:
        // private components: member variables
        std::string name;
        std::string line_one;
        std::string line_two;
        std::string city;
        std::string state;
        int zip_code;
        std::string country;

    public:
        // public components: member functions

        // constructors
        Address();
        Address(const std::string NAME, const std::string LINE_ONE, const std::string LINE_TWO, const std::string CITY, const std::string STATE, const int ZIP_CODE, const std::string COUNTRY);

        // getter functions
        std::string getName() const;
        std::string getLineOne() const;
        std::string getLineTwo() const;
        std::string getCity() const;
        std::string getState() const;
        int getZipCode() const;
        std::string getCountry() const;

        // setter functions
        void setName(const std::string NAME);
        void setLineOne(const std::string LINE_ONE);
        void setLineTwo(const std::string LINE_TWO);
        void setCity(const std::string CITY);
        void setState(const std::string STATE);
        void setZipCode(const int ZIP_CODE);
        void setCountry(const std::string COUNTRY);

        // other functions / operations
        std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Address& in);
};

# endif