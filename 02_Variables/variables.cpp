# include "../Appendix/helper.h"

int main() {
    outputHeading("Declaring Variables");

    {
        // declaring variables
        int num1;  // integer variable
        char char1; // character variable

        // without initialization, variables take on a "garbage value"
        cout << "Num 1 (un-initialized): " << num1 << '\n';
        cout << "Character 1 (un-initialized): " << char1 << '\n';
        cout << '\n';

        // declaring and initializing variables
        int num2 = 0;
        char char2 = 'A'; // single quotes denote a char

        cout << "Num 2 (initialized): " << num2 << '\n';
        cout << "Character 2 (initialized): " << char2 << '\n';

        // const variables cannot be changed after initialized
        const int num3 = 0;
        // num3 = 5; // would cause error
    }

    promptInput();
    outputHeading("Data Types");

    {
        // 4 main primitive types
        bool boolean = true;
        char character = 'a';
        int integer = 1;
        float floating = 0.1;

        cout << "Boolean: " << boolean << '\n'; // boolean output as int
        cout << "Character: " << character << '\n';
        cout << "Integer: " << integer << '\n';
        cout << "Floating Point: " << floating << '\n';
        cout << '\n';

        char intChar; // 1 byte
        short intShort; // 2 bytes
        int intInt; // typically 4 bytes
        long intLong; // typically 8 bytes

        // can use sizeof() to get the size (in bytes) of a variable
        cout << "Size of char (bytes): " << sizeof(intChar) << '\n';
        cout << "Size of short (bytes): " << sizeof(intShort) << '\n';
        cout << "Size of int (bytes): " << sizeof(intInt) << '\n';
        cout << "Size of long (bytes): " << sizeof(intLong) << '\n';

        int8_t int8; // 1 byte
        int16_t int16; // 2 bytes
        int32_t int32; // 4 bytes
        int64_t int64; // 8 bytes

        unsigned int unsignedInt; // unsigned 4 byte integer
        u_int16_t unsignedInt8; // unsigned 2 byte integer
        size_t unsignedSizeT; // unsigned 8 byte integer

        int min = INT32_MIN; // minimum integer value (-2147483648)
        int max = INT32_MAX; // maximum integer value (2147483647)

        cout << "\nMinimum int: " << min << '\n';
        cout << "Maximum int: " << max << '\n';
        cout << '\n';

        // different bases
        cout << "10: " << 10 << '\n';
        cout << "0b1010: " << 0b1010 << '\n';
        cout << "0xA: " << 0xA << '\n';
    }

    promptInput();
    outputHeading("Operators");

    {
        cout << "Arithmetic Operators:\n";
        cout << "8 + 2 = " << 8 + 2 << '\n';
        cout << "8 - 2 = " << 8 - 2 << '\n';
        cout << "8 * 2 = " << 8 * 2 << '\n';
        cout << "8 / 2 = " << 8 / 2 << '\n';
        cout << "8 % 2 = " << 8 % 2 << '\n';
        cout << '\n';

        cout << "Bitwise Operators:\n";
        cout << "8 & 2 = " << (8 & 2) << '\n';
        cout << "8 | 2 = " << (8 | 2) << '\n';
        cout << "8 ^ 2 = " << (8 ^ 2) << '\n';
        cout << "~8 = " << (~8) << '\n';
        cout << "8 << 2 = " << (8 << 2) << '\n';
        cout << "8 >> 2 = " << (8 >> 2) << '\n';
        cout << '\n';

        cout << "Logical Operators:\n";
        cout << "8 && 2 = " << (1 && 1) << '\n';
        cout << "8 || 2 = " << (1 || 0) << '\n';
        cout << "!8 = " << (!1) << '\n';
        cout << '\n';

        cout << "Comparison Operators:\n";
        cout << "8 > 2 = " << (8 > 2) << '\n';
        cout << "8 < 2 = " << (8 < 2) << '\n';
        cout << "8 >= 2 = " << (8 >= 2) << '\n';
        cout << "8 <= 2 = " << (8 <= 2) << '\n';
        cout << "8 == 2 = " << (8 == 2) << '\n';
        cout << "8 != 2 = " << (8 != 2) << '\n';
        cout << '\n';
    }

    promptInput();
    outputHeading("Arrays");

    {
        int numArray[4]{5, 9, 12, 7}; // 4 * 4 = 16 bytes of memory

        cout << "Array address (pointer): " << numArray << '\n'; // arrays are pointers
        cout << "Index 0: " << numArray[0] << '\n';
        cout << "Index 1: " << numArray[1] << '\n';
        cout << "Index 2: " << numArray[2] << '\n';
        cout << "Index 3: " << numArray[3] << '\n';
    }

    promptInput();
    outputHeading("Type Conversion");

    {
        int num = 97;

        cout << "Num (int): " << num << '\n';
        cout << "Num (cast as char): " << (char) num << '\n'; // int cast as char
    }

    promptInput();

    return 0;
}