#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <limits>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class SpanFullException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif