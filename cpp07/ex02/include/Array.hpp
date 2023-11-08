#pragma once

template<typename T>
class Array {
  public:
	Array(): _arr(new T()), _size(0) {};
	Array(unsigned int n): _arr(new T[n]()), _size(n) {};
	Array(const Array &cpy): _arr(new T[cpy._size]()), _size(cpy._size) {
		for (size_t i = 0; i < cpy._size; ++i) {
			_arr[i] = cpy._arr[i];
		}
	}
	Array &operator=(const Array &cpy) {
		if (this != &cpy) {
			delete[] _arr;

			_arr = new T[cpy._size];
			for (size_t i = 0; i < cpy._size; ++i) {
				_arr[i] = cpy[i];
			}
		}
		return (*this);
	}

	T &operator[](std::size_t index) {
		if (index >= _size) {
			throw std::out_of_range("Index out of bounds");
		}
		return (_arr[index]);
	}

	T &operator[](std::size_t index) const {
		if (index >= _size) {
			throw std::out_of_range("Index out of bounds");
		}
		return (_arr[index]);
	}

	~Array() { delete[] _arr; };
	std::size_t size() {
		return (_size);
	}

  private:
	T			*_arr;
	std::size_t	_size;
};