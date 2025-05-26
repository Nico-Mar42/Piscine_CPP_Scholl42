#include "Zombie.hpp"

void newZombie( std::string name )
{
	Zombie* b = new Zombie(name);
	b->announce();
	delete b;
}