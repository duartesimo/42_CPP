#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void convert(const std::string &literal);
};


bool isCharLiteral(const std::string &literal);
bool isIntLiteral(const std::string &literal);
bool isFloatLiteral(const std::string &literal);
bool isDoubleLiteral(const std::string &literal);
void handleChar(const std::string &literal);
void displayChar(const std::string &literal);
void displayInt(const std::string &literal);
void displayFloat(const std::string &literal);
void displayDouble(const std::string &literal);
void displayImpossible();

#endif
