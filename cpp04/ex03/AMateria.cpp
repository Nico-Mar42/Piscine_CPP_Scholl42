#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	this->type = "default";
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

AMateria::~AMateria()
{
	
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Using " << this->type << " on " << target.getName() << std::endl;
}