#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <stack>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	MutantStack& operator=(const MutantStack& other);



	
private:
	iterator _act_pos;
};

#include "MutantStack.tpp"

#endif
