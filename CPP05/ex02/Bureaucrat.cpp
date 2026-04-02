#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if(this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::signForm(AForm &aform)
{
	try {
		aform.beSigned(*this);
		std::cout << _name << " signed " << aform.getName() << std::endl;
	} catch (const std::exception &error) {
		std::cout << _name << " couldn't sign " << aform.getName() << " because " << error.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try {
		form.execute(*this); 
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (const std::exception &error) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << error.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Bureaucrat grade too low! Minimum grade is 150.";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Bureaucrat grade too high! Maximum grade is 1.";
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return ostream;
}
