#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact
{
	private:
		int		_contact_index;
		std::string	_information[5];
		std::string	_field[5];
	public:
		Contact();
		int	fill_info(int index);
		void	print_list();
		void	print_contact();
};

#endif