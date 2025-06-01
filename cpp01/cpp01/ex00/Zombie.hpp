#ifndef ZOMBIE_HPP
	#define ZOMBIE_HPP

# include <iostream>
# include <string>

void newZombie( std::string name );
void randomChump( std::string name );



class Zombie
{
	//public:
	//protected:
	//private:

	public:
		Zombie(std::string name);
		void announce(void);
		~Zombie();

	private:
	std::string name;
};

#endif