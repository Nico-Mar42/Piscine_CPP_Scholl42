#include "Span.hpp"

int main()
{
	std::cout << YELLOW << "Test Span Class and function" << RESET <<std::endl <<std::endl;

	std::cout << MAGENTA << "Test with 5 numbers" << RESET << std::endl << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << MAGENTA << "Test with 20 numbers and span is full" << RESET << std::endl << std::endl;
	try
	{
		Span sp = Span(20);
		sp.addNumber(6);
		sp.addNumber(33);
		sp.addNumber(7);
		sp.addNumber(0);
		sp.addNumber(12);
		sp.addNumber(18);
		sp.addNumber(20);
		sp.addNumber(7);
		sp.addNumber(13);
		sp.addNumber(10);
		sp.addNumber(21);
		sp.addNumber(34);
		sp.addNumber(58);
		sp.addNumber(29);
		sp.addNumber(120);
		sp.addNumber(184);
		sp.addNumber(210);
		sp.addNumber(70);
		sp.addNumber(130);
		sp.addNumber(101);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;
		sp.addNumber(103);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	std::cout << MAGENTA << "Test with 10 000 numbers" << RESET << std::endl << std::endl;

	try
	{
		srand(time(NULL));
		Span sp = Span(10000);
		for (int i = 0; i <10000; ++i)
			sp.addNumber(10000 + rand() % 90000);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << MAGENTA << "Test with 0 numbers" << RESET << std::endl << std::endl;

	try
	{
		Span sp = Span();

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << MAGENTA << "Test with 1 numbers" << RESET << std::endl << std::endl;

	try
	{
		Span sp = Span(1);
		sp.addNumber(12);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}	
