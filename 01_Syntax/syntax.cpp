# include <iostream>
using std::cout, std::cin, std::endl;

/*
    cout: standard output stream
    cin: standard input stream
    endl: newline character and flushes stream
*/

int main() {
    // outputs string to standard output
    cout << "Enter your age: ";

    int age;

    // reads in integer from standard input
    cin >> age;

    // outputs string, age variable, and newline character
    cout << "Your age is: " << age << std::endl;

    return 0;
}