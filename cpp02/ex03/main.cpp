#include "Fixed.hpp"
#include "Point.hpp"

int main()	
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	Point p1(5, 5);   // inside
	Point p2(5, 0);   // on edge
	Point p3(10, 10); // outside

	std::cout << "Test p1 (5,5) inside triangle: " 
			  << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;

	std::cout << "Test p2 (5,0) on edge of triangle: " 
			  << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;

	std::cout << "Test p3 (10,10) outside triangle: " 
			  << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;
}