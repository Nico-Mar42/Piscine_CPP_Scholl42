#ifndef HUMANA_HPP
	#define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	//public:
	//protected:
	//private:

	public:
		HumanA(std::string name1, Weapon& W_type);
		void attack();
		~HumanA();

	private:
	std::string name;
	Weapon& weaponA;
};

#endif