

//#include <ctime>
#include <cstdlib>
#include "Base.hpp"

Base *generate()
{
	srand(time(0));
	int num;

	num = rand() % 3;

	std::cout << BLUE << "generation of new class..." << RESET << std::endl;
	switch (num)
	{
	case 0:
		std::cout << "Class A generated" << std::endl;
		return (new A);
	case 1:
		std::cout << "Class B generated" << std::endl;
		return (new B);
	case 2:
		std::cout << "Class C generated" << std::endl;
		return (new C);
	default:
		std::cout << "Error with the generation of newest class" << std::endl;
		return (NULL);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This is a A class! (pointer)" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Is a B class! (pointer)" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Is a C class! (pointer)" << std::endl;
	else
		std::cout << "Is not a good class!" << std::endl;
}

void identify(Base &p)
{
	try
	{
		Base &base = dynamic_cast<A&>(p);
		std::cout << "This is a A class! (reference)" << std::endl;
		(void)base;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}
	try
	{
		Base &base = dynamic_cast<B&>(p);
		std::cout << "This is a B class! (reference)" << std::endl;
		(void)base;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}
	try
	{
		Base &base = dynamic_cast<C&>(p);
		std::cout << "This is a C class! (reference)" << std::endl;
		(void)base;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}
}
