#ifndef POINT_HPP
	#define POINT_HPP


# include "Fixed.hpp"

class Point
{
public:
	// Constructeur par défaut
	Point();
	// Constructeur avec paramètres
	Point(const float x_val, const float y_val);
	// Constructeur de copie
	Point(const Point& other);
	// Destructeur
	~Point();
	// Opérateurs d'affectation
	Point& operator=(const Point& other);

	// Accesseurs
	Fixed getX() const;
	Fixed getY() const;

private:
	Fixed x; // Coordonnée x
	Fixed y; // Coordonnée y
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif