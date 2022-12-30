# include "../Appendix/helper.h"

int square(int num) {
    if (num == 0) {
        // throws invalid argument if integer is zero
        throw std::invalid_argument("Integer is zero");
    } else if (num < 0) {
        // throws invalid argument if integer is negative
        throw std::invalid_argument("Integer is negative");
    }

    return num * num;
}

int main() {
    outputHeading("Throwing Exceptions");

    {
        int input;

        cout << "Enter a positive integer: ";
        cin >> input; cin.get();

        // square() can throw an exception if input is not positive (will become runtime error)
        int output = square(input);

        cout << input << " squared is: " << output << '\n';
    }

    promptInput();
    outputHeading("Throwing Exceptions");

    {
        int input;

        cout << "Enter a positive integer: ";
        cin >> input; cin.get();

        try{
            // square() can throw an exception if input is not positive
            int output = square(input);

            cout << input << " squared is: " << output << '\n';
        } catch (std::invalid_argument& exception) {
            // executes if square() throws an invalid argument exception
            cout << "Exception: " << exception.what() << '\n';
        }
    }

    promptInput();

    return 0;
}