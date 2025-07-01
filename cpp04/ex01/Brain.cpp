#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain() 
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "Default idea ";
	}
}

Brain::Brain(const Brain &other) 
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain &other) 
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() 
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getidea()
{
	return this->ideas[1];
}