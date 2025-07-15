#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(){}

AForm* Intern::makeForm(std::string Name, std::string Target)
{
	std::string formNames[3] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
	for (int i = 0; i < 3; ++i)
	{
		if (Name == formNames[i])
		{
			switch (i)
			{
			case 0:
				return new ShrubberyCreationForm(Target);
			case 1:
				return new RobotomyRequestForm(Target);
			case 2:
				return new PresidentialPardonForm(Target);
			default:
				break;
			}
		}
	}
	std::cout << "Intern: Unknown form name '" << Name << "'" << std::endl;
	return NULL;
}
