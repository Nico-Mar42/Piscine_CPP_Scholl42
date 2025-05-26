#ifndef HUMANB_HPP
	#define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	//public:
	//protected:
	//private:

	public:
		HumanB(std::string name);
		void set_weapon(Weapon& W_type);
		void attack();
		~HumanB();

	private:
	Weapon* WeaponB;
	std::string name;
};

#endif