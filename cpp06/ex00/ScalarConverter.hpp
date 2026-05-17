#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>

class ScalarConverter {
	private :
		virtual void method() const = 0;
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cp);
		ScalarConverter &operator=(const ScalarConverter &obj);
		~ScalarConverter();
		static  void convert(std::string value);
};

