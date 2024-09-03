#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int		_fix_point_value;
		static const int _fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const value);
		float toFloat() const;
		int toInt() const;
};
	std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);

#endif