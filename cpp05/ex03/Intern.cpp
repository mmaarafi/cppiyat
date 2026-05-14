#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &cp) 
{
	(void) cp;
}

Intern &Intern::operator=(const Intern &obj)
{
	(void) obj;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::makePresidential(std::string target) { return new PresidentialPardonForm(target); }
AForm* Intern::makeRobotomy(std::string target) { return new RobotomyRequestForm(target); }
AForm* Intern::makeShrubbery(std::string target) { return new ShrubberyCreationForm(target); }

AForm *Intern::makeForm(std::string form_name, std::string _target)
{
	int pos;
	AForm *(Intern:: *methods[])(std::string target) = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
	std::string levels[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	pos = 0;
	while (form_name != levels[pos] && pos < 3)
		pos++;
	if (pos == 3)
	{
		std::cout << "couldn't find form" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << levels[pos] << " form" << std::endl;
	return (this->*methods[pos])(_target);
}
