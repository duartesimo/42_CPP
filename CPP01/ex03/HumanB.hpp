#ifndef HUMANB_HPP_
# define HUMANB_HPP_

#include "Weapon.hpp"
#include <iostream>
#include <string>

//pointer to weapon, starts unarmed (nullptr). can check if human has weapon
class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		HumanB(std::string name);
		void setWeapon(const Weapon& weapon);
		void attack();
};

#endif