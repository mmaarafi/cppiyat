#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int main()
{
	// shortest span longest span addnumber exception
	Span a(5);
	a.addNumber(10);
	a.addNumber(15);
	a.addNumber(99);
	a.addNumber(100);
	a.addNumber(29);
	try
	{
		a.addNumber(29);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "longest span: " << a.longestSpan() << std::endl;
	std::cout << "shortest span: " << a.shortestSpan() << std::endl;
	// range of iterator test
	Span sp(10000);
	std::vector<int> massiveVector;
	for (int i = 0; i < 10000; i++)
		massiveVector.push_back(i * 2);
	sp.addNumbers(massiveVector.begin(), massiveVector.end());
	try
	{
		sp.addNumbers(massiveVector.begin(), massiveVector.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
}
