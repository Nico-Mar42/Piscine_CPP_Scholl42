#include "Span.hpp"





Span::Span() : _N(0) {}

Span::Span(unsigned const N) : _N(N) {}

Span::Span(const Span& other)  : _N(other._N) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_span = other._span;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_span.size() == this->_N)
		throw SpanIsFull();
	else
		_span.push_back(n);
}

int Span::shortestSpan()
{
	if (_span.size() <= 1)
		throw NotManySpan();
	else 
	{
		int shortest = INT_MAX;
		std::vector<int> copy = this->_span;
		std::sort(copy.begin(), copy.end());
		for (std::vector<int>::iterator it = copy.begin(); it < copy.end() - 1; ++it)
		{
			if (*(it+1) - *it < shortest)
				shortest = *(it+1) - *it;
		}
		return (shortest);
	}
}

int Span::longestSpan()
{
	if (_span.size() <= 1)
		throw NotManySpan();
	else 
	{
		int longest;
		std::vector<int> copy = this->_span;
		std::sort(copy.begin(), copy.end());
		longest = copy.back() - copy.front();
		return (longest);
	}
}