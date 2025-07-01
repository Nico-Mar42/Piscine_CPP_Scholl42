#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
#include <memory>

class WrongCat : virtual public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat operator=(const WrongCat &other);
		void makeSound() const;
		virtual ~WrongCat();

};

#endif