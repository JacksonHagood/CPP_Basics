# include "../Appendix/helper.h"

int adder(int a, int b) {
    return a + b;
}

int caller(int a, int b, int (*function)(int, int)) {
    return function(a, b);
}

int main() {
    outputHeading("Function Pointers");

    {
        cout << "Address of function adder(): " << (void*) adder << '\n';
        cout << "Address of function caller(): " << (void*) caller << '\n';

        cout << "\ncaller() invoked with adder(): " << caller(2, 3, &adder) << '\n';
    }

    promptInput();

    return 0;
}