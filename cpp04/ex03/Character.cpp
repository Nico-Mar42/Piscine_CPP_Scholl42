#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

Character::Character()
{
	//std::cout << "Character default constructor called" << std::endl;
	initInventory();
}

Character::Character(std::string name)
{
	//std::cout << "Character name constructor called" << std::endl;
	this->_name = name;
	initInventory();
}

Character::Character(const Character &other)
{
	//std::cout << "Character copy constructor called" << std::endl;
	if (this != &other) 
	{
		this->_name = other._name;

		for (int i = 0;i < 4; i++)
		{
			if (this->_Inventory[i] != NULL)
				delete(this->_Inventory[i]);
			if (other._Inventory[i] == NULL)
				this->_Inventory[i] = NULL;
			else
				this->_Inventory[i] = other._Inventory[i]->clone();
		}
	}
}

Character &Character::operator=(const Character &other) 
{
	//std::cout << "Character assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->_name = other._name;

		for (int i = 0;i < 4; i++)
		{
			if (this->_Inventory[i] != NULL)
				delete(this->_Inventory[i]);
			if (other._Inventory[i] == NULL)
				this->_Inventory[i] = NULL;
			else
				this->_Inventory[i] = other._Inventory[i]->clone();
		}
	}
	return *this;
}

void Character::equip(AMateria* m)
{
	int i;

	for(i = 0; i < 4; i++)
	{
		if (this->_Inventory[i] == NULL)
		{	
			this->_Inventory[i] = m;
			std::cout << "\'* Materia equipped in slot " << i << " *\'" << std::endl;
			return;
		}
	}
	std::cout << "\'* Inventory is full, cannot equip materia *\'" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx > 3)
	{
		std::cout << "\'* Slot "<< idx << " is out of range. Choose between 0 and 3 *\'" << std::endl;
		return;
	}
	if (this->_Inventory[idx] == NULL) 
		std::cout << "\'* This slot is already empty *\'" << std::endl;
	else
	{
		this->_Inventory[idx] = NULL;
		std::cout << "\'* This slot is empty now*\'" << std::endl;
	}
	return;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3)
	{
		std::cout << "\'* Slot "<< idx << " is out of range. Choose between 0 and 3 *\'" << std::endl;
		return;
	}
	if (this->_Inventory[idx] == NULL) 
		std::cout << "\'* This slot is already empty *\'" << std::endl;
	else
	{
		std::cout << "\'* " << this->_name << " use materia *\'";
		 _Inventory[idx]->use(target);
	}
	return;
}

void Character::initInventory()
{
	int i;

	for (i = 0; i < 4; i++)
	{
		this->_Inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_Inventory[i] != NULL)
		{
			delete(this->_Inventory[i]);
		}
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::setName(std::string name)
{
	this->_name = name;
}
