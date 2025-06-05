#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap claptrap("Clappy");
	ScavTrap scavtrap("Scavvy");
	FragTrap fragtrap("Fraggy");

	// Test ClapTrap functions
	claptrap.attack("target1");
	claptrap.beRepaired(3);
	claptrap.takeDamage(5);
	claptrap.takeDamage(8); // Should deplete hit points
	claptrap.attack("target1"); // Should not attack (no HP)

	// Edge cases for ClapTrap
	claptrap.beRepaired(10); // Should not repair (no HP)
	claptrap.takeDamage(1);  // Should not take more damage (already at 0 HP)

	// Test ScavTrap functions
	scavtrap.attack("target2");
	scavtrap.beRepaired(5);
	scavtrap.takeDamage(4);
	scavtrap.guardGate(); // Specific to ScavTrap
	scavtrap.takeDamage(20); // Should deplete hit points
	scavtrap.attack("target3"); // Should not attack (no HP)
	scavtrap.guardGate(); // Should not guard (no HP)
	scavtrap.beRepaired(10); // Should not repair (no HP)

	// Test FragTrap functions
	fragtrap.attack("target4");
	fragtrap.beRepaired(7);
	fragtrap.takeDamage(10);
	fragtrap.highFivesGuys(); // Specific to FragTrap
	fragtrap.takeDamage(90); // Should deplete hit points
	fragtrap.attack("target5"); // Should not attack (no HP)
	fragtrap.highFivesGuys(); // Should not high five (no HP)
	fragtrap.beRepaired(15); // Should not repair (no HP)

	return 0;
}