# include <iostream>
using std::cout, std::cin;

int main() {
    cout << "\033[36mVariables\033[0m\n\n";

    // creation
    {
        cout << "\t\033[36mCreation\033[0m\n\n";

        cout << "\t\t\033[36mDeclaration\033[0m\n\n";

        int num1;  // integer variable
        char char1; // character variable

        // without initialization, variables take on a garbage value
        cout << "\t\t\tNum 1: " << num1 << '\n';
        cout << "\t\t\tCharacter 1: " << char1 << "\n\n";

        cout << "\t\t\033[36mInitialization\033[0m\n\n";

        int num2 = 0;
        char char2 = 'A'; // single quotes denote a char

        cout << "\t\t\tNum 2: " << num2 << '\n';
        cout << "\t\t\tCharacter 2: " << char2 << "\n\n";
    }

    // types
    {
        cout << "\t\033[36mTypes\033[0m\n\n";

        cout << "\t\t\033[36mPrimitives\033[0m\n\n";

        // 4 main primitive types
        bool boolean = true;
        char character = 'a';
        int integer = 1;
        float floating = 0.1;

        cout << "\t\t\tBoolean: " << boolean << '\n'; // boolean output as int
        cout << "\t\t\tCharacter: " << character << '\n';
        cout << "\t\t\tInteger: " << integer << '\n';
        cout << "\t\t\tFloating Point: " << floating << "\n\n";

        cout << "\t\t\033[36mSize\033[0m\n\n";

        char num1; // 1 byte
        short num2; // 2 bytes
        int num3; // typically 4 bytes
        long num4; // typically 8 bytes

        unsigned int num5; // unsigned 4 byte integer

        // can use sizeof() to get the size (in bytes) of a variable
        cout << "\t\t\tSize of char: " << sizeof(num1) << '\n';
        cout << "\t\t\tSize of short: " << sizeof(num2) << '\n';
        cout << "\t\t\tSize of int: " << sizeof(num3) << '\n';
        cout << "\t\t\tSize of long: " << sizeof(num4) << '\n';
        cout << "\t\t\tSize of unsigned int: " << sizeof(num5) << "\n\n";

        cout << "\t\t\033[36mOverflow\033[0m\n\n";

        int min = INT32_MIN; // minimum integer value (-2147483648)
        int max = INT32_MAX; // maximum integer value (2147483647)

        cout << "\t\t\tMinimum int: " << min << '\n';
        cout << "\t\t\tMaximum int: " << max << "\n\n";

        cout << "\t\t\033[36mBases\033[0m\n\n";

        // different bases
        cout << "\t\t\t10: " << 10 << '\n';
        cout << "\t\t\t0b1010: " << 0b1010 << '\n';
        cout << "\t\t\t0xA: " << 0xA << "\n\n";
    }

    // operators
    {
        cout << "\t\033[36mOperators\033[0m\n\n";

        cout << "\t\t\033[36mArithmetic Operators\033[0m\n\n";

        cout << "\t\t\t8 + 2 = " << 8 + 2 << '\n';
        cout << "\t\t\t8 - 2 = " << 8 - 2 << '\n';
        cout << "\t\t\t8 * 2 = " << 8 * 2 << '\n';
        cout << "\t\t\t8 / 2 = " << 8 / 2 << '\n';
        cout << "\t\t\t8 % 2 = " << 8 % 2 << "\n\n";

        cout << "\t\t\033[36mBitwise Operators\033[0m\n\n";

        cout << "\t\t\t8 & 2 = " << (8 & 2) << '\n';
        cout << "\t\t\t8 | 2 = " << (8 | 2) << '\n';
        cout << "\t\t\t8 ^ 2 = " << (8 ^ 2) << '\n';
        cout << "\t\t\t~8 = " << (~8) << '\n';
        cout << "\t\t\t8 << 2 = " << (8 << 2) << '\n';
        cout << "\t\t\t8 >> 2 = " << (8 >> 2) << "\n\n";

        cout << "\t\t\033[36mLogical Operators\033[0m\n\n";

        cout << "\t\t\t8 && 2 = " << (1 && 1) << '\n';
        cout << "\t\t\t8 || 2 = " << (1 || 0) << '\n';
        cout << "\t\t\t!8 = " << (!1) << "\n\n";

        cout << "\t\t\033[36mComparison Operators\033[0m\n\n";

        cout << "\t\t\t8 > 2: = " << (8 > 2) << '\n';
        cout << "\t\t\t8 < 2: = " << (8 < 2) << '\n';
        cout << "\t\t\t8 >= 2 = " << (8 >= 2) << '\n';
        cout << "\t\t\t8 <= 2 = " << (8 <= 2) << '\n';
        cout << "\t\t\t8 == 2 = " << (8 == 2) << '\n';
        cout << "\t\t\t8 != 2 = " << (8 != 2) << "\n\n";
    }

    // arrays
    {
        cout << "\t\033[36mArrays\033[0m\n\n";

        int numArray[4]{5, 9, 12, 7}; // 4 * 4 = 16 bytes of memory

        cout << "\t\tArray (pointer): " << numArray << '\n'; // arrays are pointers
        cout << "\t\tIndex 0: " << numArray[0] << '\n';
        cout << "\t\tIndex 1: " << numArray[1] << '\n';
        cout << "\t\tIndex 2: " << numArray[2] << '\n';
        cout << "\t\tIndex 3: " << numArray[3] << '\n';
    }

    return 0;
}