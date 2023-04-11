# include "../Appendix/helper.h"

template <typename T> // "T" is a generic type
bool isEqual(T a, T b) {
    return a == b;
}

template <typename A, typename B> // "A" and "B" are generic types
auto sum(A a, B b) {
    return a + b;
}

int main() {
    outputHeading("Function Templates");

    {
        int int1 = 5;
        int int2 = -5;

        char char1 = 'a';
        char char2 = 'B';

        // calls isEqual() with "T" defined as int
        cout << int1 << (isEqual(int1, int2) ? " == " : " != ") << int2 << "\n";

        // calls isEqual() with "T" defined as char
        cout << char1 << (isEqual(char1, char2) ? " == " : " != ") << char2 << "\n";

        int num1 = 2;
        float num2 = 5.67;

        // calls sum() with "A" defined as int and "B" defined as float
        cout << num1 << " + " << num2 << " = " << sum(num1, num2) << '\n';
    }

    promptInput();

    return 0;
}