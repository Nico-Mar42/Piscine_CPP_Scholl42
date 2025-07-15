#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145, 137)
{
	this->target = "default target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm",145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm",145, 137)
{
	this->target = other.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string sign = this->getSign();
	std::string out_file = this->target + std::string("_shrubbery");
	std::string content;
	content = "   ccee88oo\n C8O8O8Q8PoOb o8oo\ndOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\//  /douUP\n        \\\\////\n         |||/\\\n         |||\\/\n         |||||\n   .....//||||\\....\n";
	if(sign.compare("false") == 0)
	{
		std::cerr << "\033[31m" << executor.getName() << " , cannot sign " << this->getName() << "." << "\033[0m" << std::endl;
	}
	if(executor.getGrade() > this->getGradetoexec())
	{
		throw ShrubberyCreationForm::GradeTooLowException();
	}
	else 
	{
		std::ofstream file(out_file.c_str());
		if (!file.is_open()) {
			std::cerr << "Error opening file for writing: " << out_file << std::endl;
			return ; 
		}
		file << content;
		if (!file) {
			std::cerr << "Error writing to file: " << out_file << std::endl;
			return ;
		}
		file.close();
	}
	return ;
}

std::string ShrubberyCreationForm::getTarget()
{
	return(this->target);
}