# include "../Appendix/helper.h"
# include "employee.h"

int main() {
    outputHeading("Inheretence");

    {
        Employee john("John Jones", 38);
        cout << john.toString() << '\n';

        Engineer stuart("Stuart Smith", 32, "Web Developer");
        stuart.setAge(33);
        cout << stuart.toString() << '\n';

        SoftwareEngineer jackson("Jackson Hagood", 21, "Front-end Developer", "JavaScript, React, Redux");
        cout << jackson.toString() << '\n';
    }

    promptInput();

    return 0;
}
