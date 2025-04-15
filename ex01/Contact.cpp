#include "Phonebook.hpp"

std::string length_string(std::string str);


Contact::Contact()
{

}

std::string get_string(void)
{
	std::string str;
	while(1)
	{
		std::cout << "\033[1;33m";
		std::getline(std::cin, str);
		std::cout << "\033[0m";

		if(std::cin.eof())
			exit(0);
		if (str == "")
		{
			std::cout << "\033[1;31mPlease enter a valid string\033[0m" << std::endl;
			continue;
		}
		else 
			break;
	}
	return str;
}

std::string get_phone_number(void)
{
	std::string str;
	std::cout << "\033[1;33m";
	std::getline(std::cin, str);
	std::cout << "\033[0m";

	if(std::cin.eof())
			exit(0);
	if (str == "")
	{
		std::cout << "\033[1;31mPlease enter a valid phone number\033[0m" << std::endl;
		return get_phone_number();
	}
	if(str[0] != '+')
	{
		if(!isdigit(str[0]))
		{
			std::cout << "\033[1;31mPlease enter a valid phone number\033[0m" << std::endl;
			return get_phone_number();
		}	
	}
	else 
	{
		if(str[1] == '\0')
		{
			std::cout << "\033[1;31mPlease enter a valid phone number\033[0m" << std::endl;
			return get_phone_number();
		}
	}
	for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			std::cout << "\033[1;31mPlease enter a valid phone number\033[0m" << std::endl;
			return get_phone_number();
		}
	}
	return str;
}

void Contact::set_contact(void)
{
	std::cout << "\033[1;32mEnter First Name: \033[0m";
	this->first_name = get_string();
	std::cout << "\033[1;32mEnter Last Name: \033[0m";
	this->last_name = get_string();
	std::cout << "\033[1;32mEnter Nickname: \033[0m";
	this->nickname = get_string();
	std::cout << "\033[1;32mEnter Phone Number: \033[0m";
	this->phone_number = get_phone_number();
	std::cout << "\033[1;32mEnter Darkest Secret: \033[0m";
	this->darkest_secret = get_string();
	std::cout << "\033[1;34mContact Added\033[0m" << std::endl;
	
}

void Contact::print_contact(void)
{
	std::cout << "\033[1;34mFirst Name: " << this->first_name << std::endl;
	std::cout << "Last Name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << "\033[0m" << std::endl;	
}

std::string Contact::get_param(int i)
{
	switch (i)
	{
		case 0:
			return length_string(this->first_name);
		case 1:
			return length_string(this->last_name);
		case 2:
			return length_string(this->nickname);
		case 3:
			return length_string(this->phone_number);
		case 4:
			return length_string(this->darkest_secret);
		default:
			return "\033[1;31mInvalid Index\033[0m";
	}
}

std::string length_string(std::string str)
{
	int str_len = str.length();

	if (str_len > 10)
	{
		str = str.substr(0, 9) + ".";
	}
	else if (str_len < 10)
	{
		str = std::string(10 - str_len, ' ') + str;
	}
	return str;
}

