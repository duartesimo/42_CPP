#include "Span.hpp"


Span::Span(unsigned int N) : _maxSize(N)
{}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{}

Span& Span::operator=(const Span& other)
{
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	// Sort numbers to compute adjacent differences
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); i++)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	int minNum = *std::min_element(_numbers.begin(), _numbers.end());
	int maxNum = *std::max_element(_numbers.begin(), _numbers.end());
	return maxNum - minNum;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int rangeSize = std::distance(begin, end);
	
	if (_numbers.size() + rangeSize > _maxSize)
		throw SpanFullException();

	_numbers.insert(_numbers.end(), begin, end);
}

const char* Span::SpanFullException::what() const throw()
{
	return "Span is full. Cannot add more numbers.";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Not enough numbers to calculate a span.";
}
