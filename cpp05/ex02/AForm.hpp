#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string name, const int grade_to_sign, const int grade_to_exec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		const std::string getName() const;
		std::string getSign() const; 
		int getGradetosign() const;
		int getGradetoexec() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& Aform);
