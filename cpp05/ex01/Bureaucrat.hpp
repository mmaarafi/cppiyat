#pragma once

#include <iostream>
#include <string>
#include <exception>

class Form;
class Bureaucrat {
	private :
		const std::string	name;
		int					grade;
	public :
		Bureaucrat();
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &cp);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();
		const std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void signForm(Form &obj);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(); // throw at the end promise that this function will not throw any exceptions
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
