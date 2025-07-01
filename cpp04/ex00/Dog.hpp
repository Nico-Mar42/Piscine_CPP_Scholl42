#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
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
};

#endif