#pragma once

#include <string>
#include <exception>



class Bureaucrat 
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int rank);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		void incrementGrade();
		void decrementGrade();
		std::string getname();
		int getgrade();

		class GradeTooHighException
		{
			const char* what() const throw()
			{
				return "Grade is too high!";
			}
		};
		class GradeTooLowException
		{
			const char* what() const throw()
			{
				return "Grade is too low!";
			}
		};
	
	private:
		const std::string  _name;
		int rank;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);