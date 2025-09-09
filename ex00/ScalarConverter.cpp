
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
		if (!isdigit(str[i]) && !(i == 0 && (str[i] == '-' ||  str[i] == '+')))
			return (false);
	}
	return (true);
}

bool ScalarConverter::_isFloat(std::string const &str)
{
	size_t point = str.find('.', 0);
	int l = str.length();

	if (point > str.length())
		return (false);


	if (str[l - 1] != 'f')
		return (false);
	for (size_t i = 0; i < str.length() - 1; i++)
	{
		if (!isdigit(str[i]) && i != point && !(i == 0 && (str[i] == '-' ||  str[i] == '+')))
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
	if (point > str.length())
		return (false);

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && i != point && !(i == 0 && (str[i] == '-' ||  str[i] == '+')))
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

// *** PRINT DECIMAL NUMBERS ***

void ScalarConverter::_printFloat(float const f)
{
	std::string decimal = f - static_cast<int>(f) ? "f" : ".0f";

	std::cout << CYAN << "float: " << f << decimal << RESET << std::endl;
}

void ScalarConverter::_printDouble(double const d)
{
	std::string decimal = d - static_cast<int>(d) ? "" : ".0";

	std::cout << YELLOW << "double: " << d << decimal << RESET << std::endl;
}

// *** DISPLAY RESULT

void ScalarConverter::_displayResult(int i, char c, float f, double d)
{
	if (isprint(c))
		std::cout << GREEN << "char: '" << c << "'" << RESET << std::endl;
	else if (isascii(c))
		std::cout << GREEN << "char: Non displayable" << RESET << std::endl;
	else
		std::cout << GREEN << "char: Impossible" << RESET << std::endl;
	std::cout << BLUE << "int: " << i << RESET << std::endl;
	_printFloat(f);
	_printDouble(d);
}

// *** CONVERTER ***

void ScalarConverter::_convertFromChar(std::string const &str)
{
	char	c = str[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	_displayResult(i, c, f, d);
}

void ScalarConverter::_convertFromInt(std::string const &str)
{
	int		i = std::atoi(str.c_str());
	char	c = i <= 127 ? static_cast<char>(i) : static_cast<int>(-1);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	_displayResult(i, c, f, d);
}

void ScalarConverter::_convertFromFloat(std::string const &str)
{
	float	f = std::atof(str.c_str());
	int		i = static_cast<int>(f);
	char	c = i <= 127 ? static_cast<char>(f) : static_cast<int>(-1);
	double	d = static_cast<double>(f);

	_displayResult(i, c, f, d);
}

void ScalarConverter::_convertFromDouble(std::string const &str)
{
	double	d = std::atof(str.c_str());
	char	c = d <= 127 ? static_cast<char>(d) : static_cast<char>(-1);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	_displayResult(i, c, f, d);
}

void ScalarConverter::_convertFromSpecialFloat(std::string const &str)
{
	std::cout << GREEN << "char: Impossible" << RESET << std::endl;
	std::cout << BLUE << "int: Impossible" << RESET << std::endl;
	std::cout << CYAN << "float: " << str << RESET << std::endl;
	std::cout << YELLOW << "double: " << str.substr(0, str.length() - 1) << RESET <<std::endl;
}

void ScalarConverter::_convertFromSpecialDouble(std::string const &str)
{
	std::cout << GREEN << "char: Impossible" << RESET << std::endl;
	std::cout << BLUE << "int: Impossible" << RESET << std::endl;
	std::cout << CYAN << "float: " << str + 'f' << RESET << std::endl;
	std::cout << YELLOW << "double: " << str << RESET << std::endl;
}

void ScalarConverter::convert(std::string const &str)
{
	if (_isChar(str))
		_convertFromChar(str);
	else if (_isInt(str))
		_convertFromInt(str);
	else if (_isDouble(str))
		_convertFromDouble(str);
	else if (_isFloat(str))
		_convertFromFloat(str);
	else if (_isSpecialFloat(str))
		_convertFromSpecialFloat(str);
	else if (_isSpecialDouble(str))
		_convertFromSpecialDouble(str);
	else
		std::cerr << RED << "Not a right type!" << RESET << std::endl;
}