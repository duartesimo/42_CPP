#include "Serializer.hpp"

int main()
{
	Data originalData(42, "Test Data");
	std::cout << "Original pointer: " << &originalData << std::endl;

	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized pointer: " << serialized << std::endl;

	Data* deserializedData = Serializer::deserialize(serialized);
	std::cout << "Deserialized pointer: " << deserializedData << std::endl;

	std::cout << "Original data: ";
	originalData.print();
	std::cout << "Deserialized data: ";
	deserializedData->print();

	if (&originalData == deserializedData) {
		std::cout << "Serialization and deserialization successful!" << std::endl;
	} else {
		std::cout << "Error: pointers do not match!" << std::endl;
	}
	return 0;
}
