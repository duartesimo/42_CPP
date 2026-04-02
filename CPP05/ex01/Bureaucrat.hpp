#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string &getName() const;
		int getGrade() const;

		void decrementGrade();
		void incrementGrade();
		void signForm(Form &form);

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
};
	std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif