#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{}

//Reference to string _type, original string if Weapon. Const cant modify
const std::string& Weapon::getType()
{
	return (_type);
}

void Weapon::setType(std::string newtype)
{
	_type = newtype;
}