#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"



int main()
{
	Cat cat;
	std::cout << cat.getidea() << std::endl;
	const int arraySize = 10;
	Animal* animals[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < arraySize; ++i) {
		std::cout << animals[i]->getType() << " ";
		animals[i]->makeSound();
	}
	
	for (int i = 0; i < arraySize; ++i) {
		delete animals[i];
	}
	std::cout << "All animals deleted." << std::endl;
}