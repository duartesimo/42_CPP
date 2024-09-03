#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_clap_name")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	 std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name + "_clap_name")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap: Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	if(this != &other)
		 ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (_hitPoints <= 0)
		std::cout << "FragTrap: " << YELLOW << _name << " cannot request a high five" << RESET << " because " << RED << "it is dead!" << RESET << std::endl;
	else
		std::cout << "FragTrap: " << BLUE << _name << " requests a high five! ✋" << RESET << std::endl;
}