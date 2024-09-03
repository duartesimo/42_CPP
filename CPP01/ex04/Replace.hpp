#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
		void replaceString(std::string &line) const;
	public:
		Replace(const std::string &filename, const std::string &s1, const std::string &s2);
		void processFile() const;
};

#endif
