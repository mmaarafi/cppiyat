#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class AForm {
	private :
		const std::string	name;
		bool				sign;
		const int			grade_s;
		const int			grade_e;
	public :
		AForm();
		AForm(std::string _name, int _grade_s, int _grade_e);
		AForm(const AForm &cp);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();
		const std::string getName() const;
		int getGradeE() const;
		int getGradeS() const;
		bool getSign() const;
		void beSigned(const Bureaucrat &obj);
		void execute(Bureaucrat const & executor) const;
		virtual void performAction() const = 0;
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(); // throw at the end promise that this function will not throw any exceptions
		};
		class AFormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);
