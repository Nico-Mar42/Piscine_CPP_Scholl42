#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
	std::cout << "\033[32m--- Abstract Class Test ---\033[0m" << std::endl << std::endl;
	// Uncommenting the following line will cause a compilation error
	// because Animal is an abstract class and cannot be instantiated.

	//Animal* chat = new Cat(); // This line will cause a compilation error]"
	Cat* cat = new Cat();
	cat->makeSound();
	
}