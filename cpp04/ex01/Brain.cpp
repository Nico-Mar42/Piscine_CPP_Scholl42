#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain() 
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "Default idea";
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

std::string Brain::getfirstidea()
{
	return this->ideas[0];
}

void Brain::setidea(const std::string &idea)
{
	for (int i = 0; i < 100; ++i) {
		if (ideas[i] == "Default idea") {
			ideas[i] = idea;
			break;
		}
	}
}

void Brain::setIdeaAtIndex(int index, const std::string &idea)
{
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	}
}

std::string Brain::getIdeaAtIndex(int index) const
{
	if (index >= 0 && index < 100) {
		return ideas[index];
	}
	return "";
}

std::string* Brain::getAllIdeas()
{
	return ideas;
}

void Brain::printIdeas() const
{
	for (int i = 0; i < 100; ++i) {
		if (!ideas[i].empty()) {
			std::cout << "Idea " << i << ": " << ideas[i] << std::endl;
		}
	}
}

void Brain::clearIdeas()
{
	for (int i = 0; i < 100; ++i) {
		ideas[i].clear();
	}
}

int Brain::getNumberOfIdeas() const
{
	int count = 0;
	for (int i = 0; i < 100; ++i) {
		if (!ideas[i].empty()) {
			count++;
		}
	}
	return count;
}

bool Brain::ideaExistsAtIndex(int index) const
{
	if (index >= 0 && index < 100) {
		return !ideas[index].empty();
	}
	return false;
}

bool Brain::isEmpty() const
{
	for (int i = 0; i < 100; ++i) {
		if (!ideas[i].empty()) {
			return false;
		}
	}
	return true;
}

int Brain::getMaxIdeas() const
{
	return 100;
}

