#include "BitcoinExchange.hpp"

/* Orthodox Canonical Form */
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_bitcoinValues = other._bitcoinValues;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_bitcoinValues = other._bitcoinValues;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}


/* Helpers */
static bool parseFloat(const std::string &token, float &rate)
{
	std::istringstream str(token);
	float number;
	if (!(str >> number))
		return false;
	char c;
	if (str >> c)
		return false;
	rate = number;
	return true;
}

static bool isValidDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year, month, day;
	std::istringstream y(date.substr(0,4));
	std::istringstream m(date.substr(5,2));
	std::istringstream d(date.substr(8,2));

	if (!(y >> year) || !(m >> month) || !(d >> day))
		return false;

	if (month < 1 || month > 12)
		return false;

	static const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int maxDays = monthDays[month - 1];

	if (month == 2)
	{
		bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (leap)
			maxDays = 29;
	}
	if (day < 1 || day > maxDays)
		return false;

	return true;
}

static void trim(std::string &str)
{
	size_t start = str.find_first_not_of(" \t\r");
	if (start == std::string::npos)
	{
		str.clear();
		return;
	}
	size_t end = str.find_last_not_of(" \t\r");
	str = str.substr(start, end - start + 1);
}


/* Main Logic */
BitcoinExchange::BitcoinExchange(const std::string &databaseFile)
{
	std::ifstream file(databaseFile.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		trim(line);
		if (line.empty())
			continue;

		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date = line.substr(0, comma);
		std::string rateString = line.substr(comma + 1);
		trim(date);
		trim(rateString);

		if (!isValidDate(date))
			continue;

		float rate = 0.0;
		if (!parseFloat(rateString, rate))
			continue;

		_bitcoinValues[date] = rate;
	}

	if (_bitcoinValues.empty())
		throw std::runtime_error("Error: database is empty or invalid.");

}

void BitcoinExchange::processInput(const std::string &inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		trim(line);
		if (line.empty())
			continue;
		
		size_t bar = line.find('|');
		if (bar == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, bar);
		std::string bitcoinString = line.substr(bar + 1);
		trim(date);
		trim(bitcoinString);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		float bitcoin;
		if (!parseFloat(bitcoinString, bitcoin)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (bitcoin < 0.0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (bitcoin > 1000.0) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::const_iterator it = _bitcoinValues.lower_bound(date);
		if (it == _bitcoinValues.end()){
			--it;
		}
		else if (it->first != date)
		{
			if (it == _bitcoinValues.begin()) {
				std::cerr << "Error: no price available before database start for " << date << std::endl;
				continue;
			}
			--it;
		}
		const float rate = it->second;

		std::cout << date << " => " << bitcoin << " = " << (bitcoin * rate) << std::endl;
	}
}
