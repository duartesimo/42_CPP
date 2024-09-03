#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain); // deep copy, not just a copy of the pointer, calls brain copy constructor
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->_brain) = *(other._brain); // deep copy, calls brain assignment operator
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

void Dog::setBrainIdea(int index, const std::string& idea)
{
	_brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const
{
	return _brain->getIdea(index);
}