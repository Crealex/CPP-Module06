
#include "colors.h"
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
std::cout << GREEN << "Default ScalarConverter constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
std::cout << BLUE << "Copy ScalarConverter constructor called" << RESET << std::endl;
}

ScalarConverter::~ScalarConverter()
{
std::cout << RED << "ScalarConverter destructor called" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
std::cout << LIGHT_BLUE << "ScalarConverter assignment operator called" << RESET << std::endl;
}


// idea for dispalying .0 (and .0f)
//std:cout << value << value % 1 ? std::endl : ".0" << std::endl;