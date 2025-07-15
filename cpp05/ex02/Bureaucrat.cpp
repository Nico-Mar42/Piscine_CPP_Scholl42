#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("John Smith")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	this->_grade = grade;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	this->_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// _name is const and cannot be assigned
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

void Bureaucrat::incrementGrade()
{
	this->_grade -= 1;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade()
{
	this->_grade += 1;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat&  bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(AForm &Aform)
{
	try
	{
		Aform.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << this->_name << " couldn\'t sign " << Aform.getName() << " because his " << e.what() << std::endl <<"\033[0m";
		return;
	}
	std::cout << this->_name << " signed " << Aform.getName() << std::endl; 
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
	}
}