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
	typedef void (Harl::*Harlfunc)();
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	Harlfunc function[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; ++i)
	{
		if (!level.compare(levels[i]))
			(this->*function[i])();
	}
}

Harl::~Harl()
{

}
