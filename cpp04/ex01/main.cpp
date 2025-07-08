#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"



int main()
{
	std::cout << "\033[32m--- Animal Array Test ---\033[0m" << std::endl;

	const int arraySize = 4;
	Animal* animals[arraySize];

	// Create Dog and Cat objects
	for (int i = 0; i < arraySize; ++i) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n\033[32m--- Types and Sounds ---\033[0m" << std::endl;
	for (int i = 0; i < arraySize; ++i) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << "\n\033[32m--- Brain Functionality ---\033[0m" << std::endl;
	Cat cat;
	cat.setidea("I want to sleep");
	std::cout << "Cat's idea: " << cat.getfirstidea() << std::endl;

	Dog dog;
	dog.setidea("I want to play fetch");
	std::cout << "Dog's idea: " << dog.getfirstidea() << std::endl;

	std::cout << "\n\033[32m--- Deep Copy Test ---\033[0m" << std::endl;
	Cat copyCat(cat);
	std::cout << "CopyCat's idea: " << copyCat.getfirstidea() << std::endl;
	cat.setidea("I want to eat");
	std::cout << "Cat's new idea: " << cat.getfirstidea() << std::endl;
	std::cout << "CopyCat's idea after Cat changed: " << copyCat.getfirstidea() << std::endl;

	// Clean up
	for (int i = 0; i < arraySize; ++i)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "\033[32mAll animals deleted.\033[0m" << std::endl;
}