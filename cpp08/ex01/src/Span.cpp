#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int n): _capacity(n), _size(0) {}

Span::~Span() {}

Span::Span(const Span &cpy): _data(cpy._data), _capacity(cpy._capacity), _size(cpy._size) {}

Span &Span::operator=(const Span &cpy)
{
	if (this != &cpy) {
		this->_data = cpy._data;
		this->_capacity = cpy._capacity;
		this->_size = cpy._size;
	}
	return (*this);
}
void Span::addNumber(int value)
{
	if (_size >= _capacity)
		throw std::length_error("Container size exceeds capacity");
	_size++;
	_data.__emplace_back(value);
}

void	Span::displaySpan() {
	std::cout << "Span: ";
	for (size_t i = 0; i < _size; ++i) {
		std::cout << _data[i] << " ";
	}
	std::cout << "\n";
}

int Span::shortestSpan()
{
	std::vector<int>	sortedArray;
	int					shortestSpan = INT_MAX;

	sortedArray = _data;
	std::sort(sortedArray.begin(), sortedArray.end());
	for (size_t i = 1; i < sortedArray.size(); i++) {
		shortestSpan = std::min(shortestSpan, sortedArray[i] - sortedArray[i - 1]);
	}
	return (shortestSpan);
}

int Span::longestSpan()
{
	std::vector<int>	sortedArray;
	int					largestSpan = INT_MAX;

	sortedArray = _data;
	std::sort(sortedArray.begin(), sortedArray.end());
	largestSpan = sortedArray.back() - sortedArray.front();
	return (largestSpan);
}
