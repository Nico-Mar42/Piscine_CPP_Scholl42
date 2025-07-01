#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() 
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) 
{
	this->type = other.type;
	brain = new Brain(*other.brain);
	if (!brain) {
		std::cerr << "Failed to allocate memory for brain in Dog copy constructor" << std::endl;
	}
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog Dog::operator=(const Dog &other) 
{
	if (this != &other) {
		Animal::operator=(other);
		this->type = other.type;
		if (brain) {
			delete brain;
		}
		brain = new Brain(*other.brain);
		if (!brain) {
			std::cerr << "Failed to allocate memory for brain in Dog assignment operator" << std::endl;
		}
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog() 
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const 
{
	std::cout << "Woof!" << std::endl;
}