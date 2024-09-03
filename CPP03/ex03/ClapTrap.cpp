#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	 std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
		std::cout << "ClapTrap: " << YELLOW << _name << " cannot attack" << RESET " because" << RED << " it is dead!" << RESET << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap: " << YELLOW << _name << " cannot attack" << RESET " because" << " it has no energy left!" << std::endl;
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap: " << PURPLE << _name << " attacks " << target << RESET << ", causing " << _attackDamage << " points of damage!" << " Remaining energy points: " << _energyPoints << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap: " << RED << _name << " is already dead, please stop!" << RESET << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap: " << RED << _name << " takes " << amount << " points of damage! " << RESET;
	if (_hitPoints > 0)
		std::cout << "Remaining hit points: " << _hitPoints << std::endl;
	else
		std::cout << "\nClapTrap: " << RED << _name << " is dead!" << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap: " << GREEN << _name << " repairs itself, restoring " 
			<< amount << " hit points! " << RESET << "Remaining hit points: " << _hitPoints << ", Remaining energy points: " << _energyPoints << std::endl;
	}
	else if (_hitPoints > 0 && _energyPoints <= 0)
		std::cout << "ClapTrap: " << YELLOW << _name << " has no energy left" << RESET " to repair itself!" << std::endl;
	else
		std::cout << "ClapTrap: " << YELLOW << _name << " cannot repare itself" << RESET << " because" << RED << " it is dead!" << RESET << std::endl;
}