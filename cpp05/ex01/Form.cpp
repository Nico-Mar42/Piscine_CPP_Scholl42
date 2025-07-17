#include "Form.hpp"

Form::Form() : _name("Default Form"), _grade_to_sign(150), _grade_to_exec(150)
{
	_sign = false;
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_exec) 
	: _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (_grade_to_exec < 1 || _grade_to_sign < 1)
		throw Form::GradeTooHighException();
	if (_grade_to_exec > 150 || _grade_to_sign > 150)
		throw Form::GradeTooLowException();

	_sign = false;
}

Form::Form(const Form &other) : _name(other._name),
	_grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec)
{
	this->_sign = other._sign;
}

Form &Form::operator=(const Form &other)
{
	if(this != &other)
	{
		this->_sign = other._sign;
		// Only _sign is assigned; other members are const and cannot be assigned.
	}
	return (*this);
}

Form::~Form(){};

const std::string Form::getName() const
{
	return(this->_name);
}

std::string Form::getSign() const
{
	if (this->_sign == true) 
		return("true");
	else
		return ("false");
}

int Form::getGradetosign() const
{
	return this->_grade_to_sign;
}

int Form::getGradetoexec() const
{
	return this->_grade_to_exec;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >  this->_grade_to_sign)
	{
		throw Form::GradeTooLowException();
		return;
	}
	else
		this->_sign = true;
	return;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", form sign grade " << form.getGradetosign() << ", execute grade " << form.getGradetoexec() << ",signed : " << form.getSign();
    return os;
}
