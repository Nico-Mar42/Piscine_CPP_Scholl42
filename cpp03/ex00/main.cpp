#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("Clappy");

	claptrap.attack("target1");
	claptrap.beRepaired(3);

	claptrap.takeDamage(5);
	claptrap.takeDamage(8);
	claptrap.attack("target1");

	return 0;
}