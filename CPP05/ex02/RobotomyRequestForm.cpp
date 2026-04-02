#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", 72, 45), _target(target)
{
	std::cout << "Robotomy Request Form created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "Copy of Robotomy Request Form created" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Robotomy Request Form assignment operator" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destroyed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::cout << "* Some Drilling Noises *" << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized succesfully" << std::endl;
	else
		std::cout << "The robotomy failed on " << _target << std::endl;
}