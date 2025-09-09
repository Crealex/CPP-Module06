
#include "colors.h"
#include "Serializer.hpp"

Serializer::Serializer():
{
std::cout << GREEN << "Default Serializer constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &cpy)
{
std::cout << BLUE << "Copy Serializer constructor called" << RESET << std::endl;
}

Serializer::~Serializer()
{
std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
std::cout << LIGHT_BLUE << "Serializer assignment operator called" << RESET << std::endl;
}

