#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",72, 45)
{
	this->target = "default target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm",72, 45)
{
	this->target = other.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::string sign = this->getSign();
	if(sign.compare("false") == 0)
	{
		std::cerr << "\033[31m" << executor.getName() << " , cannot sign " << this->getName() << ".\033[0m" << std::endl;
	}
	if(executor.getGrade() > this->getGradetoexec())
	{
		throw RobotomyRequestForm::GradeTooLowException();
	}
	else 
	{
		std::cout << "\033[32mvrriiii, vrriiii, vrriiiiiiiiiiii \" Bruit de perceuse \"\033[0m" << std::endl;
		srand(time(NULL));
		if (rand() % 2 == 0)
		{
			std::cout << "\033[34m" << this->target << " has been robotomized successfully.\033[0m" << std::endl;
		}
		else
		{
			std::cerr << "\033[31mThe robotomy of " << this->target << " was unsuccessful.\033[0m" << std::endl;
		}
	}
	return ;
}

std::string RobotomyRequestForm::getTarget()
{
	return(this->target);
}