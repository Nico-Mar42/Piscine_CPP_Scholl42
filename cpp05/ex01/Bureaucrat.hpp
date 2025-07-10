#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include "Form.hpp"

class Form;

class Bureaucrat 
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		void incrementGrade();
		void decrementGrade();
		std::string const getName() const; 
		int getGrade() const;
		void signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw()
			{
				return "Grade is too high!";
			}
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw()
			{
				return "Grade is too low!";
			}
		};
	
	private:
		const std::string  _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);