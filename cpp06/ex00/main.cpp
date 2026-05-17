#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert \"param\"." << std::endl;
		return (0);
	}
	(void) ac;
	ScalarConverter::convert(av[1]);
}