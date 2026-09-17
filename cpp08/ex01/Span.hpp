#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span {
	private :
		unsigned int N;
		std::vector<int> S;
	public :
		Span();
		Span(unsigned int N);
		Span(const Span &cp);
		Span &operator=(const Span &obj);
		~Span();
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		template <typename it>
		void addNumbers(it begin, it end)
		{
			if ((this->S.size() + std::distance(begin, end)) < this->N)
				this->S.insert(this->S.end(), begin, end);
			else
				throw std::runtime_error("Span doesn't have enough space!");
		}
};
