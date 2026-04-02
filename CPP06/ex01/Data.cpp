#include "Data.hpp"

Data::Data() : id(0), name("Default")
{}

Data::Data(int id, const std::string &name) : id(id), name(name)
{}

Data::Data(const Data &other) : id(other.id), name(other.name)
{}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		id = other.id;
		name = other.name;
	}
	return *this;
}

Data::~Data()
{}

void Data::print() const
{
	std::cout << "Data{id: " << id << ", name: " << name << "}" << std::endl;
}