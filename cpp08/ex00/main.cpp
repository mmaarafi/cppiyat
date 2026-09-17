#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> v;
		v.push_back(10);
		v.push_back(42);
		v.push_back(30);
		v.push_back(40);
		std::vector<int>::iterator element = easyfind(v, 42);
		std::cout << "Element found:" << *element << std::endl; 
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	try
	{
		std::list<int> l;
		l.push_back(100);
		l.push_back(200);
		l.push_back(300);
		l.push_back(400);
		
		std::list<int>::iterator list_element = easyfind(l, 300);
		std::cout << "Element found in list: " << *list_element << std::endl; 
		std::cout << "Trying to find 999 in list..." << std::endl;
		easyfind(l, 999);
	}
	catch (const std::exception &e)
	{
		std::cerr << "List error: " << e.what() << std::endl;
	}
}