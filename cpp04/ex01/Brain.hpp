#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain {
	public:
		Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain &other);
		virtual ~Brain();
	
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
		
		protected:
		std::string ideas[100];
};

#endif