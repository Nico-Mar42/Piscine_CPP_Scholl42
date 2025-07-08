#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
#include <memory>

class Cat : virtual public Animal {
	public:
		Cat();
		Cat(const Cat &other);
		Cat operator=(const Cat &other);
		void makeSound() const;
		virtual ~Cat();

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