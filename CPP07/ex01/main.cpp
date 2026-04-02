#include "iter.hpp"

template <typename T>
void printElement(const T& elem)
{
	std::cout << elem << " ";
}

template <typename T>
void multiply(T& elem)
{
	elem *= 10;
}

int main()
{
	// Int array
	int intArray[] = {1, 2, 3, 4, 5};
	std::size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original intArray: ";
	iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intArraySize, multiply<int>);

	std::cout << "Multiplied intArray: ";
	iter(intArray, intArraySize, printElement<int>);
	std::cout << std::endl;

	// String array
	std::string strArray[] = {"Hello", "World", "!"};
	std::size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "String array: ";
	iter(strArray, strArraySize, printElement<std::string>);
	std::cout << std::endl;

	// Double array
	double doubleArray[] = {1.1, 2.5, 3.7, 4.4, 5.9};
	std::size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Original doubleArray: ";
	iter(doubleArray, doubleArraySize, printElement<double>);
	std::cout << std::endl;

	iter(doubleArray, doubleArraySize, multiply<double>);

	std::cout << "Rounded doubleArray: ";
	iter(doubleArray, doubleArraySize, printElement<double>);
	std::cout << std::endl;

	return 0;
}
