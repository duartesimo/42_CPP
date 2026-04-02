#include "ScalarConverter.hpp"

bool isCharLiteral(const std::string &literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return true;
	return false;
}

bool isIntLiteral(const std::string &literal)
{
	if (literal.empty())
		return false;
	if (literal == "-" || literal == "+")
		return false;
	if (literal[0] == '-' && literal.size() == 1)
		return false;
	for (size_t i = 0; i < literal.length(); ++i)
		if (!std::isdigit(literal[i]) && (literal[i] != '-' || i != 0))
			return false;
	
	long value = std::strtol(literal.c_str(), NULL, 10);
	if (value < INT_MIN || value > INT_MAX)
		return false;
	
	return true;
}

bool isFloatLiteral(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	if (literal.find('.') != std::string::npos && literal[literal.size() - 1] == 'f')
		return true;
	return false;
}

bool isDoubleLiteral(const std::string &literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	if (literal.find('.') != std::string::npos && literal[literal.size() - 1] != 'f')
		return true;
	return false;
}

void handleChar(const std::string &literal)
{
	char c = literal[0];

	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void displayChar(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" ||
		literal == "+inff" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	double value = std::strtod(literal.c_str(), NULL);
	if (value < 0 || value > 255)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if (!std::isprint(static_cast<int>(value)))
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void displayInt(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" ||
		literal == "+inff" || literal == "-inff")
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	double value = std::strtod(literal.c_str(), NULL);
	if (value < INT_MIN || value > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void displayFloat(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		return;
	}
	if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		return;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		return;
	}
	float value = std::strtof(literal.c_str(), NULL);
	std::cout << std::fixed << std::setprecision(1) << "float: " << value << "f" << std::endl;
}

void displayDouble(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "double: -inf" << std::endl;
		return;
	}
	double value = std::strtod(literal.c_str(), NULL);
	std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
}

void displayImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
