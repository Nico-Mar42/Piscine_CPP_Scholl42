#include "Fixed.hpp"

// Static constant
const int Fixed::bits_nbr = 8;

// =========================
// Constructors / Destructor
// =========================

Fixed::Fixed()
{
	this->_nbr = 0;
}

Fixed::Fixed(int const nbr)
{
	this->_nbr = nbr << bits_nbr;
}

Fixed::Fixed(float const nbr_f)
{
	this->_nbr = roundf(nbr_f * (1 << bits_nbr));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::~Fixed()
{
}

// =========================
// Assignment operators
// =========================

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->_nbr = other.getRawBits();
	}
	return (*this);
}

// =========================
// Accessors
// =========================

int Fixed::getRawBits(void) const
{
	return (this->_nbr);
}

void Fixed::setRawBits(int const raw)
{
	this->_nbr = raw;
}

// =========================
// Conversion
// =========================

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_nbr) / (1 << bits_nbr));
}

int Fixed::toInt( void ) const
{
	return( static_cast <float> (this->_nbr >> bits_nbr));
}

// =========================
// Operator << overload
// =========================

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

// =========================
// Comparison operators
// =========================

bool Fixed::operator>(const Fixed& other) const {
	return this->_nbr > other._nbr;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_nbr < other._nbr;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_nbr >= other._nbr;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_nbr <= other._nbr;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_nbr == other._nbr;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_nbr != other._nbr;
}

// =========================
// Arithmetic operators
// =========================

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_nbr + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_nbr - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	long tmp = static_cast<long>(this->_nbr) * static_cast<long>(other._nbr);
	result.setRawBits(static_cast<int>(tmp >> bits_nbr));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	if (other._nbr == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return result;
	}
	long tmp = (static_cast<long>(this->_nbr) << bits_nbr) / other._nbr;
	result.setRawBits(static_cast<int>(tmp));
	return result;
}

// =========================
// Increment/Decrement operators
// =========================

Fixed& Fixed::operator++() {
	this->_nbr++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_nbr++;
	return tmp;
}

Fixed& Fixed::operator--() {
	this->_nbr--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_nbr--;
	return tmp;
}

// =========================
// Min/Max functions
// =========================

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return(a);
	else
		return(b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return(a);
	else
		return(b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return(a);
	else
		return(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return(a);
	else
		return(b);
}
