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
			this->_Memory[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
	{
		if (type == this->_Memory[i]->getType())
		{	
			return(_Memory[i]->clone());
		}
	}
	return(NULL);
}

void MateriaSource::InitMemory()
{
	for(int i = 0; i < 4; i++)
	{
		this->_Memory[i] = NULL;
	}
}