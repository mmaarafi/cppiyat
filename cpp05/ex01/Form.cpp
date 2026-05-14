#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(): name("default"), sign(false), grade_s(100), grade_e(100) {}

Form::Form(std::string _name, int _grade_s, int _grade_e): name(_name), sign(false), grade_s(_grade_s), grade_e(_grade_e)
{
	if (grade_s < 1)
		throw Form::GradeTooHighException();
	if (grade_s > 150)
		throw Form::GradeTooLowException();
	if (grade_e < 1)
		throw Form::GradeTooHighException();
	if (grade_e > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &cp): name(cp.name), sign(cp.sign), grade_s(cp.grade_s), grade_e(cp.grade_e) {}

Form &Form::operator=(const Form &obj)
{
	this->sign = obj.sign;
	return (*this);
}

Form::~Form() {}

const std::string Form::getName() const
{
	return (this->name);
}

int Form::getGradeE() const
{
	return (this->grade_e);
}

int Form::getGradeS() const
{
	return (this->grade_s);
}

bool Form::getSign() const
{
	return (this->sign);
}

void Form::beSigned(const Bureaucrat &obj)
{
	if (this->sign == false)
	{
		if (obj.getGrade() > grade_s)
			throw Form::GradeTooLowException();
		this->sign = true;
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << ", Form grade_e " << obj.getGradeE() << ", Form grade_s " << obj.getGradeS() << std::endl;
	return (os);
}