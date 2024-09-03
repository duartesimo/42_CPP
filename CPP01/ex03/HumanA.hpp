#ifndef HUMANA_HPP_
# define HUMANA_HPP_

#include "Weapon.hpp"
#include <iostream>
#include <string>

//reference to weapon, uses original weapon object, no copy. If weapon object is changed humanA changes
class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack();
};

#endif