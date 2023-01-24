# include "../Appendix/helper.h"
# include "address.h"

int main() {
    outputHeading("Classes");

    {
        Address tamu("Administration Building", "400 Bizzell St", "", "College Station", "TX", 77843, "USA");

        cout << '\n';

        cout << tamu.toString();
    }

    promptInput();

    return 0;
}
