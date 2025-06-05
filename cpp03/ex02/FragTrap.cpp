# include "ClapTrap.hpp"
# include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "\033[32m" << _name << " is not a ClapTrap, is a FragTrap " << "\033[0m" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 50;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[32m" << _name << " is over" << "\033[0m" << std::endl;
}

void FragTrap::attack(const std::string& target)
{

	if (_hitPoints == 0)
	{
		std::cout << "\033[31m" << "FragTrap is K.O. — attacking is impossible." << "\033[0m" << std::endl;
		return ;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "\033[31m" << "FragTrap has no more energy — attacking is impossible." << "\033[0m" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "\033[33m" << "FragTrap " << _name;
	std::cout << " attack " << target << " the attack inflicts ";
	std::cout << _attackDamage << " damage points." << "\033[0m" << std::endl;
}



void FragTrap::highFivesGuys()
{
		std::cout << "\033[34m" << "FragTrap "<< _name << " a High Fives with his ennemy." << "\033[32m" << std::endl;
}
