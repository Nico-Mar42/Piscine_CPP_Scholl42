#ifndef ARRAY_TPP
 #define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array() 
{
	this->_size = 0;
	this->_data = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(new T[n]())
{

}

template<typename T>
Array<T>::Array(const Array<T>& other) :  _size(other._size)
{
	this->_data = new T[this->_size];
	for(unsigned int i = 0; i < this->_size; ++i)
	{
		this->_data[i] = other._data[i];
	}
}

template<typename T>
Array<T>::~Array() 
{
	delete[] this->_data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] this->_data;
		this->_size = other._size;
		this->_data = new T[this->size];
		for(unsigned int i = 0; i < this->_size; ++i)
		{
			this->_data[i] = other._data[i];
		}
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int const n)
{
	if (n >= this->_size)
		throw Array<T>::OutOfBoundsException();
	else
	{
		return this->_data[n];
	}
}

template<typename T>
const T& Array<T>::operator[](unsigned int const n) const
{
	if (n >= this->_size)
		throw Array<T>::OutOfBoundsException();
	else
	{
		return this->_data[n];
	}
}

template<typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

#endif
