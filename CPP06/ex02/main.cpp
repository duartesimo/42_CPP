#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));

	Base* obj = generate();

	// By pointer
	identify(obj);

	// By reference
	identify(*obj);

	delete obj;

	return 0;
}
