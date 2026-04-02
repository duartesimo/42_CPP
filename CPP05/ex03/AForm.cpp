#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	//std::cout << "Form created." << std::endl;
}

AForm::AForm(const AForm &other): _name(other._name), _isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	//std::cout << "Copy of form created." << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	//std::cout << "Form assignment operator." << std::endl;
	if (this != &other)
		 _isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
	//std::cout << "Form destroyed." << std::endl;
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &ostream, const AForm &aform)
{
	ostream << "Form " << aform.getName()
		<< ", Signed: " << (aform.isSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << aform.getGradeToSign()
		<< ", Grade to execute: " << aform.getGradeToExecute();
	return ostream;
}