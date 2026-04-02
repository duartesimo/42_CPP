#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		// Valid Form and Bureaucrat
		Bureaucrat bureaucrat1("John", 5);
		Form form1("Tax Form", 10, 20);

		std::cout << bureaucrat1 << std::endl;
		std::cout << form1 << std::endl;

		bureaucrat1.signForm(form1);
		std::cout << form1 << std::endl;

		// Bureaucrat insufficient grade
		Bureaucrat bureaucrat2("Bob", 15);
		bureaucrat2.signForm(form1);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		// Invalid Form
		Form form2("Invalid Form", 0, 10);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}