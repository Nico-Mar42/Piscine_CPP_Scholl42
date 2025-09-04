#include "MutantStack.hpp"


template<class T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T,Container>()
{
	this->_act_pos = this->c.begin();
}

template<class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other) : std::stack<T, Container>(other) 
{
	this->_act_pos = other._act_pos;
}

template<class T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template<class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
		this->_act_pos = other._act_pos;
	}
	return *this;
}

template<class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}

template<class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template<class T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return this->c.end();
}

template<class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

