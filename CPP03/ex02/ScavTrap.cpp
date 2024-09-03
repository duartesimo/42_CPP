#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "Default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guarding = false;
	 std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guarding = false;
	std::cout << "ScavTrap: Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	if(this != &other)
		 ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
		std::cout << "ScavTrap: " << YELLOW << _name << " is not able to attack" << RESET " because" << RED << " it is dead!" << RESET << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap: " << YELLOW << _name << " is not able to attack" << RESET " because" << " it has no energy left!" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap: " << PURPLE << _name << " does a really big and mighty attack against " << target << RESET << ", causing " << _attackDamage << " points of damage!" << " Remaining energy points: " << _energyPoints << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap: " << YELLOW << _name << " can't guard the gate" << RESET << " because " << RED << "it is dead!" << RESET << std::endl;
		return;
	}
	if (!_guarding)
	{
		_guarding = true;
		std::cout << "ScavTrap: " << GREEN << _name << " is now in gatekeeping mode!" << RESET << std::endl;
	}
	else
		std::cout << "ScavTrap: " << YELLOW << _name << " was already guarding the gate!" << RESET << std::endl;
}