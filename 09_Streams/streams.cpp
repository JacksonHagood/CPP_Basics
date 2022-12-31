# include "../Appendix/helper.h"
# include <sstream>
# include <fstream>

int main() {
    outputHeading("Input Streams");

    {
        cout << "Enter two words: ";

        string str1, str2;

        // separates strings by spaces
        cin >> str1 >> str2;
        cin.get();

        cout << "Word 1: " << str1 << '\n';
        cout << "Word 2: " << str2 << '\n';

        cout << "Enter your full name: ";

        string name;

        // get line obtains the entire line of input
        getline(cin, name);

        cout << "Your full name: " << name << '\n';
    }

    promptInput();
    outputHeading("Output Streams");

    {
        string str = "ABC";
        int num = 123;

        // output streams support a variety of data types
        cout << str << ' ' << num;
        cout << std::endl;
    }

    promptInput();
    outputHeading("String Streams");

    {
        cout << "Enter a line of words: ";

        string line;

        // reads line from cin
        getline(cin, line);

        // constructs stringstream with line
        std::stringstream ss(line);

        string temp;
        int i = 0;

        cout << "Line: " << ss.str() << '\n';

        // reads in words from stringstream one at a time
        while (ss >> temp) {
            cout << "Word " << ++i << ": " << temp << '\n';
        }
    }

    promptInput();
    outputHeading("File Streams");

    {
        // opens output file stream with data.txt
        std::ofstream output("data.txt");

        cout << "Enter a name and birthday (NAME MM/DD/YYYY), \"q\" to quit: ";
        string line;
        
        while (getline(cin, line) && line != "q") {
            // outputs string to file stream
            output << line << '\n';
            
            cout << "Enter a name and birthday (NAME MM/DD/YYYY), \"q\" to quit: ";
        }

        output.close(); // closes file stream (best practice)
        cout << "Birthday data stored in data.txt\n";

        // opens output file stream with data.txt
        std::ifstream input("data.txt");

        cout << "\nEnter a name to search for: ";
        string name;

        getline(cin, name);
        bool found = false;

        // reads in lines from file stream
        while (getline(input, line)) {
            if (line.find(name) != string::npos) {
                cout << "Found: " << line << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            cout << name << "not found\n";
        }

        input.close(); // closes file stream (best practice)
    }

    promptInput();
}