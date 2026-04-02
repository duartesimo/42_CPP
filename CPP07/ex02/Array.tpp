#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), length(0)
{}

template <typename T>
Array<T>::Array(size_t n) : elements(new T[n]()), length(n) //()so values are initialized 0 and not garbage
{}

template <typename T>
Array<T>::Array(const Array<T> &other) : elements(NULL), length(other.length)
{
	if (length > 0)
	{
		elements = new T[length];
		for (size_t i = 0; i < length; ++i)
			elements[i] = other.elements[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] elements;
		length = other.length;

		if (length > 0)
			elements = new T[length];
		else
			elements = NULL;
			
		for (size_t i = 0; i < length; ++i)
			elements[i] = other.elements[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] elements;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= length)
		throw std::out_of_range("Index out of bounds");
	return elements[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= length)
		throw std::out_of_range("Index out of bounds");
	return elements[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return length;
}