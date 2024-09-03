#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
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
	/* ScavTrap scavtrap("Scavvy");

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
	scavtrap.attack("Intruder"); */

	// FragTrap Tests
	FragTrap fragtrap("Fraggy");

	fragtrap.takeDamage(50);
	fragtrap.beRepaired(40);
	fragtrap.attack("Bandit");
	fragtrap.highFivesGuys();
	fragtrap.takeDamage(150);
	fragtrap.highFivesGuys();
	fragtrap.attack("Bandit");
	fragtrap.beRepaired(15);
}