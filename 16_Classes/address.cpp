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

// getter functions
string Address::getName() const { return name; }
string Address::getLineOne() const{ return line_one; }
string Address::getLineTwo() const { return line_two; }
string Address::getCity() const { return city; }
string Address::getState() const { return state; }
int Address::getZipCode() const { return zip_code; }
string Address::getCountry() const { return country; }

// setter functions
void Address::setName(const string NAME) { name = NAME; }
void Address::setLineOne(const string LINE_ONE) { line_one = LINE_ONE; }
void Address::setLineTwo(const string LINE_TWO) { line_two = LINE_TWO; }
void Address::setCity(const string CITY) { city = CITY; }
void Address::setState(const string STATE) { state = STATE; }
void Address::setZipCode(const int ZIP_CODE) { zip_code = ZIP_CODE; }
void Address::setCountry(const string COUNTRY) { country = COUNTRY; }

// to string function
string Address::toString() const {
    return name + '\n' + line_one + '\n' + (line_two == "" ? "" : line_two + '\n') + city + ", " + state + '\n' + std::to_string(zip_code) + '\n' + country + '\n';
}

// ostream operator for address class
std::ostream& operator<<(std::ostream& os, const Address& in) {
    os << in.name << '\n' << in.line_one << '\n' << (in.line_two == "" ? "" : in.line_two + '\n') << in.city << ", " << in.state << '\n' << std::to_string(in.zip_code) << '\n' + in.country << '\n';
    return os;
}