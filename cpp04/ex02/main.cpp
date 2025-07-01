#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
	Dog* Doug = new Dog();
	Cat* Kitty = new Cat();
	Dog* Doug2 = new Dog(*Doug);
	Cat* Kitty2 = new Cat(*Kitty);

	Doug->makeSound();
	Kitty->makeSound();
	Doug2->makeSound();
	Kitty2->makeSound();
	delete Doug;
	delete Kitty;
	delete Doug2;
	delete Kitty2;
	std::cout << "All animals deleted." << std::endl;
	return 0;
}