#pragma once

#include <vector>

class Span {

  public:
	Span(unsigned int n);
	~Span();
	Span(const Span &cpy);
	Span &operator=(const Span &cpy);
	void addNumber(int value);
	int	shortestSpan();
	int longestSpan();
	void displaySpan();

  private:
	std::vector<int>	_data;
	std::size_t			_size;
	std::size_t			_capacity;
};
