#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form created." << std::endl;
}

Form::Form(const Form &other): _name(other._name), _isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy of form created." << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator." << std::endl;
	if (this != &other)
		 _isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destroyed." << std::endl;
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &ostream, const Form &form)
{
	ostream << "Form " << form.getName()
		<< ", Signed: " << (form.isSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form.getGradeToSign()
		<< ", Grade to execute: " << form.getGradeToExecute();
	return ostream;
}