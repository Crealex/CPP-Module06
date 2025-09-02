
#include "colors.h"
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "Default ScalarConverter constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
	std::cout << BLUE << "Copy ScalarConverter constructor called" << RESET << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destructor called" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	std::cout << LIGHT_BLUE << "ScalarConverter assignment operator called" << RESET << std::endl;
	return (*this);
}

bool ScalarConverter::_isChar(std::string const &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (true);
	return (false);
}

// *** CHECK TYPE ***

bool ScalarConverter::_isInt(std::string const &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::_isFloat(std::string const &str)
{
	int l = str.length();

	std::cout << "str[l]: " << str[l] << std::endl;
	if (str[l - 1] != 'f')
		return (false);
	for (size_t i = 0; i < str.length() - 1; i++)
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
	}
	return (true);
}

bool ScalarConverter::_isSpecialFloat(std::string const &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	return (false);
}

bool ScalarConverter::_isDouble(std::string const &str)
{
	size_t point = str.find('.', 0);
	std::cout << point << std::endl;
	if (point == 0)
		return (false);

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && i != point)
			return (false);
	}
	return (true);
}

bool ScalarConverter::_isSpecialDouble(std::string const &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	return (false);
}

// *** CONVERTER ***

void ScalarConverter::convert(std::string const &str)
{
	if (_isChar(str))
		std::cout << "is char" << std::endl;
	else if (_isInt(str))
		std::cout << "is int" << std::endl;
	else if (_isDouble(str))
		std::cout << "is double" << std::endl;
	else if (_isFloat(str))
		std::cout << "is float" << std::endl;
	else if (_isSpecialFloat(str))
		std::cout << "is special float" << std::endl;
	else if (_isSpecialDouble(str))
		std::cout << "is special double" << std::endl;
	else
		std::cout << "not the right type" << std::endl;
}