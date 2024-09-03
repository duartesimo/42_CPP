#include "Replace.hpp"

Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2)
    : _filename(filename), _s1(s1), _s2(s2)
{}

void Replace::processFile() const
{
	//ifstream c++ class to read from files. infile filestream. _filename converted to cstring (char *) because not c++11
	std::ifstream infile(_filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Could not open file " << _filename << std::endl;
		return;
	}

	std::string new_filename = _filename + ".replace";
	std::ofstream outfile(new_filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create file " << new_filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		replaceString(line);
		outfile << line << std::endl;
	}
	
	infile.close();
	outfile.close();
}

void	Replace::replaceString(std::string &line) const
{
	size_t pos = 0;
	while (true)
	{
		pos = line.find(_s1, pos); //search for substring, return * : pos = position to start looking
		if(pos == std::string::npos)
			break;

		line.erase(pos, _s1.length()); //deletes substring : pos = start ; during that length
		line.insert(pos, _s2); //insert substring :pos = start ; string to insert
		pos += _s2.length();
	}
}
