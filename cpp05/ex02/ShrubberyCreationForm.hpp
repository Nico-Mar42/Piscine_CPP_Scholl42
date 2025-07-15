#include "Bureaucrat.hpp"
#include "AForm.hpp"


class ShrubberyCreationForm : virtual public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
		std::string getTarget();
 
	private:
		std::string target;
};