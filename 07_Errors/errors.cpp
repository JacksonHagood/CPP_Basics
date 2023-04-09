# include "../Appendix/helper.h"

int main() {
    cout << 1 / 0;

    outputHeading("Syntax Errors");

    {
        // int num = 1 // would cause syntax error

        // foo(); // would cause linker error

        int size = 10;

        // causes warning against comparing unsigned and signed ints
        for (unsigned int i = 0; i < size; i++) {
            cout << i << " ";
        }

        cout << '\n';
    }

    promptInput();
    outputHeading("Runtime Errors");

    {
        int nums[3] = {0, 1, 2};
        cout << "Number 0: " << nums[0] << '\n';
        cout << "Number 1: " << nums[1] << '\n';
        cout << "Number 2: " << nums[2] << '\n';
        // cout << "Number 3: " << nums[3] << '\n'; // could cause segmentation fault

        // cout << "1 / 0 = " << 1 / 0 << '\n'; // would cause divide by zero error
    }

    promptInput();
    outputHeading("Logical Errors");

    {
        // logical error due to integer division
        cout << "5 gallons split in half is " << 5 / 2 << " gallons.\n";
    }

    promptInput();

    return 0;
}
