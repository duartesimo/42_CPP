#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap diamond("Diamond");

	diamond.attack("target");
	diamond.whoAmI();
	diamond.takeDamage(50);
	diamond.beRepaired(30);
	diamond.guardGate();
	diamond.highFivesGuys();

	return (0);
}