#include "Utils.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Base class pointer pointing to different derived objects
Base* generate(void)
{
	int randVal = rand() % 3;
	if (randVal == 0)
		return new A;
	else if (randVal == 1)
		return new B;
	else
		return new C;
}

// Determines the actual type of an object at runtime using dynamic_cast, returns the ptr. Returns nullptr if doesnt find
// Dynamic_cast can only successfully cast a pointer to a type if that type is in the same class hierarchy
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
		std::cout << "Unknown" << std::endl;
}

// Returns a reference or if fails std::bad_cast; With Typeinfo (typeid(p) == typeid(A))
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception & e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception & e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception & e) {}

	std::cout << "Unknown" << std::endl;
}
