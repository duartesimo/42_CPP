#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>

template<typename C>
void runTest(C& container, int value, const char* name)
{
    std::cout << "Searching for " << value << " in " << name << "... ";
    try {
        // Returns iterator, can get value with *it
        typename C::iterator it = easyfind(container, value);

        // Get index
        std::size_t i = 0;
        for (typename C::iterator itr = container.begin(); itr != it; ++itr) {
            ++i;
        }

        std::cout << "found at position " << i << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "not found (" << e.what() << ")" << std::endl;
    }
}

int main()
{
    // vector
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    runTest(v, 50, "vector");
    runTest(v, 99, "vector");

    // list
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    runTest(l, 3, "list");
    runTest(l, 42, "list");

    // deque
    std::deque<int> d;
    d.push_back(7);
    d.push_back(14);
    d.push_back(21);
    d.push_back(28);
    runTest(d, 28, "deque");
    runTest(d, 99, "deque");

    return 0;
}
