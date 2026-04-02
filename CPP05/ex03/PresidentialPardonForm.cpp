#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", 25, 5), _target(target)
{
	//std::cout << "Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{
	//std::cout << "Copy of Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	//std::cout << "Presidential Pardon Form assignment operator" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "Presidential Pardon Form destroyed" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}