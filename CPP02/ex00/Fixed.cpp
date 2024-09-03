#include "Fixed.hpp"

Fixed::Fixed() : _fix_point_value(0)
{
	std::cout << "Default constructor called"  << std::endl;
};

// Fixed& = Reference to original fixed obj (not modified), const other (other not modified)
// *this =(copy assignement operator) object that is being constructed
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// prevent self-assignment
	if (this != &other)
		_fix_point_value = other.getRawBits();
	return (*this);
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

// wont modify the object
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fix_point_value);
};

// value cant be modified inside the function
void Fixed::setRawBits(int const value)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fix_point_value = value;
};