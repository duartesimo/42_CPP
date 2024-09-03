#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	// Claptrap Tests
	/* ClapTrap claptrap("Clappy");

	claptrap.takeDamage(4);
	claptrap.beRepaired(3);
	for (int i = 0; i < 12; i++)
		claptrap.attack("Enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(4);
	claptrap.takeDamage(1);
	claptrap.attack("Enemy");
	claptrap.beRepaired(3); */

	// Scavtrap Tests
	ScavTrap scavtrap("Scavvy");

	scavtrap.takeDamage(30);
	scavtrap.beRepaired(20);
	for (int i = 0; i < 55; i++)
		scavtrap.attack("Intruder");
	scavtrap.takeDamage(50);
	scavtrap.beRepaired(10);
	scavtrap.guardGate();
	scavtrap.guardGate();
	scavtrap.takeDamage(50);
	scavtrap.guardGate();
	scavtrap.attack("Intruder");

	return (0);
}