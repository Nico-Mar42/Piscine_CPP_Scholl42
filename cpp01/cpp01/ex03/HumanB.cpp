#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void HumanB::set_weapon(Weapon& W_type)
{
	this->WeaponB = &W_type;
}

void HumanB::attack()
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	if (WeaponB == NULL)
		std::cout << "fist";
	else
		std::cout << WeaponB->getType();
	std::cout << std::endl;
}

HumanB::~HumanB()
{
	
}