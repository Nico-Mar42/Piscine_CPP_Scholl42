#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\033[32mCreating Animal, Dog, Cat, WrongAnimal, and WrongCat objects...\033[0m" << std::endl;
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongAnimal();
	const WrongCat* c = new WrongCat();
	
	std::cout << std::endl;
	std::cout << "\033[32mTypes of the created objects:\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << "\033[32mMaking sounds...\033[0m" << std::endl;	
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	c->makeSound();
	k->makeSound();

	std::cout << std::endl;
	std::cout << "\033[32mDeleting objects...\033[0m" << std::endl;
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete k;
	delete c;

	return 0;
}