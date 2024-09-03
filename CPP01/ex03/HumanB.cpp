#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{}

void HumanB::setWeapon(const Weapon& weapon)
{
	_weapon = (Weapon*)&weapon;
}

void HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " doesn't have a weapon to attack." << std::endl;
}
