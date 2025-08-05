#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
    std::cout << YELLOW << "          Global Test for Array class" << RESET << std::endl;
    std::cout << YELLOW << "          ---------------------------" << RESET << std::endl << std::endl;

	std::cout << MAGENTA << "          Test with the default constructor" << RESET << std::endl << std::endl;
	try
	{
		Array<int> defaults;
		std::cout << GREEN << "          the contents of the first index : " << BLUE << defaults[0] << RESET << std::endl;
		std::cout << GREEN << "          the size of the table is : " << BLUE << defaults.size() << RESET << std::endl ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << MAGENTA << "          test with the constructor that takes an unsigned int" << RESET << std::endl << std::endl;
	std::cout << CYAN << "          With int array" << RESET << std::endl << std::endl;

	try
	{
		Array<int> Numbers(42);

		std::cout << GREEN << "          the size of the table is " << BLUE << Numbers.size() << RESET << std::endl << std::endl;
		std::cout << GREEN << "          the contents of the first index : " << BLUE << Numbers[0] << RESET << std::endl;
		std::cout << GREEN << "          the contents of the last index : " << BLUE << Numbers[41] << RESET << std::endl;

		Numbers[0] = 4;
		Numbers[41] = 42;

		std::cout << GREEN << "          the contents of the first index after modification : " << BLUE << Numbers[0] << RESET << std::endl;
		std::cout << GREEN << "          the contents of the last index : " << BLUE << Numbers[41] << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << CYAN << "\n          With int Char" << RESET << std::endl << std::endl;

	try
	{
		Array<char> alpha(42);

		std::cout << GREEN << "          the size of the table is " << BLUE << alpha.size() << RESET << std::endl << std::endl;
		std::cout << GREEN << "          the contents of the first index : " << BLUE << alpha[0] << RESET << std::endl;
		std::cout << GREEN << "          the contents of the last index : " << BLUE << alpha[41] << RESET << std::endl;

		alpha[0] = 'b';
		alpha[41] = 'k';

		std::cout << GREEN << "          the contents of the first index after modification : " << BLUE << alpha[0] << RESET << std::endl;
		std::cout << GREEN << "          the contents of the last index : " << BLUE << alpha[41] << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << CYAN << "\n          With int string" << RESET << std::endl << std::endl;

	try
	{
		Array<std::string> string(42);

		std::cout << GREEN << "          the size of the table is " << BLUE << string.size() << RESET << std::endl << std::endl;
		std::cout << GREEN << "          the contents of the first index : " << BLUE << string[0] << RESET << std::endl;
		std::cout << GREEN << "          the contents of the last index : " << BLUE << string[41] << RESET << std::endl;

		string[0] = "test1";
		string[41] = "test42";

		std::cout << GREEN << "          the contents of the first index after modification : " << BLUE << string[0] << RESET << std::endl;
		std::cout << GREEN << "          the contents of the last index : " << BLUE << string[41] << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << CYAN << "\n          With int const int" << RESET << std::endl << std::endl;

	try
	{
		Array<const int> alpha(42);

		std::cout << GREEN << "          the size of the table is " << BLUE << alpha.size() << RESET << std::endl << std::endl;
		std::cout << GREEN << "          the contents of the first index : " << BLUE << alpha[0] << RESET << std::endl;
		std::cout << GREEN << "          the contents of the last index : " << BLUE << alpha[41] << RESET << std::endl;

		//alpha[0] = 'b'; //uncommenting these 2 lines prevents compilation
		//alpha[41] = 'k';

		std::cout << GREEN << "          the contents of the first index after modification : " << BLUE << alpha[0] << RESET << std::endl;
		std::cout << GREEN << "          the contents of the last index : " << BLUE << alpha[41] << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}