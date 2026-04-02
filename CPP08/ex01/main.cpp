#include "Span.hpp"

int main()
{
	try {
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		Span largeSpan(10000);
		std::srand(std::time(0));
		for (int i = 0; i < 10000; i++)
			largeSpan.addNumber(std::rand());

		std::cout << "Shortest Span (large set): " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span (large set): " << largeSpan.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		// Span with a capacity of 10
		Span sp(10);

		// Vector numbers
		std::vector<int> numbers;
		numbers.push_back(1);
		numbers.push_back(2);
		numbers.push_back(3);
		numbers.push_back(4);
		numbers.push_back(5);

		sp.addRange(numbers.begin(), numbers.end());

		sp.addNumber(6);
		sp.addNumber(7);

		std::cout << "\n\nShortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		// Vector too many
		std::vector<int> tooMany;
		tooMany.push_back(8);
		tooMany.push_back(9);
		tooMany.push_back(10);
		tooMany.push_back(11);

		// Attempt to add a range that exceeds capacity
		sp.addRange(tooMany.begin(), tooMany.end());
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}