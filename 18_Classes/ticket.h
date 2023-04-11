# include <iostream>
# include <string>
using std::string, std::cout;

# ifndef TICKET_H
# define TICKET_H

class Ticket {
    private:
        unsigned int num;

        // static member variables
        static unsigned int count;

    public:
        Ticket() : num(++count) {}
        unsigned int getNum() { return num; }
        Ticket* getAddress() { return this; }

        // static member functions
        static unsigned int getSold() { return count; }
};

unsigned int Ticket::count = 0;

# endif