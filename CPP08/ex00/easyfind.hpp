#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"

#endif