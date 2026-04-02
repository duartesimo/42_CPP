#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
	public:
		int id;
		std::string name;

		Data();
		Data(int id, const std::string &name);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();

		void print() const;
};

#endif
