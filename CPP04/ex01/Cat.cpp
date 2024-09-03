#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) 
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain); // deep copy, not just the pointer, calls brain copy constructor: Brain brain2(brain1);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->_brain) = *(other._brain); // deep copy, calls brain assignment operator
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::setBrainIdea(int index, const std::string& idea)
{
	_brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const
{
	return _brain->getIdea(index);
}