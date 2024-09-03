#include "Fixed.hpp"

Fixed::Fixed() : _fix_point_value(0)
{ 
	std::cout << "Default constructor called"  << std::endl; 
}

Fixed::Fixed(const int intValue)
{ 
	std::cout << "Int constructor called"  << std::endl; 
	_fix_point_value = intValue << Fixed::_fractional_bits; // Convert integer to fixed-point (also stored as an int)
}

Fixed::Fixed(const float floatValue)
{ 
	std::cout << "Float constructor called"  << std::endl;
	_fix_point_value = roundf(floatValue * (1 << Fixed::_fractional_bits)); // Can only bitshift directly in ints
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fix_point_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (_fix_point_value);
}

void Fixed::setRawBits(int const value)
{
	_fix_point_value = value;
}

float Fixed::toFloat() const
{
	return ( (float)_fix_point_value / (1 << Fixed::_fractional_bits) );
}

int Fixed::toInt() const
{
	return ( _fix_point_value >> Fixed::_fractional_bits );
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}