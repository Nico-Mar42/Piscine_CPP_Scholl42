#ifndef CLAPTRAP_HPP
	#define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include "ScavTrap.hpp"

class ClapTrap
{
	//public:
	//protected:
	//private:

	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
};

#endif