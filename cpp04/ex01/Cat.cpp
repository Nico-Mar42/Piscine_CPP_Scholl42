#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() 
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) 
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	brain = new Brain(*other.brain);
	if (!brain) {
		std::cerr << "Failed to allocate memory for brain in Cat copy constructor" << std::endl;
	}
}

Cat Cat::operator=(const Cat &other) 
{
	std::cout << "Cat assignment operator called" << std::endl;
if (this != &other) {
		Animal::operator=(other);
		this->type = other.type;
		if (brain) {
			delete brain;
		}
		brain = new Brain(*other.brain);
		if (!brain) {
			std::cerr << "Failed to allocate memory for brain in Cat assignment operator" << std::endl;
		}
	}
	return *this;
}

Cat::~Cat() 
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const 
{
	std::cout << "Meow!" << std::endl;
}

std::string Cat::getidea()
{
	return (this->brain->getidea());
}
