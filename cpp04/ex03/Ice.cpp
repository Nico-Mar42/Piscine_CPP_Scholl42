#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	//std::cout << "Ice default constructor called" << std::endl;
	this->type = "ice";	
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	//std::cout << "Ice copy constructor called" << std::endl;
	this->type = other.type;
}

Ice &Ice::operator=(const Ice &other)
{
	//std::cout << "Ice assignement operator called" << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
		this->type = other.type;
	}
	return *this;
}

Ice::~Ice()
{
	//std::cout << "Ice destcutor called" << std::endl;
}

Ice *Ice::clone() const
{
	std::cout << "\'* Ice clone called *\'" << std::endl;
	return new Ice (*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "\'* shoots an ice bolt at " << target.getName() << " *\'" << std::endl;
}