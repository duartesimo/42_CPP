#include "PmergeMe.hpp"

/* Orthodox Canonical Form */
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other) {}
	return *this;
}

PmergeMe::~PmergeMe()
{}

/* Ford Johnson Algorithm */
static std::vector<int> jacobsthal_order(int m)
{
	std::vector<int> order;
	if (m <= 0)
		return order;

	// Jacobsthal boundaries 1, 3, 5, 11, ...
	std::vector<int> bound;
	bound.push_back(1);
	bound.push_back(3);
	while (bound.back() < m)
	{
		int next = bound[bound.size() - 1] + 2 * bound[bound.size() - 2];
		bound.push_back(next);
	}

	int prev = 0;
	for (size_t i = 0; i < bound.size(); ++i)
	{
		int end = bound[i];
		if (end > m)
			end = m;
		// m=9; bound[0]=1; push [1-1]; bound[1]=3; push[3-1][2-1]
		for (int k = end; k > prev; --k)
			order.push_back(k - 1);
		prev = end;
		if (prev >= m)
			break;
	}
	return order; // Always same: [0,2,1,4,3,10,9,8,7,6,5,11, ... ]
}


// Ford–Johnson for vector
static void fordJohnson(std::vector<unsigned int> &seq)
{
	const std::size_t len = seq.size();
	if (len <= 1)
		return;

	const std::size_t pairCount = len / 2;

	// Build pairs (winner, pendant) (max, min)
	std::vector< std::pair<unsigned int, unsigned int> > pairs;
	pairs.reserve(pairCount);
	for (std::size_t i = 0; i + 1 < len; i += 2)
	{
		unsigned int a = seq[i];
		unsigned int b = seq[i + 1];
		if (a >= b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	// From pairs vec create winners only vec
	std::vector<unsigned int> winners;
	winners.reserve(pairCount);
	for (std::size_t i = 0; i < pairCount; ++i)
		winners.push_back(pairs[i].first);

	// Deal with potential straggler
	const bool hasStraggler = (len % 2) != 0;
	unsigned int straggler = 0;
	if (hasStraggler)
		straggler = seq[len - 1];

	// Recursively sort winners
	fordJohnson(winners);

	// From pairs vec create pendants only vec
	std::vector<unsigned int> pendants;
	pendants.reserve(pairCount);
	for (std::size_t i = 0; i < pairCount; ++i)
		pendants.push_back(pairs[i].second);


	// Insert pendants in Jacobsthal order BEFORE their paired winner
	std::vector<int> order = jacobsthal_order(static_cast<int>(pendants.size()));
	for (std::size_t i = 0; i < order.size(); ++i)
	{
		const int pair_index = order[i];
		const unsigned int pend = pendants[pair_index];
		const unsigned int paired_winner = pairs[pair_index].first;

		// Find current position of the paired winner
		std::vector<unsigned int>::iterator winnerPos_it = std::lower_bound(winners.begin(), winners.end(), paired_winner);

		// Binary search only from begin until winnerPos_it
		std::vector<unsigned int>::iterator insert_it = std::lower_bound(winners.begin(), winnerPos_it, pend);

		winners.insert(insert_it, pend);
	}

	// Straggler if exists
	if (hasStraggler)
	{
		std::vector<unsigned int>::iterator it = std::lower_bound(winners.begin(), winners.end(), straggler);
		winners.insert(it, straggler);
	}

	// Replace original with sorted result
	seq.swap(winners);
}


// Ford–Johnson for deque
static void fordJohnson(std::deque<unsigned int> &seq)
{
	const std::size_t len = seq.size();
	if (len <= 1)
		return;

	const std::size_t pairCount = len / 2;

	std::deque< std::pair<unsigned int, unsigned int> > pairs;
	for (std::size_t i = 0; i + 1 < len; i += 2)
	{
		unsigned int a = seq[i];
		unsigned int b = seq[i + 1];
		if (a >= b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	// Only diff is no reserve
	std::deque<unsigned int> winners;
	for (std::size_t i = 0; i < pairCount; ++i)
		winners.push_back(pairs[i].first);

	const bool hasStraggler = (len % 2) != 0;
	unsigned int straggler = 0;
	if (hasStraggler)
		straggler = seq[len - 1];

	fordJohnson(winners);

	std::deque<unsigned int> pendants;
	for (std::size_t i = 0; i < pairCount; ++i)
		pendants.push_back(pairs[i].second);

	std::vector<int> order = jacobsthal_order(static_cast<int>(pendants.size()));
	for (std::size_t i = 0; i < order.size(); ++i)
	{
		const int pair_index = order[i];
		const unsigned int pend = pendants[pair_index];
		const unsigned int paired_winner = pairs[pair_index].first;

		std::deque<unsigned int>::iterator winnerPos_it = std::lower_bound(winners.begin(), winners.end(), paired_winner);
		std::deque<unsigned int>::iterator insert_it = std::lower_bound(winners.begin(), winnerPos_it, pend);

		winners.insert(insert_it, pend);
	}

	if (hasStraggler)
	{
		std::deque<unsigned int>::iterator it = std::lower_bound(winners.begin(), winners.end(), straggler);
		winners.insert(it, straggler);
	}

	seq.swap(winners);
}


/* Time */
static long long stopwatch_us()
{
	timeval tv;
	gettimeofday(&tv, 0);
	return static_cast<long long>(tv.tv_sec * 1000000 + tv.tv_usec);
}


/* Main Logic */
void PmergeMe::sortAndDisplay(int argc, char** argv)
{
	std::vector<unsigned int> input;
	for (int i = 1; i < argc; ++i)
	{
		std::string str(argv[i]);
		if (str.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < str.size(); ++j)
		{
			char c = str[j];
			if (c < '0' || c > '9')
				throw std::runtime_error("Error");
		}
		char* end = 0;
		unsigned long lnum = std::strtoul(str.c_str(), &end, 10);
		if (*end != '\0' || lnum == 0 || lnum > UINT_MAX)
			throw std::runtime_error("Error");
		input.push_back(static_cast<unsigned int>(lnum));
	}
	if (input.empty())
		throw std::runtime_error("Error");

	std::cout << "Before: ";
	for (size_t i = 0; i < input.size(); ++i)
		std::cout << input[i] << " ";
	std::cout << "\n";

	long long vecTimeStart = stopwatch_us();
	std::vector<unsigned int> vecSorted(input.begin(), input.end());
	fordJohnson(vecSorted);
	long long vecTimeEnd = stopwatch_us();
	
	long long deqTimeStart = stopwatch_us();
	std::deque<unsigned int> deqSorted(input.begin(), input.end());
	fordJohnson(deqSorted);
	long long deqTimeEnd = stopwatch_us();

	std::cout << "After:  ";
	for (size_t i = 0; i < vecSorted.size(); ++i)
		std::cout << vecSorted[i] << " ";
	std::cout << "\n";

	long long us_vec = vecTimeEnd - vecTimeStart;
	long long us_deq = deqTimeEnd - deqTimeStart;

	std::cout << "Time to process a range of " << vecSorted.size()
		<< " elements with std::vector : " << (us_vec) << " us\n";
	std::cout << "Time to process a range of " << deqSorted.size()
		<< " elements with std::deque  : " << (us_deq) << " us\n";
}

