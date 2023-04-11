# include "../Appendix/helper.h"
# include <string.h>

int main() {
    outputHeading("Characters");

    {
        char a = 'a';

        // characters can easily be output
        cout << "Character a: " << a << '\n';

        // type casting can be used to get a characters integer value
        cout << "Integer value of a: " << (int) a << '\n';
    }

    promptInput();
    outputHeading("C-strings");

    {
        // c-strings are arrays of characters terminated by null ('\0')
        char array[10] = {'H', 'e', 'l', 'l', 'o', '\0', '-', '-', '-', '-'};
        
        // C++ has built-in support for c-strings (not output like other arrays)
        cout << "C-string: " << array << '\n';
        cout << "Size of array: " << 10 << '\n';

        // string.h provides some helpful functions for c-strings
        cout << "Size of c-string: " << strlen(array) << '\n';
    }

    promptInput();
    outputHeading("C++ Strings");

    {
        // C++ strings are much easier to create
        string str = "Hello";

        cout << "C++ string: " << str << '\n';

        // can use member functions of string class
        cout << "Size of string: " << str.size() << '\n';

        cout << '\n' << "String [0]: " << str[0] << '\n';

        for (unsigned int i = 0; i <= str.size(); i++) {
            cout << "String at " << i << ": ";

            try {
                cout << str.at(i) << '\n';
            } catch (std::out_of_range) {
                cout << "EXCEPTION THROWN\n";
            }
        }

        // can use front and back functions to get start and end characters
        cout << "\nString front: " << str.front() << '\n';
        cout << "String back: " << str.back() << '\n';

        // can use substring function to get partial string
        cout << "String from [1, 3): " << str.substr(1, 3) << '\n';

        // can use find to search for strings
        cout << "\nFind \"ello\": " << str.find("ello") << '\n';
        cout << "Find \"goodbye\": " << str.find("goodbye") << " (string::npos)\n";

        string str2 = "there";

        // C++ strings support concatenation
        cout << "\n\"Hello\" + \' \' + \"there\": " << str + ' ' + str2 << '\n';

        // several functions for string modification
        str.push_back('!'); // adds '!' to end
        str.erase(2, 3); // erases 3 characters starting at index 2
        str.insert(2, "y"); // inserts "y" at index 2

        cout << "New string: " << str << '\n';
    }

    promptInput();
}