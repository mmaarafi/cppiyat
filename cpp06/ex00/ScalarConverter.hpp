#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>

class ScalarConverter {
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cp);
		ScalarConverter &operator=(const ScalarConverter &obj);
		~ScalarConverter();
	public :
		static  void convert(std::string value);
};

