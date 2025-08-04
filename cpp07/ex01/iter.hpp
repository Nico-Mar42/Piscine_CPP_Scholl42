#pragma once

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

template<typename T>
void iter(T* array, size_t lengh, void (*f)(T&))
{
	for (size_t i = 0; i < lengh; i++)
	{
		f(array[i]);
	}
	return;
}