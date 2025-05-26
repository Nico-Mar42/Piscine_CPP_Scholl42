#include "Phonebook.hpp"

int test_index(std::string str);

Phonebook::Phonebook()
{
	this->index = 0;
	this->total_contacts = 0;
}
Phonebook::~Phonebook()
{
	std::cout << "\033[1;31mPhonebook Destroyed\033[0m" << std::endl;
}

void Phonebook::add_contact(Contact &cont)
{
	if (this->index < 8)
	{
		this->contacts[this->index] = cont;
		this->index++;
		if (this->total_contacts < 8)
			this->total_contacts++;
	}
	else
	{
		this->index = 0;
		this->contacts[this->index] = cont;
		this->index++;
		std::cout << "\033[1;33mPhonebook is full, overwriting the oldest contact.\033[0m" << std::endl;
	}
}

void Phonebook::search_contact(void)
{
	if(this->total_contacts == 0)
	{
		std::cout << "\033[1;31mNo contacts to display.\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[1;34m---------------------------------------------\033[0m" << std::endl;
	std::cout << "\033[1;34m-  index   |first name|last name | nickname -\033[0m" << std::endl;
	std::cout << "\033[1;34m---------------------------------------------\033[0m" << std::endl;
	for (int i = 0; i < this->total_contacts; i++)
	{
		std::cout << "\033[1;34m-         " << i;
		std::cout << "|" << this->contacts[i].get_param(0);
		std::cout << "|" << this->contacts[i].get_param(1);
		std::cout << "|" << this->contacts[i].get_param(2) << "-\033[0m" << std::endl;
	}
	std::cout << "\033[1;34m---------------------------------------------\033[0m" << std::endl;

	while(1)
	{
		std::cout << "\033[1;32mEnter the index of the contact you want to see: \033[0m" << std::endl;
		std::string str_index;
		int index;
		std::cout << "\033[0m";
		std::getline(std::cin, str_index);
		std::cout << "\033[0m";

		if(std::cin.eof())
			exit(0);
		if (test_index(str_index) == -1)
			index = 10;
		else	
			index = std::atoi(str_index.c_str());
		if (index >= 0 && index < this->index)
		{
			this->contacts[index].print_contact();
			break;
		}
		else
		{
			std::cout << "\033[1;31mPlease enter a valid index.\033[0m" << std::endl;
			std::cout << "\033[1;32mPlease enter a valid index.\033[0m" << std::endl;
		}
	}
	return ;
}

int test_index(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return -1;
	}
	return 0;
}
