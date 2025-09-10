
#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include "colors.h"

class Base
{
private:

public:
	virtual ~Base() {};
};

// *** CHILD CLASSES ***

class A: public Base {};
class B: public Base {};
class C: public Base {};

// *** FUNCTIONS ***

Base *generate();
void identify(Base *p);
void identify(Base &p);




#endif
