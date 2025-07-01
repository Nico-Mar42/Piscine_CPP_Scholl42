#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		std::string const &getName() const;
		void setName(std::string name);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void initInventory();

	private:
		std::string _name;
		AMateria* _Inventory[4];
};

#endif