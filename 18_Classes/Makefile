all: classes.cpp address.cpp
	g++ -std=c++17 -Wextra -Weffc++ -pedantic -fsanitize=address,undefined -o classes.exe classes.cpp address.cpp

clean:
	rm classes.exe