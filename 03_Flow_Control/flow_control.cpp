# include "../Appendix/helper.h"

int main() {
    outputHeading("If Statements");

    {
        bool condition = true;

        if (condition) {
            // executes if condition is true
            cout << "Condition is true\n";
        }

        bool condition1 = false;
        bool condition2 = true;

        if (condition1) {
            // executes if condition 1 is true
            cout << "Condition 1 is true\n";
        } else if (condition2) {
            // executes if condition 1 is false and condition 2 is true
            cout << "Condition 1 is false and Condition 2 is true\n";
        } else {
            // executes if condition 1 and condition 2 are both false
            cout << "Condition 1 is false and Condition 2 is false\n";
        }

        unsigned int select = 4;

        // executes the case according to the value of the selector
        switch(select) {
            case 0:
                cout << "Zero is selected\n";
                break;
            case 1:
                cout << "One is selected\n";
                break;
            case 2:
                cout << "Two is selected\n";
                break;
            case 3:
                cout << "Three is selected\n";
                break;
            case 4:
                cout << "Four is selected\n";
                break;
            case 5:
                cout << "Five is selected\n";
                break;
            default:
                cout << "A number greater than 5 is selected\n";
                break;
        }

        bool boolean = true;

        // outputs TRUE if the boolean true, FALSE otherwise
        cout << "The boolean is " << (boolean ? "TRUE" : "FALSE") << '\n';
    }

    promptInput();
    outputHeading("Loops");

    {
        bool condition = true;
        unsigned int counter = 0;

        while (condition) {
            // executes once at a time with condition checked before each iteration
            cout << "Iteration " << ++counter << ": Condition is True\n";

            if (counter == 8) {
                condition = false;
            }
        }

        cout << "Condition is false\n\n";

        // for loop equivalent to the while loop
        for (unsigned int i = 0; i <= 8; i++) {
            cout << "Iteration " << i << ": Condition is True\n";
        }

        cout << "Condition is false\n\n";

        // loops can be nested
        for (unsigned int row = 0; row < 10; row++) {
            for (unsigned int col = 0; col < 10; col++) {
                cout << row << col << " ";
            }
            cout << '\n';
        }
    }

    promptInput();

    return 0;
}