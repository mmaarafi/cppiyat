#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Class.hpp"

Base* generate(void)
{
	int r = std::rand() % 3;
	
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer actual type is: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer actual type is: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer actual type is: C" << std::endl;
	else
		std::cout << "Pointer actual type is: Unknown" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference actual type is: A" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference actual type is: B" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference actual type is: C" << std::endl;
		return;
	} catch (...) {}
	
	std::cout << "Reference actual type is: Unknown" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 3; i++)
	{
		std::cout << "--- Test " << i + 1 << " ---" << std::endl;
		Base* ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	return 0;
}