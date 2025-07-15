#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
		std::string getTarget();
 
	private:
		std::string target;
};