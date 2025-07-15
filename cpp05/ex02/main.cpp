#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "\033[33m--- ShrubberyCreationForm Test ---\033[0m" << std::endl << std::endl;

	try
	{
		Bureaucrat Bobby("Bobby McDouglas", 150);
		ShrubberyCreationForm Forester("Forest");
		Bobby.signForm(Forester);
		Bobby.executeForm(Forester);

		std::cout << std::endl;

		for(int i = 0; i < 20; i++)
		{
			Bobby.incrementGrade();
		}
		std::cout << "\033[32m" << Bobby << "\033[0m" << std::endl;
		Bobby.signForm(Forester);
		std::cout << "\033[32m" << Forester << "\033[0m" << std::endl;
		Bobby.executeForm(Forester);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "\033[33m--- RobotomyRequestForm Test ---\033[0m" << std::endl << std::endl;

	try
	{
		Bureaucrat Dwaine("Dwaine Dickinson", 75);
		RobotomyRequestForm Technomedic("Josh Davis");
		Dwaine.signForm(Technomedic);
		Dwaine.executeForm(Technomedic);

		std::cout << std::endl;

		for(int i = 0; i < 30; i++)
		{
			Dwaine.incrementGrade();
		}

		std::cout << "\033[32m" << Dwaine << "\033[0m" << std::endl;
		Dwaine.signForm(Technomedic);
		std::cout << "\033[32m" << Technomedic << "\033[0m" << std::endl;
		Dwaine.executeForm(Technomedic);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "\033[33m--- PresidentialPardonForm Test ---\033[0m" << std::endl << std::endl;

	try
	{
		Bureaucrat Todd("Dwaine Dickinson", 30);
		PresidentialPardonForm Mercy("George Tucker");
		Todd.signForm(Mercy);
		Todd.executeForm(Mercy);

		std::cout << std::endl;

		for(int i = 0; i < 25; i++)
		{
			Todd.incrementGrade();
		}

		std::cout << "\033[32m" << Todd << "\033[0m" << std::endl;
		Todd.signForm(Mercy);
		std::cout << "\033[32m" << Mercy << "\033[0m" << std::endl;
		Todd.executeForm(Mercy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}