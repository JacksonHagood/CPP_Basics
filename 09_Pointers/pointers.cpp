# include "../Appendix/helper.h"

int main() {
    outputHeading("Address Operator");

    {
        int num = 1;

        // dereference operator gives the address of a variable
        int* ptr = &num;

        cout << "Ptr points to num\n";
        cout << "Num value: " << num << '\n';

        // memory addresses can be output
        cout << "Ptr value: " << ptr << '\n';
        cout << "Num address: " << &num << '\n';

        // pointers are also at an address
        cout << "Ptr address: " << &ptr << '\n';
    }

    promptInput();
    outputHeading("Dereference Operator");

    {
        int num = 1;
        int* ptr = &num;

        // dereference operator gives reference to whatever is at that address
        cout << "Num value: " << *ptr << '\n';

        // can use dereference operator to change values
        *ptr = 2;

        cout << "Num value: " << num << '\n';

        // address and dereference operators can negate each other
        cout << "Ptr value: " << ptr << '\n';
        cout << "Address of ptr dereferenced: " << &(*ptr) << '\n';
    }

    promptInput();
    outputHeading("Arrays");

    {
        // arrays are actually pointer variables
        int numArray[5]{10, 20, 30, 40, 50};

        cout << "Array base address: " << numArray << '\n';

        for (unsigned int i = 0; i < 5; i++) {
            cout << "Element " << i << ": " << numArray[i] << " (address " << &numArray[i] << ")\n";
        }
    }

    promptInput();
    outputHeading("nullptr");

    {
        // nullptr are special ptr values
        int* ptr = nullptr;

        cout << "Ptr value (nullptr): " << ptr << '\n';
        // cout << "Ptr value (nullptr): " << *ptr << '\n'; // would cause a SEGV on uknown address 0x000000000000 error
    }

    promptInput();

    return 0;
}