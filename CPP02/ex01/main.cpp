#include "Fixed.hpp"

int	main( void )
{

	//Ex: 3.75 is 11.11 in binary (00000011 11000000) and 11110000 in fixed point num with << 8 bits for fractional part (*256)

	Fixed a;
	Fixed const b( 10 ); //const = cant be modified after creation
	Fixed const c( 3.75f );
	Fixed const d( b );
	a = Fixed( 1234.4321f ); //Temporary object created

	// Print the objects with overloaded << operator
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	// Print the raw fixed-point values
	std::cout << "Raw value of a: " << a.getRawBits() << std::endl;
	std::cout << "Raw value of b: " << b.getRawBits() << std::endl;
	std::cout << "Raw value of c: " << c.getRawBits() << std::endl;
	std::cout << "Raw value of d: " << d.getRawBits() << std::endl;
	
	// Print the integer values
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	
	return (0);
}