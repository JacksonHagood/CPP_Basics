# include "../Appendix/helper.h"
# include "math.h"

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

    return 0;
}
