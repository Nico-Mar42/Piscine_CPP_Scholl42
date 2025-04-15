#ifndef CONTACT_CLASS_HPP
	#define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class Contact
{
	//public:
	//protected:
	//private:

	public:
		Contact();
		void set_contact(void);
		void print_contact(void);
		std::string get_param(int i);
		//~contact();

	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif