#include "Point.hpp"

// Calculate the area of a triangle
static Fixed area(Point const p1, Point const p2, Point const p3)
{
	Fixed area = (
		(p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) +
		(p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())) +
		(p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) );

	area = area / Fixed(2.0f);

	if (area < 0)
		return area * Fixed(-1);
	return area;
}

// Determine if the point is inside the triangle using the area method
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed Area = area(a, b, c);

	Fixed A1 = area(point, a, b);
	Fixed A2 = area(point, b, c);
	Fixed A3 = area(point, c, a);

	// Check if the point is at the edge/vertex
	if (A1 == Fixed(0) || A2 == Fixed(0) || A3 == Fixed(0))
		return false;

	if (A1 + A2 + A3 == Area)
		return true;
		
	return false;
}
