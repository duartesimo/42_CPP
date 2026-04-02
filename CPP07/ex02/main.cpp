#include "Array.hpp"

int main()
{
	try {
		// Default constructor
		Array<int> emptyArray;
		std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

		// Parameterized constructor
		Array<int> intArray(5);
		std::cout << "Size of intArray: " << intArray.size() << std::endl;

		std::cout << "intArray elements: ";
		for (size_t i = 0; i < intArray.size(); ++i) {
			std::cout << intArray[i] << " ";
		}

		for (size_t i = 0; i < intArray.size(); ++i) {
			intArray[i] = static_cast<int>(i * 10);
		}

		std::cout << "\nintArray elements: ";
		for (size_t i = 0; i < intArray.size(); ++i) {
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;

		// Copy constructor
		Array<int> copiedArray = intArray;
		std::cout << "Copied array elements: ";
		for (size_t i = 0; i < copiedArray.size(); ++i) {
			std::cout << copiedArray[i] << " ";
		}
		std::cout << std::endl;

		// Assignment operator
		Array<int> assignedArray;
		assignedArray = intArray;
		std::cout << "Assigned array elements: ";
		for (size_t i = 0; i < assignedArray.size(); ++i) {
			std::cout << assignedArray[i] << " ";
		}
		std::cout << std::endl;

		// Modify original, copies stay same
		intArray[0] = 999;
		std::cout << "Modified intArray[0]: " << intArray[0] << std::endl;
		std::cout << "Copied array first element: " << copiedArray[0] << std::endl;

		// Out-of-bounds
		std::cout << "Accessing out-of-bounds: ";
		std::cout << intArray[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// String array tests
	std::cout << "\n## String Array ##\n";

	Array<std::string> strArray(3);
	std::cout << "Size of strArray: " << strArray.size() << "\n";

	std::cout << "strArray elements: ";
	for (std::size_t i = 0; i < strArray.size(); ++i)
		std::cout << '"' << strArray[i] << "\" ";
	std::cout << "\n";

	strArray[0] = "abc";
	strArray[1] = "def";
	strArray[2] = "ghi";

	std::cout << "strArray elements: ";
	for (std::size_t i = 0; i < strArray.size(); ++i)
		std::cout << '"' << strArray[i] << "\" ";
	std::cout << "\n";

	// Copy and show independence
	Array<std::string> copiedStr = strArray;
	strArray[1] = "xyz";
	std::cout << "After modifying original:\n";
	std::cout << "original: ";
	for (std::size_t i = 0; i < strArray.size(); ++i)
		std::cout << '"' << strArray[i] << "\" ";
	std::cout << "\ncopy:     ";
	for (std::size_t i = 0; i < copiedStr.size(); ++i)
		std::cout << '"' << copiedStr[i] << "\" ";
	std::cout << "\n";

	// Out‑of‑bounds check
	try {
		std::cout << "Accessing out of bounds: " << strArray[5] << "\n";
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << "\n";
	}
	return 0;
}
