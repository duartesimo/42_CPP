#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	// Test 1: Point inside
	Point p1(5, 5);
	if (bsp(a, b, c, p1))
		std::cout << "Test 1: Point is inside the triangle\n";
	else
		std::cout << "Test 1: Point is outside the triangle\n";

	// Test case 2: Point outside
	Point p2(10, 10);
	if (bsp(a, b, c, p2))
		std::cout << "Test 2: Point is inside the triangle\n";
	else
		std::cout << "Test 2: Point is outside the triangle\n";

	 // Test case 3: Point on the edge
	Point p3(5, 0);
	if (bsp(a, b, c, p3))
		std::cout << "Test 3: Point is inside the triangle\n";
	else
		std::cout << "Test 3: Point is outside the triangle\n";

	 // Test case 4: Point at the vertex
	Point p4(0, 0);
	if (bsp(a, b, c, p4))
		std::cout << "Test 4: Point is inside the triangle\n";
	else
		std::cout << "Test 4: Point is outside the triangle\n";

	 // Test case 5: Point inside the triangle near the edge
	Point p5(5, 0.1f);
	if (bsp(a, b, c, p5))
		std::cout << "Test 5: Point is inside the triangle\n";
	else
		std::cout << "Test 5: Point is outside the triangle\n";

	// Test case 5: Point outside the triangle near the edge
	Point p6(5, -0.1f);
	if (bsp(a, b, c, p6))
		std::cout << "Test 6: Point is inside the triangle\n";
	else
		std::cout << "Test 6: Point is outside the triangle\n";

	return (0);
}
