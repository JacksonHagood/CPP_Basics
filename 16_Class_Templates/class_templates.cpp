# include "../Appendix/helper.h"
# include "pair.h"

int main() {
    outputHeading("Class Templates");

    {
        Pair<int, float> p1(5, 6.0);

        cout << "Pair of int and float created\n";
        cout << "Left value: " << p1.getLeft() << '\n';
        cout << "Right value: " << p1.getRight() << '\n';

        Pair<string, string> p2("Jackson", "Hagood");

        cout << "\nPair of string and string created\n";
        cout << "Left value: " << p2.getLeft() << '\n';
        cout << "Right value: " << p2.getRight() << '\n';
    }

    promptInput();

    return 0;
}