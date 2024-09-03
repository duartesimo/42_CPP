#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY())
{}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
		return *this;
	return *this;
}

Point::~Point()
{}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}
