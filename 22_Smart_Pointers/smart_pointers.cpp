# include "../Appendix/helper.h"
# include <memory>

int main() {
    outputHeading("Unique Pointers");

    {
        std::unique_ptr<int> ptr(new int(3));

        cout << "Pointer dereference: " << *ptr << '\n'; // gets value
        cout << "Memory address: " << ptr.get() << '\n'; // gets memory address

        // memory on heap is automatically deallocated when unique pointer is out of scope
    }

    promptInput();
    outputHeading("Shared Pointers");

    {
        std::shared_ptr<int> ptr1;

        {
            std::shared_ptr<int> ptr2(new int(3));
            cout << "Pointer 1: " << ptr2.get() << '\n'; // gets value

            ptr1 = ptr2;

            // memory on heap is not deallocated as another shared pointer is still in scope
        }
        
        cout << "Pointer 2: " << ptr1.get() << '\n';

        // memory on heap is automatically deallocated as the final shared pointer is out of scope
    }

    promptInput();

    return 0;
}
