#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try {
		// Valid Form
		Intern intern;
		Bureaucrat bureaucrat("John", 5);

		AForm* form1 = intern.makeForm("presidential pardon", "Bill");
		if (form1) {
			bureaucrat.signForm(*form1);
			bureaucrat.executeForm(*form1);
			delete form1;
		}

		AForm* form2 = intern.makeForm("robotomy request", "Mitt");
		if (form2) {
			bureaucrat.signForm(*form2);
			bureaucrat.executeForm(*form2);
			delete form2;
		}

		AForm* form3 = intern.makeForm("shrubbery creation", "Dove");
		if (form3) {
			bureaucrat.signForm(*form3);
			bureaucrat.executeForm(*form3);
			delete form3;
		}

		// Invalid Form
		AForm* form4 = intern.makeForm("invalid form name", "Pat");
		if (form4) {
			bureaucrat.signForm(*form4);
			bureaucrat.executeForm(*form4);
			delete form4;
		}
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}