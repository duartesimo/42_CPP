#include "ClapTrap.hpp"

int	main()
{
	ClapTrap claptrap("Clappy");

	claptrap.takeDamage(4);
	claptrap.beRepaired(3);
	for (int i = 0; i < 12; i++)
		claptrap.attack("Enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(4);
	claptrap.takeDamage(1);
	claptrap.attack("Enemy");
	claptrap.beRepaired(3);

	return (0);
}