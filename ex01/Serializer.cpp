
#include "colors.h"
#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Default Serializer constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &cpy)
{
	std::cout << BLUE << "Copy Serializer constructor called" << RESET << std::endl;
	(void)cpy;
}

Serializer::~Serializer()
{
std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	(void)rhs;
	std::cout << LIGHT_BLUE << "Serializer assignment operator called" << RESET << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
