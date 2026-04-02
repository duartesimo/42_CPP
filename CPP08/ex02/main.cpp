#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(42);

	std::cout << "Top element: " << mstack.top() << std::endl;

	// Iterate through the stack using iterators
	std::cout << "Stack elements: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	mstack.pop();

	std::cout << "After popping one element: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Test reverse iterators
	std::cout << "Stack elements in reverse: ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	// Subject's Tests With Stack
	MutantStack<int> mstack2;

	mstack2.push(5);
	mstack2.push(17);

	std::cout << mstack2.top() << std::endl;
	mstack2.pop();
	std::cout << mstack2.size() << std::endl;

	mstack2.push(3);
	mstack2.push(5);
	mstack2.push(737);
	mstack2.push(0);

	MutantStack<int>::iterator it = mstack2.begin();
	MutantStack<int>::iterator ite = mstack2.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack2);
	std::cout << std::endl;
	std::cout << std::endl;

	// With List
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator it2 = mlist.begin();
	std::list<int>::iterator ite2 = mlist.end();

	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> s2(mlist);

	return 0;
}
