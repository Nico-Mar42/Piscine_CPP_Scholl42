#include "RPN.hpp"

bool check_digit(std::string s);
bool check_digit(std::string s);

int main(int argc, char const *argv[])
{
	if (argc < 2){
		std::cerr << RED << "Not enough parameter" << RESET << std::endl;
		return 1;}
	else if(argc > 2){
		std::cerr << RED << "Too many parameter" << RESET << std::endl;
		return 1;}
	
	RPN e = RPN();
	e.calculate(argv[1]);

	return 0;
}
