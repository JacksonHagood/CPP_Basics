# ifndef HELPER_H
# define HELPER_H

# include <iostream>
# include <string>
using std::cout, std::cin, std::string; // usually not a good idea to have using statements in a header file

const unsigned char screenWidth = 50;

void outputHeading(string heading) {
    system("clear");
    cout << string((screenWidth - heading.size()) / 2, '-') << "\033[36m" << heading << "\033[0m" << string((screenWidth - heading.size()) / 2 + heading.size() % 2, '-') << "\n\n";
}

void promptInput() {
    cout << '\n' << string(screenWidth / 2 - 6, '-') << "\033[36mPress Enter\033[0m" << string(screenWidth / 2 - 5, '-') << "\n";
    cin.get();
    system("clear");
}

# endif