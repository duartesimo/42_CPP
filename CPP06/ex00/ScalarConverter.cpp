#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{}
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(const std::string &literal)
{
	if (isCharLiteral(literal))
	{
		handleChar(literal);
	}
	else if (isIntLiteral(literal) || isFloatLiteral(literal) || isDoubleLiteral(literal))
	{
		displayChar(literal);
		displayInt(literal);
		displayFloat(literal);
		displayDouble(literal);
	}
	else
	{
		displayImpossible();
	}
}
