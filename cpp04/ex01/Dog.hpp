#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
#include <memory>

class Dog : virtual public Animal {
	public:
		Dog();
		Dog(const Dog &other);
		Dog operator=(const Dog &other);
		void makeSound() const;
		virtual ~Dog();
		
		std::string getfirstidea();
		void setidea(const std::string &idea);
		void setIdeaAtIndex(int index, const std::string &idea);
		std::string getIdeaAtIndex(int index) const;
		std::string* getAllIdeas();
		void printIdeas() const;
		void clearIdeas();
		int getNumberOfIdeas() const;
		bool ideaExistsAtIndex(int index) const;
		bool isEmpty() const;
		int getMaxIdeas() const;

	private:
	Brain* brain;
};

#endif