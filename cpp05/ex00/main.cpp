#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\033[32mTest with right grade\033[0m" << std::endl << std::endl;

	try
	{
		Bureaucrat henry("Henry Mcgalaghan", 1);
		std::cout << henry.getName() << std::endl;
		std::cout << henry.getGrade() << std::endl;
		std::cout << henry << std::endl; 
	}
	catch (std::exception & e)
	{
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	


	std::cout << std::endl << "\033[32mTest with too high grade\033[0m" << std::endl << std::endl;

	try
	{
		Bureaucrat Sophie("Sophie Durand", 200);
	}
	catch (std::exception & e)
	{
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[32mTest with too low grade\033[0m" << std::endl << std::endl;

	try
	{
		Bureaucrat Duke("Duke Johnson", 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Erreur : " << e.what() << std::endl;
	}

}