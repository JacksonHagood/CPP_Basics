# include "../Appendix/helper.h"
# include <vector>

using std::vector;

int main() {
    outputHeading("Vectors");

    {
        vector<int> nums = {1, 2, 3};
        
        nums.push_back(4);

        for (int num : nums) {
            cout << num << " ";
        }

        cout << '\n';
    }

    promptInput();

    return 0;
}