#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource default constructor called" << std::endl;
	InitMemory();
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	//std::cout << "MateriaSource copy constructor called" << std::endl;
	if (this != &other) 
	{
		for (int i = 0;i < 4; i++)
		{
			if (this->_Memory[i] != NULL)
				delete(this->_Memory[i]);
			if (other._Memory[i] == NULL)
				this->_Memory[i] = NULL;
			else
				this->_Memory[i] = other._Memory[i]->clone();
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) 
{
	//std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other) 
	{
		for (int i = 0;i < 4; i++)
		{
			if (this->_Memory[i] != NULL)
				delete(this->_Memory[i]);
			if (other._Memory[i] == NULL)
				this->_Memory[i] = NULL;
			else
				this->_Memory[i] = other._Memory[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_Memory[i] != NULL)
			delete(this->_Memory[i]);
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_Memory[i] == NULL)
		{	
			std::cout << "\'* " << m->getType() << " Materia learned in slot " << i << " *\'" << std::endl;
			this->_Memory[i] = m;
			return;
		}
	}
	std::cout << "\'* Memory is full, cannot learn " << m->getType() << " Materia *\'" << std::endl;
	return;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
	{
		if (type == this->_Memory[i]->getType())
		{	
			std::cout << "\'* " << type << " Materia created from slot " << i << " *\'" << std::endl;
			return(_Memory[i]->clone());
		}
	}
	std::cout << "\'* " << type << " Materia not found in memory *\'" << std::endl;
	return(NULL);
}

void MateriaSource::InitMemory()
{
	for(int i = 0; i < 4; i++)
	{
		this->_Memory[i] = NULL;
	}
}