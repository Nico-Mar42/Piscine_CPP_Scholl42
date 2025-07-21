#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25, 5)
{
	this->target = "default target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PresidentialPardonForm",25, 5)
{
	this->target = other.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::string sign = this->getSign();
	if(sign.compare("false") == 0)
	{
		std::cerr << "\033[31m" << executor.getName() << " , cannot sign " << this->getName() << ".\033[0m" << std::endl;
	}
	if(executor.getGrade() > this->getGradetoexec())
	{
		throw PresidentialPardonForm::GradeTooLowException();
	}
	else 
	{
		std::cout << "\033[34m" << this->target << " has been pardoned by Zaphod Beeblebrox\033[0m" << std::endl;
	}
	return ;
}

std::string PresidentialPardonForm::getTarget()
{
	return(this->target);
}