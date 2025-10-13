#include "easyfind.hpp"

int main()
{
	std::cout << YELLOW << "Test my function Easyfind." << RESET << std::endl;
	std::cout << YELLOW << "-------------------------." << RESET << std::endl << std::endl;
 
	std::cout << MAGENTA << "Test With Vector." << RESET << std::endl << std::endl;

	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);

	std::cout << BLUE << "Test numbers is in vector." << RESET << std::endl << std::endl;
	
	if (easyfind(numbers, 4) != numbers.end())
		std::cout << GREEN << 4 << " is in vector" << RESET << std::endl << std::endl;
	else 
		std::cout << RED << 4 << " isn't in vector" << RESET << std::endl << std::endl;

	std::cout << BLUE << "Test numbers isn't in vector." << RESET << std::endl << std::endl;
	
	if (easyfind(numbers, 10) != numbers.end())
		std::cout << GREEN << 10 << " is in vector" << RESET << std::endl << std::endl;
	else 
		std::cout << RED << 10 << " isn't in vector" << RESET << std::endl << std::endl;

	std::cout << MAGENTA << "Test With Deque." << RESET << std::endl << std::endl;
	
	std::deque<int> deq;
	deq.push_back(10);
	deq.push_back(20);
	deq.push_back(30);
	deq.push_back(40);
	deq.push_back(50);

	std::cout << BLUE << "Test numbers is in deque." << RESET << std::endl << std::endl;

	if (easyfind(deq, 30) != deq.end())
		std::cout << GREEN << 30 << " is in deque" << RESET << std::endl << std::endl;
	else 
		std::cout << RED << 30 << " isn't in deque" << RESET << std::endl << std::endl;

	std::cout << BLUE << "Test numbers isn't in deque." << RESET << std::endl << std::endl;

	if (easyfind(deq, 33) != deq.end())
		std::cout << GREEN << 33 << " is in deque" << RESET << std::endl << std::endl;
	else 
		std::cout << RED << 33 << " isn't in deque" << RESET << std::endl << std::endl;

	
	// If you uncomment this part, the program does not compile.
	//std::cout << MAGENTA << "Test with a non-container type." << RESET << std::endl << std::endl;

	//int nbr = 12;
	//if (easyfind(nbr, 12) != deq.end()) 
	//	std::cout << GREEN << 30 << " is in deque" << RESET << std::endl << std::endl;
	//else 
	//	std::cout << RED << 30 << " isn't in deque" << RESET << std::endl << std::endl;

}	
