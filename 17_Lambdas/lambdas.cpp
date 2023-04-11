# include "../Appendix/helper.h"

template <typename F>
unsigned int countEqual(unsigned int array[], unsigned int size, unsigned int value, F equality) {
    unsigned int count = 0;

    for (unsigned int i = 0; i < size; i++) {
        if (equality(value, array[i])) {
            count++;
        }
    }

    return count;
}

int main() {
    outputHeading("Function Pointers");

    {
        unsigned int size = 5;
        unsigned int array[5] = {0, 1, 3, 5, 6};
        unsigned int value = 0;

        {
            cout << "Equivalence function: equality of values " << 3 << '\n';
            auto equals = [](unsigned int lhs, unsigned int rhs) { return lhs == rhs; };

            // counts the number of elements in the array that are equivalent to value
            cout << value << " is equivalent to " << countEqual(array, size, value, equals) << " values\n";
        }

        {
            cout << "\nEquivalence function: congruence mod " << 3 << '\n';
            unsigned int m = 3;
            auto congruent = [m](unsigned int lhs, unsigned int rhs) { return lhs % m == rhs % m; };

            // counts the number of elements in the array that are congruent (mod m) to value
            cout << value << " is equivalent to " << countEqual(array, size, value, congruent) << " values\n";
        }
    }

    promptInput();

    return 0;
}
