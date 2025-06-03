#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const float x_val, const float y_val)
{
	this->x = Fixed(x_val);
	this->y = Fixed(y_val);
}
Point::Point(const Point& other) : x(other.x), y(other.y) {}
Point::~Point() {}
Point& Point::operator=(const Point& other) 
{
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

Fixed Point::getX() const 
{
	return x;
}
Fixed Point::getY() const 
{
	return y;
}
