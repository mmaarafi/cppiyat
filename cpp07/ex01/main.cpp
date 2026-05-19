#include <iostream>
#include "iter.hpp"
#include <string>

void incrementor(int &value)
{
	value++;
}

void bruh(std::string &astring)
{
	astring = "bruh";
}

int main( void )
{
	int numbers[3] = {1, 2, 3};
	std::cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << std::endl;
	iter(numbers, 3, incrementor);
	std::cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << std::endl;
	std::string strings[3] = {"moha", "simo", "hmad"};
	std::cout << strings[0] << " " << strings[1] << " " << strings[2] << std::endl;
	iter(strings, 3, bruh);
	std::cout << strings[0] << " " << strings[1] << " " << strings[2] << std::endl;
	return (0);
}