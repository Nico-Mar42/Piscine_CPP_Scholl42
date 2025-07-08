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

std::string Dog::getfirstidea()
{
	return (this->brain->getfirstidea());
}

void Dog::setidea(const std::string &idea)
{
	this->brain->setidea(idea);
}

void Dog::setIdeaAtIndex(int index, const std::string &idea)
{
	this->brain->setIdeaAtIndex(index, idea);
}

std::string Dog::getIdeaAtIndex(int index) const
{
	return this->brain->getIdeaAtIndex(index);
}

std::string* Dog::getAllIdeas()
{
	return this->brain->getAllIdeas();
}

void Dog::printIdeas() const
{
	this->brain->printIdeas();
}

void Dog::clearIdeas()
{
	this->brain->clearIdeas();
}

int Dog::getNumberOfIdeas() const
{
	return this->brain->getNumberOfIdeas();
}

bool Dog::ideaExistsAtIndex(int index) const
{
	return this->brain->ideaExistsAtIndex(index);
}

bool Dog::isEmpty() const
{
	return this->brain->isEmpty();
}

int Dog::getMaxIdeas() const
{
	return this->brain->getMaxIdeas();
}