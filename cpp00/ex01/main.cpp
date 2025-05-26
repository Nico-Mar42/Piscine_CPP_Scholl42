#include "Phonebook.hpp"

int main()
{
	Phonebook p;
	std::string command;

	std::cout << "\033[1;32mWelcome to the Phonebook!\033[0m" << std::endl;
	while(1)
	{
		std::cout << "\033[1;32mYou can add or search contacts.\033[0m" << std::endl;
		std::cout << "\033[1;32mPlease enter a command: ADD, SEARCH, EXIT\033[0m" << std::endl;
		std::cout << "\033[1;33m";
		if(!std::getline(std::cin, command))
		{
			std::cout << "\033[1;31mExiting Phonebook...\033[0m" << std::endl;
			break;
		}
		std::cout << "\033[0m";
		if (command == "ADD" || command == "add")
		{
			Contact cont;
			cont.set_contact();
			p.add_contact(cont);
		}
		else if (command == "SEARCH" || command == "search")
			p.search_contact();
		else if (command == "EXIT" || command == "exit")
		{
			std::cout << "\033[1;31mExiting Phonebook...\033[0m" << std::endl;
			break;
		}
		else
			std::cout << "\033[1;31mInvalid command. Please try again.\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return 0;
}

