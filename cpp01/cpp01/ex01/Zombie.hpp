#ifndef ZOMBIE_HPP
	#define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie
{
	//public:
	//protected:
	//private:

	public:
		Zombie();
		void setname(std::string name);
		void announce(void);
		~Zombie();

	private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);


#endif