#include "whatever.hpp"

int main()
{
	int a = 0;
	int b = 12;

	float c = 123;
	float d = 1;

	char e = 'a';
	char f = 'z';

	char* g = const_cast<char*>("test1");
	char* h = const_cast<char*>("test2");

	std::cout << YELLOW << "Swap Test\033[0m" << RESET << std::endl << std::endl;

	std::cout << GREEN << "with int" << RESET << std::endl;
	std::cout << BLUE << "Before swap A = " << a << " and B = " << b << RESET << std::endl;
	swap<int>(a, b);
	std::cout << RED << "After swap  A = " << a << " and B = " << b << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "with float" << RESET << std::endl;
	std::cout << BLUE << "Before swap C = " << c << " and D = " << d << RESET << std::endl;
	swap<float>(c, d);
	std::cout << RED << "After swap  C = " << c << " and D = " << d << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "with char" << RESET << std::endl;
	std::cout << BLUE << "Before swap E = " << e << " and F = " << f << RESET << std::endl;
	swap<char>(e, f);
	std::cout << RED << "After swap  E = " << e << " and F = " << f << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "with string" << RESET << std::endl;
	std::cout << BLUE << "Before swap G = " << g << " and H = " << h << RESET <<std::endl;
	swap(g, h);
	std::cout << RED << "After swap  G = " << g << " and H = " << h << RESET << std::endl << std::endl;

	std::cout << YELLOW << "MIN Test\033[0m" << RESET << std::endl << std::endl;

	std::cout << GREEN << "with int" << RESET << std::endl;
	std::cout << BLUE << "which is the smaller of A and B ?" << RESET << std::endl;
	std::cout << MAGENTA << "knowing that A = " << a << " and B = " << b << std::endl;
	std::cout << RED << "the smallest is " << min<int>(a, b) << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "with float" << RESET << std::endl;
	std::cout << BLUE << "which is the smaller of C and D ?" << RESET << std::endl;
	std::cout << MAGENTA << "knowing that C = " << c << " and D = " << d << std::endl;
	std::cout << RED << "the smallest is " << min<float>(c, d) << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "with char" << RESET << std::endl;
	std::cout << BLUE << "which is the smaller of E and F ?" << RESET << std::endl;
	std::cout << MAGENTA << "knowing that E = " << e << " and F = " << f << std::endl;
	std::cout << RED << "the smallest is " << min<char>(e, f) << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "with string" << RESET << std::endl;
	std::cout << BLUE << "which is the smaller of G and H ?" << RESET << std::endl;
	std::cout << MAGENTA << "knowing that G = " << g << " and H = " << h << std::endl;
	std::cout << RED << "the smallest is " << min(g, h) << RESET << std::endl << std::endl;

	std::cout << YELLOW << "MAX Test\033[0m" << RESET << std::endl << std::endl;

	std::cout << GREEN << "with int" << RESET << std::endl;
	std::cout << BLUE << "which is the Bigger of A and B ?" << RESET << std::endl;
	std::cout << MAGENTA << "knowing that A = " << a << " and B = " << b << std::endl;
	std::cout << RED << "the smallest is " << max<int>(a, b) << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "with float" << RESET << std::endl;
	std::cout << BLUE << "which is the Bigger of C and D ?" << RESET << std::endl;
	std::cout << MAGENTA << "knowing that C = " << c << " and D = " << d << std::endl;
	std::cout << RED << "the smallest is " << max<float>(c, d) << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "with char" << RESET << std::endl;
	std::cout << BLUE << "which is the Bigger of E and F ?" << RESET << std::endl;
	std::cout << MAGENTA << "knowing that E = " << e << " and F = " << f << std::endl;
	std::cout << RED << "the smallest is " << max<char>(e, f) << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "with string" << RESET << std::endl;
	std::cout << BLUE << "which is the Bigger of G and H ?" << RESET << std::endl;
	std::cout << MAGENTA << "knowing that G = " << g << " and H = " << h << std::endl;
	std::cout << RED << "the smallest is " << max(g, h) << RESET << std::endl << std::endl;

	//std::cout << YELLOW << "WRONG Test\033[0m" << RESET << std::endl << std::endl;

	//std::cout << GREEN << "Try to swap an int and a float" << RESET << std::endl;
	//std::cout << BLUE << "Before swap A = " << a << " and C = " << c << RESET << std::endl;
	//swap<int>(a, c); //Uncommenting out the test makes compilation impossible because the type of the two variables are different
	//std::cout << RED << "After swap  A = " << a << " and C = " << c << RESET << std::endl << std::endl;

}	
