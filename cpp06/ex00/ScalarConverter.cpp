#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &cp) 
{
	(void) cp;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void) obj;
	return (*this);
}

int count_occurences(std::string value, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(value[i])
	{
		if (value[i] == c)
			count++;
		i++;
	}
	return (count);
}

int detectType(std::string value)
{
	int pos;
	if (value == "+inff" || value == "-inff" || value == "nanf" || value == "inff")
		return (5);
	if (value == "+inf" || value == "-inf" || value == "nan" || value == "inf")
		return (5);
	//*********** CHARS
	if (value.length() == 1 && !isdigit(value[0]))
		return (1);
	//*********** INTEGERS
	if (value[0] == '+' || value[0] == '-' || isdigit(value[0]))
	{
		if ((value[0] == '+' || value[0] == '-') && value.length() == 1)
			return (0);
		if (value.find('.') == std::string::npos && value[value.length() - 1] != 'f')
		{
			pos = 1;
			while(value[pos])
			{
				if (!isdigit(value[pos]))
					return (0);
				pos++;
			}
			return (2);
		}
	}
	//*********** FLOATS
	if (value[0] == '+' || value[0] == '-' || isdigit(value[0]) || value[0] == '.')
	{
		if ((value[0] == '+' || value[0] == '-') && value.length() == 1)
			return (0);
		if (value.find('.') != std::string::npos && value[value.length() - 1] == 'f')
		{
			if (count_occurences(value, '.') != 1 || count_occurences(value, 'f') != 1)
				return (0);
			pos = 1;
			while(value[pos])
			{
				if (value[pos] == '.' || value[pos] == 'f')
				{
					pos++;
					continue ;
				}
				else if (!isdigit(value[pos]))
					return (0);
				pos++;
			}
			return (3);
		}
	}
	//*********** DOUBLES
	if (value[0] == '+' || value[0] == '-' || isdigit(value[0]) || value[0] == '.')
	{
		if ((value[0] == '+' || value[0] == '-') && value.length() == 1)
			return (0);
		if (value.find('.') != std::string::npos)
		{
			if (count_occurences(value, '.') != 1)
				return (0);
			if (value[value.length() - 1] == '.')
			{
				if (!isdigit(value[value.length() - 2]))
					return (0);
			}
			pos = 1;
			while(value[pos])
			{
				if (value[pos] == '.')
				{
					pos++;
					continue ;
				}
				else if (!isdigit(value[pos]))
					return (0);
				pos++;
			}
			return (4);
		}
	}
	return (0);
}

void ScalarConverter::convert(std::string value)
{
	int val = detectType(value);

	if (val == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (val == 5)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::string doubleStr = value;
		if (doubleStr == "+inff" || doubleStr == "-inff" || doubleStr == "nanf")
			doubleStr = doubleStr.substr(0, doubleStr.length() - 1);
		std::string floatStr = doubleStr + "f";
		std::cout << "float: " << floatStr << std::endl;
		std::cout << "double: " << doubleStr << std::endl;
		return;
	}
	char c = 0;
	long l = 0;
	float f = 0.0f;
	double d = 0.0;
	switch (val) {
		case 1:
			c = value[0];
			l = static_cast<long>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case 2:
			l = std::strtol(value.c_str(), NULL, 10);
			c = static_cast<char>(l);
			f = static_cast<float>(l);
			d = static_cast<double>(l);
			break;
		case 3:
			d = std::strtod(value.c_str(), NULL);
			f = static_cast<float>(d);
			l = static_cast<long>(d);
			c = static_cast<char>(d);
			break;
		case 4:
			d = std::strtod(value.c_str(), NULL);
			f = static_cast<float>(d);
			l = static_cast<long>(d);
			c = static_cast<char>(d);
			break;
	}
	if (l < 0 || l > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(l) << std::endl;
	if (l == d)
	{
		std::cout << std::fixed << std::setprecision(1);
	}
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;;
}