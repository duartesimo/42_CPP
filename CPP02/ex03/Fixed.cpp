#include "Fixed.hpp"

Fixed::Fixed() : _fix_point_value(0)
{}

Fixed::Fixed(const int intValue)
{ 
	_fix_point_value = intValue << Fixed::_fractional_bits;
}

Fixed::Fixed(const float floatValue)
{ 
	_fix_point_value = roundf(floatValue *(1 << Fixed::_fractional_bits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_fix_point_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_fix_point_value > other._fix_point_value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_fix_point_value >= other._fix_point_value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_fix_point_value < other._fix_point_value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_fix_point_value <= other._fix_point_value);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_fix_point_value == other._fix_point_value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_fix_point_value != other._fix_point_value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other._fix_point_value == 0)
	{
		std::cerr << "Can't divide by zero!" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	++(this->_fix_point_value);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fix_point_value++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	--(this->_fix_point_value);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fix_point_value--;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
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