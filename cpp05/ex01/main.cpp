#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\033[32mTest form with right grade\033[0m" << std::endl << std::endl;

	try
	{
		Bureaucrat Henry("Henry McGalaghan", 80);
		Form Bullshit("Hapiness Manager", 80, 80);

		std::cout << Henry << std::endl;
		std::cout << Bullshit << std::endl;	
		Henry.signForm(Bullshit);
		std::cout << Bullshit << std::endl;	
		Henry.decrementGrade();
		Henry.signForm(Bullshit);
	}
	catch (std::exception & e)
	{
		std::cout << "Erreur : " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[32mTest form with Wrong grade\033[0m" << std::endl << std::endl;

	try
	{
		Form Master("Master of the Universe", 0, 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Erreur : " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[32mTest form with right grade but Bureaucrat has grade to low\033[0m" << std::endl << std::endl;

	Bureaucrat Sophie("Sophie Durand", 22);
	Form Head ("Head Leader", 1, 1);

	std::cout << Sophie << std::endl;
	std::cout << Head << std::endl;

	Sophie.signForm(Head);

}