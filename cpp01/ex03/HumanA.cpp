#include "HumanA.hpp"

HumanA::HumanA(std::string name1, Weapon& W_type) : name(name1), weaponA(W_type)
{

}

void HumanA::attack()
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << weaponA.getType();
	std::cout << std::endl;
}

HumanA::~HumanA()
{
	
}