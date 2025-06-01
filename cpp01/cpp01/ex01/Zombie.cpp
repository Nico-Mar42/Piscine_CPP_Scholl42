#include "Zombie.hpp"

Zombie::Zombie()
{
	
}

void Zombie::setname(std::string name) 
{
    this->name = name;
}
void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	
}