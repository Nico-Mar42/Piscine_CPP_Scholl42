#ifndef ARRAY_HPP
 #define ARRAY_HPP

#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <limits.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

template<typename T>
class Array {
public:
	Array<T>();
	Array<T>(unsigned int n);
	Array<T>(const Array& other);
	~Array<T>();

	Array& operator=(const Array& other);
	T& operator[](unsigned int const n);
	const T& operator[](unsigned int const n) const;
	unsigned int size() const;


	class OutOfBoundsException : public std::exception {
		const char* what() const throw()
		{
			return "\033[31mArray index out of bounds\n\033[0m";
		}
	};

private:
	unsigned int _size;
	T* _data;

};

#include "Array.tpp"

#endif
