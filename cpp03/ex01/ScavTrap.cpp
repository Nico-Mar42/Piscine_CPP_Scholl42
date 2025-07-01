# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "\033[32m" << _name << " is a Scavtrap " << "\033[0m" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[32m" << _name << " Run ending program" << "\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{

	if (_hitPoints == 0)
	{
		std::cout << "\033[31m" << "test  ScavTrap is K.O. — attacking is impossible." << "\033[0m" << std::endl;
		return ;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "\033[31m" << "test ScavTrap has no more energy — attacking is impossible." << "\033[0m" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "\033[33m" << "test ScavTrap " << _name;
	std::cout << " attack " << target << " the attack inflicts ";
	std::cout << _attackDamage << " damage points." << "\033[0m" << std::endl;
}



void ScavTrap::guardGate()
{
		std::cout << "\033[34m" << "Scavtrap "<< _name << " enter in gate keeper mode." << "\033[32m" << std::endl;
}
