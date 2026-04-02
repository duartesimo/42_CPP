#include "Bureaucrat.hpp"

int main()
{
	// Valid Bureaucrats
	try {
		Bureaucrat bureaucrat1("John", 1);
		Bureaucrat bureaucrat2("Doe", 150);

		std::cout << "Test 1: Valid Bureaucrats" << std::endl;
		std::cout << bureaucrat1 << std::endl;
		std::cout << bureaucrat2 << std::endl;
	} catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}

	// Incrementing Decrementing
	try {
		Bureaucrat bureaucrat3("Levy", 2);
		std::cout << "\nTest 2: Incrementing and decrementing grades" << std::endl;
		std::cout << bureaucrat3 << std::endl;

		bureaucrat3.incrementGrade();
		std::cout << "After increment: " << bureaucrat3 << std::endl;

		bureaucrat3.incrementGrade();
	} catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat4("Bob", 149);
		std::cout << bureaucrat4 << std::endl;

		bureaucrat4.decrementGrade();
		std::cout << "After decrement: " << bureaucrat4 << std::endl;

		bureaucrat4.decrementGrade();
	} catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}

	// Invalid grades
	try {
		std::cout << "\nTest 3: Creating Bureaucrats with invalid grades" << std::endl;
		Bureaucrat bureaucrat5("Invalid1", 0);
	} catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat6("Invalid2", 151);
	} catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}

	// Copy constructor / Assignment operator
	try {
		std::cout << "\nTest 4: Copy constructor and assignment operator" << std::endl;
		Bureaucrat bureaucrat7("Charlie", 50);
		Bureaucrat bureaucrat8(bureaucrat7);
		Bureaucrat bureaucrat9("Dummy", 100);

		bureaucrat9 = bureaucrat7;

		std::cout << "Original: " << bureaucrat7 << std::endl;
		std::cout << "Copied: " << bureaucrat8 << std::endl;
		std::cout << "Assigned: " << bureaucrat9 << std::endl;
	} catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}

	return 0;
}