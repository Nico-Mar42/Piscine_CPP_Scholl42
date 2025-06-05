#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{

	// Test ClapTrap functions
	std::cout << "\033[4;37m" << "Testing ClapTrap functions." << "\033[0m" << std::endl;
	ClapTrap claptrap("Clappy");
	claptrap.attack("target1");
	claptrap.beRepaired(3);
	claptrap.takeDamage(5);
	claptrap.takeDamage(8); // Should deplete hit points
	claptrap.attack("target1"); // Should not attack (no HP)
	claptrap.beRepaired(10); // Should not repair (no HP)
	claptrap.takeDamage(1);  // Should not take more damage (already at 0 HP)
	std::cout << "\033[37m" << "End of ClapTrap tests." << "\033[0m" << std::endl << std::endl;

	// Test ScavTrap functions
	std::cout << "\033[4;37m" << "Testing ScavTrap functions." << "\033[0m" << std::endl;
	ScavTrap scavtrap("Scavvy");
	scavtrap.attack("target2");
	scavtrap.beRepaired(5);
	scavtrap.takeDamage(4);
	scavtrap.guardGate(); // Specific to ScavTrap
	scavtrap.takeDamage(20); // Should deplete hit points
	scavtrap.attack("target3"); // Should not attack (no HP)
	scavtrap.guardGate(); // Should not guard (no HP)
	scavtrap.beRepaired(10); // Should not repair (no HP)
	std::cout << "\033[37m" << "End of ScavTrap tests." << "\033[0m" << std::endl << std::endl;

	// Test FragTrap functions
	std::cout << "\033[4;37m" << "Testing FragTrap functions." << "\033[0m" << std::endl;
	FragTrap fragtrap("Fraggy");
	fragtrap.attack("target4");
	fragtrap.beRepaired(7);
	fragtrap.takeDamage(10);
	fragtrap.highFivesGuys(); // Specific to FragTrap
	fragtrap.takeDamage(90); // Should deplete hit points
	fragtrap.attack("target5"); // Should not attack (no HP)
	fragtrap.highFivesGuys(); // Should not high five (no HP)
	fragtrap.beRepaired(15); // Should not repair (no HP)
	fragtrap.takeDamage(1); // Should not take more damage (already at 0 HP)
	std::cout << "\033[37m" << "End of FragTrap tests." << "\033[0m" << std::endl << std::endl;

	// Test DiamondTrap functions
	std::cout << "\033[4;37m" << "Testing DiamondTrap functions." << "\033[0m" << std::endl;

	DiamondTrap diamondtrap("Diamondy");
	diamondtrap.attack("target6");
	diamondtrap.whoAmI(); // Should print its name and ClapTrap name
	diamondtrap.beRepaired(10);
	diamondtrap.takeDamage(15);
	diamondtrap.attack("target7"); // Should not attack (no HP)
	diamondtrap.whoAmI(); // Should not print (no HP)
	diamondtrap.beRepaired(5); // Should not repair (no HP)
	diamondtrap.takeDamage(100); // Should deplete hit points
	diamondtrap.attack("target8"); // Should not attack (no HP)
	diamondtrap.whoAmI(); // Should not print (no HP)
	std::cout << "\033[37m" << "End of the program." << "\033[0m" << std::endl << std::endl;

	return 0;
}