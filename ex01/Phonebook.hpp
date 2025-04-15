#ifndef PHONEBOOK_HPP
	#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.class.hpp"
# include <cstdlib>
# include <limits>


class Phonebook
{
	public:
		Phonebook();
		void add_contact(Contact &cont);
		void search_contact(void);
		~Phonebook();
	
	private:
	Contact contacts[8];
	int index;
	int total_contacts;
};

#endif