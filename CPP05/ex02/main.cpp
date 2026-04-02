#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		// ShrubberyCreationForm
		Bureaucrat bureaucrat1("John", 5);
		ShrubberyCreationForm form1("home");

		std::cout << bureaucrat1 << std::endl;
		std::cout << form1 << std::endl;

		bureaucrat1.signForm(form1);
		bureaucrat1.executeForm(form1);
	} catch (const std::exception &error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}

	try {
		// RobotomyRequestForm
		Bureaucrat bureaucrat2("Bob", 45);
		RobotomyRequestForm form2("office");

		std::cout << bureaucrat2 << std::endl;
		std::cout << form2 << std::endl;

		bureaucrat2.signForm(form2);
		bureaucrat2.executeForm(form2);
	} catch (const std::exception &error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}

	try {
		// PresidentialPardonForm
		Bureaucrat bureaucrat3("Levy", 10);
		PresidentialPardonForm form3("road");

		std::cout << bureaucrat3 << std::endl;
		std::cout << form3 << std::endl;

		bureaucrat3.signForm(form3);
		bureaucrat3.executeForm(form3);
	} catch (const std::exception &error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}

	return 0;
}