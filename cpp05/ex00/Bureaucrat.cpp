#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(100) {}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "this is the name :" << name << std::endl;
	this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cp): name(cp.name), grade(cp.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->grade = obj.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::increment()
{
	if ((this->grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrement()
{
	if ((this->grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade is too high (below 1)!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade is too low (above 150)!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (os);
}