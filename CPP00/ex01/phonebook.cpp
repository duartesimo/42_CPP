#include "main.hpp"

Phonebook::Phonebook()
{
	_count = 0;
	_index_replace = 0;
}

int	Phonebook::add_contact()
{
	if (_count < 8)
	{
		if (_contact_list[_count].fill_info(_count + 1) < 0)
			return (-1);
		_count++;
	}
	else
	{
		if (_contact_list[_index_replace].fill_info(_index_replace + 1) < 0)
        		return (-1);
		_index_replace = (_index_replace + 1) % 8;
		std::cout << "The oldest contact was replaced with the new one." << std::endl;
	}
	return (0);
}

int	Phonebook::select_contact()
{
	int		flag = 1;
	int		index_num;
	std::string	index;

	std::cout << "Please select an index : ";
	std::getline(std::cin, index);
	for (size_t i = 0 ; i < index.length(); i++)
		if (std::isdigit(index[i]) == 0)
			flag = 0;
	index_num = atoi(index.c_str());
	if (flag == 0 || std::cin.fail() || index_num > _count || index_num <= 0)
	{
		std::cout << "Invalid index value!" << std::endl;
		return (1);
	}
	_contact_list[index_num - 1].print_contact();
	return (0);
}

int	Phonebook::print_phonebook()
{
	if (_count == 0)
		std::cout << "Phonebook is empty!" << std::endl;
	else
	{
		std::cout << "│     INDEX│FIRST NAME│ LAST NAME│  NICKNAME│" << std::endl;
		for (int i = 0 ; i < _count ; i++)
			_contact_list[i].print_list();
		select_contact();
	}
	return (0);
}