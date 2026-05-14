#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// std::cout << std::bad_alloc().what() << std::endl;
	// std::cout << Bureaucrat::GradeTooHighException().what() << std::endl;
	std::srand(std::time(NULL)); // Seed once here
	/*         constructor tests               */
	Bureaucrat boss("boss", 1);
	Bureaucrat crook("crook", 150);
	AForm *a = new PresidentialPardonForm("1");
	AForm *b = new ShrubberyCreationForm ("2");
	AForm *c = new RobotomyRequestForm("3");
	/*         signing forms tests             */
	crook.signForm(*a);
	std::cout << "=======================\n=======================" << std::endl;
	boss.signForm(*a);
	std::cout << "=======================\n=======================" << std::endl;
	boss.signForm(*b);
	std::cout << "=======================\n=======================" << std::endl;
	boss.signForm(*c);
	std::cout << "=======================\n=======================" << std::endl;
	/*         AForm tests                     */
	boss.executeForm(*a);
	std::cout << "=======================\n=======================" << std::endl;
	boss.executeForm(*b);
	std::cout << "=======================\n=======================" << std::endl;
	boss.executeForm(*c); 
	std::cout << "=======================\n=======================" << std::endl;
	crook.executeForm(*a);
	std::cout << "=======================\n=======================" << std::endl;
	crook.executeForm(*b);
	std::cout << "=======================\n=======================" << std::endl;
	crook.executeForm(*c);

	delete a;
	delete b;
	delete c;
}
