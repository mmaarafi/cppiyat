#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	// std::cout << std::bad_alloc().what() << std::endl;
	// std::cout << Bureaucrat::GradeTooHighException().what() << std::endl;
	/*         constructor tests               */
	Bureaucrat boss("boss", 1);
	Bureaucrat crook("crook", 150);
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	/*         signing forms tests             */
	crook.signForm(*rrf);
	std::cout << "=======================\n=======================" << std::endl;
	boss.signForm(*rrf);
	std::cout << "=======================\n=======================" << std::endl;
	/*         AForm tests                     */
	boss.executeForm(*rrf);
	std::cout << "=======================\n=======================" << std::endl;
	delete rrf;
}
