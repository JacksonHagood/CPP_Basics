# include "../Appendix/helper.h"

int main() {
    outputHeading("The Stack");

    {
        // stackInteger does not exist here

        {
            // integer created on the stack (automatically managed by the compiler)
            int stackInteger = 1;

            cout << "Integer value: " << stackInteger << '\n';
            cout << "Integer address: " << &stackInteger << '\n';

            // stackInteger exists here

            // outputs diagram of memory 
            cout << "\n+-------------Stack Diagram-------------+\n|    address     | value |  identifier  |\n+----------------+-------+--------------+\n| " << &stackInteger << " |   " << stackInteger << "   | stackInteger |\n|       ...      |  ...  |     ...      |\n+----------------+-------+--------------+\n";
        }

        // stackInteger does not exist here (automatically deleted once out of scope)
    }

    promptInput();
    outputHeading("The Heap");

    {
        // pointer to an integer created on the heap (managed by the programmer)
        int* heapPointer = new int{3};

        // "heapPointer" is a pointer to an integer, not the integer itself
        cout << "Pointer value: " << heapPointer << '\n';
        cout << "Pointer dereferenced: " << *heapPointer << '\n';

        // because pointers are themselves variables, they have their own memory location (on the stack)
        cout << "Pointer address: " << &heapPointer << '\n';

        // outputs diagram of memory 
        cout << "\n+-----------------Stack Diagram------------------+     +------Heap Diagram------+\n|    address     |     value      |  identifier  |     |    address     | value |\n+----------------+----------------+--------------+     +----------------+-------+\n| " << &heapPointer << " | " << heapPointer << " | heapPointer  |---->| " << heapPointer << " |   " << *heapPointer << "   |\n|       ...      |      ...       |     ...      |     |       ...      |  ...  |\n+----------------+----------------+--------------+     +----------------+-------+\n";

        // must deallocate memory on the heap before access is lost to it (pointer on stack goes out of scope)
        delete heapPointer;

        cout << "\nMemory deallocated\n";

        // the pointer variable's value is not changed (dangling pointer)
        cout << "Pointer value: " << heapPointer << '\n';

        // it is best to set to nullptr after the memory is deleted
        heapPointer = nullptr;

        cout << "\nDangling pointer handled\n";

        cout << "Pointer value (nullptr): " << heapPointer << '\n';
    }

    promptInput();

    return 0;
}
