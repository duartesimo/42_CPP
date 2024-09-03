#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class Phonebook
{
	private:
		int			_count;
		int		_index_replace;
		Contact		_contact_list[8];
	public:
		Phonebook();
		int		add_contact();
		int		select_contact();
		int		print_phonebook();
};

#endif