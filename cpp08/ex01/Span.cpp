#include "Span.hpp"

Span::Span(): N(10) {}

Span::Span(unsigned int N): N(N) {}

Span::Span(const Span &original): N(original.N), S(original.S) {}

Span &Span::operator=(const Span &obj)
{
	if (this == &obj)
		return (*this);
	N = obj.N;
	S = obj.S;
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (this->S.size() < this->N)
		this->S.push_back(number);
	else
		throw std::runtime_error("Span already full!");
}

long Span::shortestSpan()
{
	if (this->S.size() >= 2)
	{
		std::vector<int> copy = this->S;
		std::sort(copy.begin(), copy.end());
		long min_span = copy[1] - copy[0];
		for (size_t i = 2; i < copy.size(); ++i)
		{
			long current_span = copy[i] - copy[i - 1];
			if (current_span < min_span)
				min_span = current_span;
		}
		return min_span;
	}
	else
		throw std::runtime_error("Span needs to be equal or more then 2 numbers!");
}

long Span::longestSpan()
{
	if (this->S.size() >= 2)
	{
		std::vector<int>::iterator min = std::min_element(this->S.begin(), this->S.end());
		std::vector<int>::iterator max = std::max_element(this->S.begin(), this->S.end());
		return (*max - *min);
	}
	else
		throw std::runtime_error("Span needs to be equal or more then 2 numbers!");
}
