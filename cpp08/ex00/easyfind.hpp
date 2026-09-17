#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

template<typename T> 
typename T::iterator easyfind(T &a, int b)
{
	typename T::iterator element = std::find(a.begin(), a.end(), b);
	if (element != a.end())
		return (element);
	throw std::runtime_error ("Element not found!");
}