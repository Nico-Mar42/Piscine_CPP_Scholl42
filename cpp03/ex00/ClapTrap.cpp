#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "\033[32m" << "New challenger is comming, claptrap ";
	std::cout << this->_name << "is ready to fight" << "\033[0m" << std::endl;
	
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "\033[32m" << "New challenger is comming, claptrap ";
	std::cout << this->_name << "is ready to fight" << "\033[0m" << std::endl;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[32m" << "The fight is over, ClapTrap ";
	std::cout << this->_name << " is brought back to the box." << "\033[0m" << std::endl;}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0)
	{
		std::cout << "\033[31m" << "ClapTrap is K.O. — attacking is impossible." << "\033[0m" << std::endl;
		return ;
	}
	else if (this->_energyPoints)
	{
		std::cout << "\033[31m" << "ClapTrap has no more energy — attacking is impossible." << "\033[0m" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "\033[33m" << "ClapTrap " << this->_name;
	std::cout << " attack" << target << "\033[0m";
	std::cout << "The attack inflicts " << this->_attackDamage << " damage points." << "\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\033[31m" << "ClapTrap " << this->_name << " takes ";
	std::cout << amount << " points of damage." << "\033[0m" << std::endl;
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints = this->_hitPoints - amount;
	std::cout << "\033[32m" << "claptrap " << this->_name << " only has ";
	std::cout <<  this->_hitPoints << " hit points left." << "\033[0m" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << "\033[32m" << "claptrap " << this->_name << " is K.O." << "\033[32m" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 10)
		std::cout << "\033[34m" << "claptrap " << this->_name << " is already Repared" << "\033[32m" << std::endl;
	else
	{
		this->_energyPoints--;
		if (this->_hitPoints + amount >= 10)
			this->_hitPoints = 10;
		else
			this->_hitPoints += amount;
		std::cout << "\033[32m" << "claptrap " << this->_name << " Repaired itself for ";
		std::cout <<  amount << "hit points." << "\033[32m" << std::endl;
		if (this->_hitPoints == 10)
			std::cout << "\033[34m" << "claptrap " << this->_name << " is fully repaired" << "\033[32m" << std::endl;
		else
			std::cout << "\033[34m" << "claptrap " << this->_name << " now has ";
			std::cout << this->_hitPoints << " hit Points" << "\033[32m" << std::endl;
	}

}