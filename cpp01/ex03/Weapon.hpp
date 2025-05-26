#ifndef WEAPON_HPP
	#define WEAPON_HPP

# include <iostream>
# include <string>
# include <cstdlib>


class Weapon
{
	//public:
	//protected:
	//private:

	public:
		Weapon();
		Weapon(std::string type);
		const std::string& getType();
		void setType(std::string type);
		~Weapon();

	private:
	std::string type;
};

#endif