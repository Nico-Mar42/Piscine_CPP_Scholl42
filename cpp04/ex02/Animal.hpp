#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <memory>

class Animal {
	public:
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		virtual ~Animal();

		std::string getType() const;
		void setType(const std::string &type);
		virtual void makeSound() const = 0;

	protected:
		std::string type;

};




#endif