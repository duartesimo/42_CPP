#include "main.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	str;

	while (1)
	{
		std::cout << "Enter a command, (ADD, SEARCH OR EXIT): ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (-1);
		if (str == "ADD")
		{
			if (phonebook.add_contact() < 0)
				break ;
		}
		else if (str == "SEARCH")
		{
			if (phonebook.print_phonebook() < 0)
				break ;
		}
		else if (str == "EXIT")
			break ;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}