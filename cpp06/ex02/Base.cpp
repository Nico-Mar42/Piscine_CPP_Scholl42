#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}


Base* generate()
{
	srand(time(NULL));

	switch (rand() % 3)
	{
	case 1:
		 return new A;
		break;
	case 2:
		 return new B;
		break;
	default:
		 return new C;
		break;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "\033[34mIs A\033[0m" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "\033[31mis B\033[0m" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "\033[35mis C\033[0m" << std::endl;
	else if (p == NULL)
		std::cout << "Is NULL" << std::endl;
	else
		std::cout << "\033[33mis unknown\033[0m" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "\033[34mIs A\033[0m" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "\033[31mis B\033[0m" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "\033[35mis C\033[0m" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	std::cout << "\033[33mis unknown\033[0m" << std::endl;
}