#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type)
{
	std::cout << "Animal: Name constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}
