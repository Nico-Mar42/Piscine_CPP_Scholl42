#pragma once

#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <ctime>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class Span {
public:
	Span();
	Span(unsigned const N);
	Span(const Span& other);
	~Span();

	Span& operator=(const Span& other);
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();

	class SpanIsFull : public std::exception 
	{
	public:
		const char* what() const throw() {
			return "Cannot add numbers: span is full\n";
		}
	};
	class NotManySpan : public std::exception 
	{
	public:
		const char* what() const throw() {
			return "Impossible to compute a span: not enough numbers stored\n";
		}
	};
		
private:
	std::vector<int> _span;
	unsigned const _N;
};