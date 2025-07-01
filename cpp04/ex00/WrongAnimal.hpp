#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include <memory>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal operator=(const WrongAnimal &other);
		virtual ~WrongAnimal();

		std::string getType() const;
		void setType(const std::string &type);
		void makeSound() const;

	protected:
		std::string type;

};




#endif