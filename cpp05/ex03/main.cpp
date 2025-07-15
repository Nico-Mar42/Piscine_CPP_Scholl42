#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	std::cout << "\033[33m--- Intern Test ---\033[0m" << std::endl << std::endl;

	try
	{
		Intern Timeo;
		AForm* Mercy;
		Mercy = Timeo.makeForm("PresidentialPardonForm", "Jason Douglas");
		std::cout << *Mercy << std::endl;
		delete (Mercy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		Intern Lilou;
		AForm * Robotizing;
		Robotizing = Lilou.makeForm("RobotomyRequestForm", "Mark Welberg");
		std::cout << *Robotizing << std::endl;
		delete (Robotizing);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		Intern Liam;
		AForm * Forestry;
		Forestry = Liam.makeForm("ShrubberyCreationForm", "Jenna Jones");
		std::cout << *Forestry << std::endl;
		delete (Forestry);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		Intern Liam;
		AForm * Random;
		Random = Liam.makeForm("RandomForm", "Steven Moffat");
		std::cout << Random << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (1) ;
}