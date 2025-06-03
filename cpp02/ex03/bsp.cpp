#include "Fixed.hpp"
#include "Point.hpp"

static Fixed crossProduct(const Point &a, const Point &b, const Point &p) 
{
    Fixed ab_x = b.getX() - a.getX();
    Fixed ab_y = b.getY() - a.getY();
    Fixed ap_x = p.getX() - a.getX();
    Fixed ap_y = p.getY() - a.getY();

    // Produit vectoriel : ab.x * ap.y - ab.y * ap.x
    return ab_x * ap_y - ab_y * ap_x;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = crossProduct(a, b, point);
    Fixed cross2 = crossProduct(b, c, point);
    Fixed cross3 = crossProduct(c, a, point);

    // Tous positifs ou tous négatifs (strictement)
    bool all_positive = (cross1 > Fixed(0)) && (cross2 > Fixed(0)) && (cross3 > Fixed(0));
    bool all_negative = (cross1 < Fixed(0)) && (cross2 < Fixed(0)) && (cross3 < Fixed(0));

    return all_positive || all_negative;
}

