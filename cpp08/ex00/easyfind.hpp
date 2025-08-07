#pragma once

#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

template<typename T>
typename T::const_iterator easyfind(T const &container, int nbr)
{
	for(typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if(*it == nbr)
		{
			return it;
		} 
	}
	return (container.end());
}
