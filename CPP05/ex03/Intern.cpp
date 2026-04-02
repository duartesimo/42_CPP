#include "Intern.hpp"

Intern::Intern()
{
    //std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &other)
{
	//std::cout << "Copy of Intern created" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	//std::cout << "Intern assignment operator" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern()
{
	//std::cout << "Intern destroyed" << std::endl;
}

AForm* makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* (*formCreators[])(const std::string&) = {
		makePresidentialPardonForm,
		makeRobotomyRequestForm,
		makeShrubberyCreationForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "Error: Form '" << formName << "' not found!" << std::endl;
	return NULL;
}