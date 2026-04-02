#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137), _target(target)
{
	//std::cout << "Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	//std::cout << "Copy of Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	//std::cout << "Shrubbery Creation Form assignment operator" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "Shrubbery Creation Form destroyed" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::ofstream file;
	file.open((_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (file.is_open())
	{
		file << "      /\\      " << std::endl;
		file << "     /\\*\\    " << std::endl;
		file << "    /\\O\\*\\    " << std::endl;
		file << "   /*/\\/\\/\\   " << std::endl;
		file << "  /\\O\\/\\*\\/\\  " << std::endl;
		file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file.close();
	}
	else
		std::cerr << "Error creating shrubbery file!" << std::endl;
}