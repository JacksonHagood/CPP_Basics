# include "../Appendix/helper.h"
# include "byte.h"

int main() {
    outputHeading("Shallow vs Deep Copy");

    {
        // original
        int* original = new int{1};

        // shallow copy
        int* shallowCopy = original;

        // deep copy
        int* deepCopy = new int;
        *deepCopy = *original;

        cout << "Original value: " << *original << '\n';
        cout << "Original address: " << original << '\n';

        cout << "Shallow copy value: " << *shallowCopy << '\n';
        cout << "Shallow copy address: " << shallowCopy << '\n';

        cout << "Deep copy value: " << *deepCopy << '\n';
        cout << "Deep copy address: " << deepCopy << '\n';

        // changing original changes the shallow copy but not the deep copy
        *original = 2;
        cout << "\nOriginal value changed\n\n";

        cout << "Original value: " << *original << '\n';
        cout << "Original address: " << original << '\n';

        cout << "Shallow copy value: " << *shallowCopy << '\n';
        cout << "Shallow copy address: " << shallowCopy << '\n';

        cout << "Deep copy value: " << *deepCopy << '\n';
        cout << "Deep copy address: " << deepCopy << '\n';

        cout << "\n+-----------------Stack Diagram-----------------+     +------Heap Diagram------+\n|    address     |     value      | identifier  |     |    address     | value |\n+----------------+----------------+-------------+     +----------------+-------+\n| " << &original << " | " << original << " | original    |-+-->| " << original << " |   2   |\n| " << &shallowCopy << " | " << shallowCopy << " | shallowCopy |  +->| " << deepCopy << " |   1   |\n| " << &deepCopy << " | " << deepCopy << " | deepCopy    |--+  |       ...      |  ...  |\n|       ...      |      ...       |     ...     |     +----------------+-------+\n+----------------+----------------+-------------+\n";

        delete original;
        delete deepCopy;
    }

    promptInput();
    outputHeading("Rule of Three");

    {
        Byte byte0(0);
        Byte byte1(byte0); // copy constructor
        Byte byte2 = byte0; // copy assignment operator

        cout << "Byte 0: " << byte0.getByte() << '\n';
        cout << "Byte 1: " << byte1.getByte() << '\n';
        cout << "Byte 2: " << byte2.getByte() << '\n';

        byte0.setByte(3);
        cout << "\nByte 0 changed\n\n";

        cout << "Byte 0: " << byte0.getByte() << '\n';
        cout << "Byte 1: " << byte1.getByte() << '\n';
        cout << "Byte 2: " << byte2.getByte() << '\n';

        byte1.setByte(5);
        cout << "\nByte 1 changed\n\n";

        cout << "Byte 0: " << byte0.getByte() << '\n';
        cout << "Byte 1: " << byte1.getByte() << '\n';
        cout << "Byte 2: " << byte2.getByte() << '\n';

        // destructor called here by compiler
    }

    promptInput();

    return 0;
}
