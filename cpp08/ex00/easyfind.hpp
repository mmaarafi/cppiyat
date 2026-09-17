#pragma once

#include <iostream>
#include <exception>
#include <algorithm>

template<typename T> 
typename T::iterator easyfind(T &a, int b)
{
	if (std::find(a.begin(), a.end(), b) != a.end())
		return (std::find(a.begin(), a.end(), b));
	throw std::runtime_error ("Element not found!");
}