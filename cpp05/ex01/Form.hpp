#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int grade_to_sign, const int grade_to_exec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string getName() const;
		std::string getSign() const; 
		int getGradetosign() const;
		int getGradetoexec() const;
		void beSigned(Bureaucrat &bureaucrat);

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
		const std::string _name;
		bool _sign;
		const int _grade_to_sign;
		const int _grade_to_exec;
};

std::ostream& operator<<(std::ostream& os, const Form& form);
