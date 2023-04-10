# include <iostream>

# ifndef MATH_H
# define MATH_H

namespace math {
    // inside the math namespace
    
    using integer = unsigned long int;

    integer power(integer a, integer b) {
        integer c = a;

        for (integer i = 1; i < b; i++) {
            c *= a;
        }

        return c;
    }

    integer factorial(integer a) {
        integer b = 1;

        for (integer i = 2; i <= a; i++) {
            b *= i;
        }

        return b;
    }
}

# endif