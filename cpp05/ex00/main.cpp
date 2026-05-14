#include "Bureaucrat.hpp"

int main()
{
	// std::cout << std::bad_alloc().what() << std::endl;
	// std::cout << Bureaucrat::GradeTooHighException().what() << std::endl;
	/*         constructor tests               */
	Bureaucrat a;
	Bureaucrat b("moha", 1);
	Bureaucrat d("moha", 150);
	try
	{
		Bureaucrat c("moha", 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat e("anas", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*         decrement increment tests       */
	std::cout << a;
	a.increment();
	std::cout << a;
	a.decrement();
	std::cout << a;
	try
	{
		b.increment();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		d.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
