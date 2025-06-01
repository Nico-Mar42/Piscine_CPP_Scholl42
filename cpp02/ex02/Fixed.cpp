#include "Fixed.hpp"

const int Fixed::bits_nbr = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_nbr = 0;
}

Fixed::Fixed(int const nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_nbr = nbr << bits_nbr;
}

Fixed::Fixed(float const nbr_f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_nbr = roundf(nbr_f * (1 << bits_nbr));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_nbr = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->_nbr);
}

void Fixed::setRawBits(int const raw)
{
	this->_nbr = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_nbr) / (1 << bits_nbr));
}

int Fixed::toInt( void ) const
{
	return( static_cast <float> (this->_nbr >> bits_nbr));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}