#ifndef DIAMONDTRAP_HPP
	#define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap 
{
	//public:
	//protected:
	//private:

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI();

	private:
		std::string _name; // DiamondTrap name
};

#endif