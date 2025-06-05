# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	std::cout << "\033[32m" << _name << " constructed " << "\033[0m" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[32m" << _name << " has crash!" << "\033[0m" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "\033[32m" << "My name is " << _name;
	std::cout << " and my ClapTrap name is " << ClapTrap::_name << "\033[0m" << std::endl;
}