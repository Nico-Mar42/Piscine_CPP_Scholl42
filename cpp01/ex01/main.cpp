#include "Zombie.hpp"

int main()
{
	std::string name = "Jeannette";
	int N = 12;

	Zombie* horde = zombieHorde(N, name);

	for (int i = 0; i < N; ++i)
		horde[i].announce();
	
	delete[] horde;

	return (0);
}