#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Error\n";
		return 1;
	}
	try {
		PmergeMe sorter;
		sorter.sortAndDisplay(argc, argv);
		return 0;
	} catch (const std::exception& error) {
		std::cerr << error.what() << std::endl;
		return 1;
	}
}