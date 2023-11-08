#pragma once
#include <cstddef>
#include <cstdio>

template<typename T, typename Func>
void	iter(T *a, ssize_t len, Func function) {
	for (ssize_t i = 0; i < len; ++i) {
		function(a[i]);
	}
}

template<typename T>
void	display(T a) {
	std::cout << a << " ";
}