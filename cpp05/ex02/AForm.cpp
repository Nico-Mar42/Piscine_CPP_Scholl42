#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _grade_to_sign(150), _grade_to_exec(150)
{
	_sign = false;
}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_exec) 
	: _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (_grade_to_exec < 1 || _grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	if (_grade_to_exec > 150 || _grade_to_sign > 150)
		throw AForm::GradeTooLowException();

	_sign = false;
}

AForm::AForm(const AForm &other) : _name(other._name),
	_grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec)
{
	this->_sign = other._sign;
}

AForm &AForm::operator=(const AForm &other)
{
	if(this != &other)
	{
		this->_sign = other._sign;
		// Only _sign is assigned; other members are const and cannot be assigned.
	}
	return (*this);
}

AForm::~AForm(){};

const std::string AForm::getName() const
{
	return(this->_name);
}

std::string AForm::getSign() const
{
	if (this->_sign == true) 
		return("true");
	else
		return ("false");
}

int AForm::getGradetosign() const
{
	return this->_grade_to_sign;
}

int AForm::getGradetoexec() const
{
	return this->_grade_to_exec;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >  this->_grade_to_sign)
	{
		throw AForm::GradeTooLowException();
		return;
	}
	else
		this->_sign = true;
	return;
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << Aform.getName() << ", Aform sign grade " << Aform.getGradetosign() << ", execute grade " << Aform.getGradetoexec() << ",signed : " << Aform.getSign();
    return os;
}