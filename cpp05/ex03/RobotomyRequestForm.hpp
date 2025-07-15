#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;
		std::string getTarget();
 
	private:
		std::string target;
};