# include "../Appendix/helper.h"

int main() {
    outputHeading("Dynamic Arrays");

    {
        // original array (on the heap)
        int* array = new int[3]{0, 1, 2};

        cout << "Array address: " << array << '\n';

        for (unsigned int i = 0; i < 3; i++) {
            cout << "Index " << i << ": " << array[i] << '\n';
        }

        // want to resize array to have room for six elements

        // step 1: allocate memory for new array (on the heap)
        int* newArray = new int[4];

        // step 2: copy values from old array to new array
        for (unsigned int i = 0; i < 3; i++) {
            newArray[i] = array[i];
        }

        newArray[3] = 3;

        // step 3: deallocate memory of old array
        delete[] array;

        // step 4: update array pointer to new array
        array = newArray;

        cout << "\nArray address: " << array << '\n';

        for (unsigned int i = 0; i < 4; i++) {
            cout << "Index " << i << ": " << array[i] << '\n';
        }

        delete[] array;
    }

    promptInput();

    return 0;
}
