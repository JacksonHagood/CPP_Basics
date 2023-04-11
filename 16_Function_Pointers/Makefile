all: function_pointers.cpp
	g++ -std=c++17 -Wextra -Weffc++ -pedantic -fsanitize=address,undefined -o function_pointers.exe function_pointers.cpp

clean:
	rm function_pointers.exe