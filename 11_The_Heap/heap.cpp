# include <iostream>
using std::cout, std::cin;

// program to demonstrate the stack and heap

int main() {
    system("clear"); cout << "\033[36mThe Heap\033[0m\n\n";

    // integer created on the stack
    // stack is memory automatically managed by the compiler
    int stackInteger = 1;

    cout << "Integer value: \033[33m" << stackInteger << "\033[0m\n";
    cout << "Integer address: \033[35m" << &stackInteger << "\033[0m\n";

    // pointer to an integer created on the heap
    // heap is memory managed by the programmer (use new and delete)
    // all allocated memory on the heap must be traced back to a pointer on the stack (otherwise, memory leak)
    int* heapPointer = new int{3};

    // "heapPointer" is a pointer to an integer, not the integer itself
    cout << "\nPointer value: \033[35m" << heapPointer << "\033[0m\n";
    cout << "Pointer dereferenced: \033[33m" << *heapPointer << "\033[0m\n";

    // because pointers are themselves variables, they have their own memory location (the pointer variable is on the stack)
    cout << "Pointer address: \033[35m" << &heapPointer << "\033[0m\n";

    // (outputs diagram of the stack & heap)
    cout << "\n+-----------------------\033[36mSTACK\033[0m----------------------+        +--------------\033[36mHEAP\033[0m---------------+\n| addr           | value          | variable       |        | addr           | value          |\n+----------------+----------------+----------------+        +----------------+----------------+\n|                        \033[36m...\033[0m                       |        |               \033[36m...\033[0m               |\n+----------------+----------------+----------------+        +----------------+----------------+\n| \033[35m" << &stackInteger << "\033[0m | \033[33m" << stackInteger << "\033[0m              | stackInteger   |   +--->| \033[35m" << heapPointer << "\033[0m | \033[33m" << *heapPointer << "\033[0m              |\n+----------------+----------------+----------------+   |    +----------------+----------------+\n| \033[35m" << &heapPointer << "\033[0m | \033[35m" << heapPointer << "\033[0m | heapPointer    |---+    |               \033[36m...\033[0m               |\n+----------------+----------------+----------------+        +----------------+----------------+\n|                        \033[36m...\033[0m                       | \n+----------------+----------------+----------------+ \n";
    
    // must deallocate memory on the heap before access is lost to it
    // variables on the stack are automatically deleted once out of scope (such as the pointer)
    delete heapPointer;

    cout << "\nMemory deallocated\n";

    // even though the memory heapPointer points to is deleted, the pointer variable's value is not changed
    // therefore, the heapPointer points to a location in memory that has been deallocated (dangling pointer)
    cout << "\nPointer value: \033[35m" << heapPointer << "\033[0m\n";

    // it is best to set pointers to a nullptr after the memory they point to is deleted
    heapPointer = nullptr;

    cout << "\nPointer value (nullptr): \033[35m" << heapPointer << "\033[0m\n";
}
