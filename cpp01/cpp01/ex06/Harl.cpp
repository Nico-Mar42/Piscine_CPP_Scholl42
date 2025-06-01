#include "Harl.hpp"

Harl::Harl()
{

}

void Harl::debug()
{
	std::cout << "[DEBUG]Let me double-check the rulebook... again." << std::endl; 
}

void Harl::info()
{
	std::cout << "[INFO]Just so you know, my character can see in the dark. It’s on my sheet." << std::endl; 
}

void Harl::warning()
{
	std::cout << "[WARNING]If the DM pulls one more trap without a perception roll, I swear..." << std::endl; 
}

void Harl::error()
{
	std::cout << "[ERROR]WHAT DO YOU MEAN I DIED FROM FALLING DOWN THE STAIRS?!" << std::endl; 
}

void Harl::complain(std::string level)
{
	int i = 0;
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	while (i < 4 && level != levels[i])
        i++;

	switch (i)
	{
		case 0 :
			Harl::debug();
		case 1 :
			Harl::info();
		case 2 :
			Harl::warning();
		case 3 :
			Harl::error();
			break;
		default:
			std::cout << "Probably nothing" << std::endl;
	}

}

Harl::~Harl()
{

}
