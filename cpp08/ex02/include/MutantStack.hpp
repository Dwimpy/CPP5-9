#pragma once

#include <stack>
#include <list>
#include <algorithm>

template<typename T>
  class MutantStack: public std::stack<T> {
  public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator rev_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator rev_const_iterator;


	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack &cpy) {
		*this = cpy;
	}
	MutantStack &operator=(const MutantStack &cpy) {
		if (this != &cpy) {
			*this = cpy;
		}
		return (*this);
	}

	iterator begin() {
		return (std::stack<T>::c.begin());
	}

	iterator end() {
		return (std::stack<T>::c.end());
	}

	const_iterator cbegin() const{
		return (std::stack<T>::c.cbegin());
	}

	const_iterator cend() const {
		return (std::stack<T>::c.cend());
	}


	rev_iterator rbegin() {
		return (std::stack<T>::c.rbegin());
	}

	rev_iterator rend() {
		return (std::stack<T>::c.rend());
	}

	rev_const_iterator rbegin() const{
		return (std::stack<T>::c.rbegin());
	}

	rev_const_iterator rend() const {
		return (std::stack<T>::c.rend());
	}
};