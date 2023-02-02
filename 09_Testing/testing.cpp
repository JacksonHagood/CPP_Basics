# include "../Appendix/helper.h"

int product(int lhs, int rhs) {
    return lhs * rhs;
}

int power(int base, unsigned int exponent) {
    int result = 1;

    for (unsigned int i = 0; i < exponent; i++) {
        result = product(result, base);
    }

    return result;
}

int main() {
    outputHeading("Testing");

    // parallel arrays for test cases
    int bases[5] = {2, 5, 10, 25, 3};
    unsigned int exponents[5] = {5, 0, 1, 4, 16};
    int results[5] = {32, 1, 10, 390625, 43046721};

    // integration tests for power() and product()
    for (unsigned int i = 0; i < 5; i++) {
        int output = power(bases[i], exponents[i]);

        if (output == results[i]) {
            cout << "TEST PASS: " << bases[i] << " ^ " << exponents[i] << " = " << results[i] << '\n';
        } else {
            cout << "TEST FAIL: " << bases[i] << " ^ " << exponents[i] << " = " << output << " (EXPECTED " << results[i] << ")\n";
        }
    }

    promptInput();
}