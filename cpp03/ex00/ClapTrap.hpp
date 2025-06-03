#ifndef FIXED_HPP
	#define FIXED_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>
# include <sstream>

class ClapTrap
{
	//public:
	//protected:
	//private:

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
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