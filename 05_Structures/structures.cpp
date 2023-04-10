# include "../Appendix/helper.h"
# include "math.h"
# include "colors.h"
# include "integer.h"

int main() {
    outputHeading("Namespaces");

    {
        // outside the math namespace
        
        // math:: prefix must be given to access parts of a namespace
        math::integer num = 3;
        math::integer exp = 5;

        cout << num << " ^ " << exp << " = " << math::power(num, exp) << '\n';
        cout << num << "! = " << math::factorial(num) << '\n';
    }

    promptInput();
    outputHeading("Enumerations");

    {
        cout << "Value of red: " << Color::red << '\n';
        cout << "Value of orange: " << Color::orange << '\n';
        cout << "Value of green: " << Color::green << '\n';
        cout << "Value of cyan: " << Color::cyan << '\n';
        cout << "Value of blue: " << Color::blue << '\n';
        cout << "Value of magenta: " << Color::magenta << '\n';

        Color c1 = Color::red; // red = 0
        int c2 = 1; // orange = 1

        cout << c1 << " is" << (isPrimary(c1) ? "" : " not") << " primary\n";
        cout << c2 << " is" << (isPrimary((Color) c2) ? "" : " not") << " primary\n";
    }

    promptInput();
    outputHeading("Unions");

    {
        Integer num; // 8 bytes of memory
        
        num.intValue = INT32_MAX; // writes to the first 4 bytes of memory

        cout << "int changed to INT32_MAX\n";
        cout << "char value: " << num.charValue << '\n';
        cout << "short value: " << num.shortValue << '\n';
        cout << "int value: " << num.intValue << '\n';
        cout << "long value: " << num.longValue << '\n';

        num.shortValue = INT16_MAX; // writes to the first 2 bytes of memory

        cout << "\nshort changed to INT16_MAX\n";
        cout << "char value: " << num.charValue << '\n';
        cout << "short value: " << num.shortValue << '\n';
        cout << "int value: " << num.intValue << '\n';
        cout << "long value: " << num.longValue << '\n';
    }

    promptInput();

    return 0;
}
