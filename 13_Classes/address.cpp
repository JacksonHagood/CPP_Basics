# include "address.h"

// function definitions for address class

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

// getter functions
string Address::getName() { return name; }
string Address::getLineOne() { return line_one; }
string Address::getLineTwo() { return line_two; }
string Address::getCity() { return city; }
string Address::getState() { return state; }
int Address::getZipCode() { return zip_code; }
string Address::getCountry() { return country; }

// setter functions
void Address::setName(string NAME) { name = NAME; }
void Address::setLineOne(string LINE_ONE) { line_one = LINE_ONE; }
void Address::setLineTwo(string LINE_TWO) { line_two = LINE_TWO; }
void Address::setCity(string CITY) { city = CITY; }
void Address::setState(string STATE) { state = STATE; }
void Address::setZipCode(int ZIP_CODE) { zip_code = ZIP_CODE; }
void Address::setCountry(string COUNTRY) { country = COUNTRY; }

// other functions / operations
string Address::toString() {
    return name + '\n' + line_one + '\n' + (line_two == "" ? "" : line_two + '\n') + city + ", " + state + '\n' + std::to_string(zip_code) + '\n' + country + '\n';
}