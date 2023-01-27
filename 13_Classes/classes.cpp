# include "../Appendix/helper.h"
# include "address.h"
# include "ticket.h"

int main() {
    outputHeading("Classes");

    {
        // parameterized constructor call
        Address tamu("Administration Building", "400 Bizzell St", "", "College Station", "TX", 77843, "USA");

        // call getter functions
        cout << "\nName: " << tamu.getName() << '\n';
        cout << "Line one: " << tamu.getLineOne() << '\n';
        cout << "Line two: " << tamu.getLineTwo() << '\n';
        cout << "City: " << tamu.getCity() << '\n';
        cout << "State: " << tamu.getState() << '\n';
        cout << "Zip code: " << tamu.getZipCode() << '\n';
        cout << "Country: " << tamu.getCountry() << '\n';

        cout << '\n';

        // uses the overloaded << operator
        cout << tamu;
    }

    promptInput();
    outputHeading("Special Class Properties");

    {
        // create some tickets
        Ticket t1;
        Ticket t2;
        Ticket t3;

        // static components are the same for all instances
        cout << "Ticket 1 ID: " << t1.getNum() << " (# sold: " << t1.getSold() << ")\n";
        cout << "Ticket 2 ID: " << t2.getNum() << " (# sold: " << t2.getSold() << ")\n";
        cout << "Ticket 3 ID: " << t3.getNum() << " (# sold: " << t3.getSold() << ")\n";

        cout << "\nAddress of t1: " << &t1 << '\n';
        cout << "Address of t1: " << t1.getAddress() << '\n';

        Ticket* t4 = new Ticket();

        cout << "\nTicket 4: " << (*t4).getNum() << '\n';
        cout << "Ticket 4: " << t4->getNum() << '\n';

        delete t4;
    }

    promptInput();

    return 0;
}
