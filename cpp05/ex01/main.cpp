#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// std::cout << std::bad_alloc().what() << std::endl;
	// std::cout << Bureaucrat::GradeTooHighException().what() << std::endl;
	/*         constructor tests               */
	Bureaucrat boss("boss", 1);
	Bureaucrat crook("crook", 150);
	Form a;
	Form b("form_1", 1, 1);
	Form d("form_2", 150, 150);
	Form e("form_3", 1, 1);
	Form f("form_4", 150, 150);
	try
	{
		Form c("form_5", 200, 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form e("form_6", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*         Form tests                     */
	std::cout << b;
	boss.signForm(b);
	boss.signForm(d);
	crook.signForm(e);
	crook.signForm(f);
}
