#include "main.hpp"

Contact::Contact()
{
	_contact_index = -1;
	for (int i = 1 ; i < 5 ; i++)
		_information[i] = std::string();
	_field[0] = "First Name";
	_field[1] = "Last Name";
	_field[2] = "Nickname";
	_field[3] = "Phone Number";
	_field[4] = "Darkest Secret";
}

static bool	isOnlyWhitespace(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] != ' ')
			return (false);
	return (true);
}

static bool	isOnlyDigits(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

int	Contact::fill_info(int index)
{
	_contact_index = index;
	for (int i = 0 ; i < 5 ; i++)
	{
		while (1)
		{
			std::cout << _field[i] << " : ";
			std::getline(std::cin, _information[i]);
			if (std::cin.eof())
				return (-1);
			if (_information[i].empty() || isOnlyWhitespace(_information[i]))
				std::cout << "Value must not be empty!" << std::endl;
			else if (i == 3 && !isOnlyDigits(_information[i]))
				std::cout << "Phone number must contain only digits!" << std::endl;
			else
				break;
		}
	}
	return (0);
}

void	Contact::print_list()
{
	std::cout << "│" << std::setw(10) << _contact_index;
	for (int i = 0 ; i < 3 ; i++)
	{
		if (_information[i].size() <= 10)
			std::cout << "│" << std::setw(10) << _information[i];
		else
			std::cout << "│" << _information[i].substr(0, 9) << ".";
	}
	std::cout << "│" << std::endl;
}

void	Contact::print_contact()
{
	for (int i = 0 ; i < 5 ; i++)
		std::cout << _field[i] << " : " << _information[i] << std::endl;
}