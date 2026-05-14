#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class Form {
	private :
		const std::string	name;
		bool				sign;
		const int			grade_s;
		const int			grade_e;
	public :
		Form();
		Form(std::string _name, int _grade_s, int _grade_e);
		Form(const Form &cp);
		Form &operator=(const Form &obj);
		~Form();
		const std::string getName() const;
		int getGradeE() const;
		int getGradeS() const;
		bool getSign() const;
		void beSigned(const Bureaucrat &obj);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(); // throw at the end promise that this function will not throw any exceptions
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
