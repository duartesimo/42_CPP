#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	// Subject Tests (smallest increment is 1/256 = 0.00390625)
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// Extra Tests
	// Comparison Tests
	Fixed const c(10);
	Fixed const d(20);

	std::cout << "\nComparison Tests:" << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;

	// Arithmetic Tests
	Fixed e(3.5f);
	Fixed f(2.5f);

	std::cout << "\nArithmetic Tests:" << std::endl;
	std::cout << "e + f: " << (e + f) << std::endl;
	std::cout << "e - f: " << (e - f) << std::endl;
	std::cout << "e * f: " << (e * f) << std::endl;
	std::cout << "e / f: " << (e / f) << std::endl;

	// Increment/Decrement Tests
	std::cout << "\nIncrement/Decrement Tests:" << std::endl;
	Fixed g(17);
	std::cout << "Initial g: " << g << std::endl;
	std::cout << "Pre-increment ++g: " << ++g << std::endl;
	std::cout << "Post-increment g++: " << g++ << std::endl;
	std::cout << "After post-increment g: " << g << std::endl;
	std::cout << "Pre-decrement --g: " << --g << std::endl;
	std::cout << "Post-decrement g--: " << g-- << std::endl;
	std::cout << "After post-decrement g: " << g << std::endl;

	// Min/Max Tests
	Fixed i(42);
	Fixed h(-42);
	std::cout << "\nMin/Max Tests:" << std::endl;
	std::cout << "Min: " << Fixed::min(h, i) << std::endl;
	std::cout << "Max: " << Fixed::max(50, -50) << std::endl;

	return (0);
}