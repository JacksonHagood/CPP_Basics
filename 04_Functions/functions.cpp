# include "../Appendix/helper.h"

int foo() {
    return 0; // returned value must match function type
}

void hello_world() {
    cout << "Hello, World!\n";
}

void pass_by_value(int num) {
    // pass by value: operations on a copy
    num = 1;
}

void pass_by_reference(int& num) {
    // pass by reference: operations on the original
    num = 1;
}

void pass_by_pointer(int* ptr) {
    // pass by pointer: operations on the original memory address
    *ptr = 1;
}

int main() {
    outputHeading("Passing Parameters");

    {
        cout << "Result of Foo: " << foo() << '\n';
        hello_world();
    }

    promptInput();
    outputHeading("Passing Parameters");

    {
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;

        cout << "Number 1 before function: " << num1 << '\n';
        cout << "Number 2 before function: " << num2 << '\n';
        cout << "Number 3 before function: " << num3 << '\n';
        cout << '\n';

        pass_by_value(num1); // num1 goes unchanged
        pass_by_reference(num2); // num2 is changed
        pass_by_pointer(&num3); // num3 is changed (by giving its memory address)

        cout << "Number 1 after function (pass by value): " << num1 << '\n';
        cout << "Number 2 after function (pass by reference): " << num2 << '\n';
        cout << "Number 3 after function (pass by pointer): " << num3 << '\n';
    }

    promptInput();

    return 0;
}