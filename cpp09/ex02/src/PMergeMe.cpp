#include "PMergeMe.hpp"


PMergeMe::PMergeMe(const std::string &input)
{

	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;
	std::chrono::microseconds duration;
	start = std::chrono::high_resolution_clock::now();
	process_data(input);
	sort();
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	 for (int i = 0; i < _mainChain.size(); ++i) {
		std::cout << _mainChain[i] << " ";
	}


	 std::chrono::high_resolution_clock::time_point start_deq;
	std::chrono::high_resolution_clock::time_point end_deq;
	std::chrono::microseconds duration_deq;
	start_deq = std::chrono::high_resolution_clock::now();
	process_data_deque(input);
	sort_deque();
	end_deq = std::chrono::high_resolution_clock::now();
	duration_deq = std::chrono::duration_cast<std::chrono::microseconds>(end_deq - start_deq);
	 for (int i = 0; i < _mainChain_deque.size(); ++i) {
		std::cout << _mainChain_deque[i] << " ";
	}
	 std::cout << "\nTime to process a range of " << _mainChain.size() << " elements with std::[vector] : " << duration.count() << " microseconds" << std::endl;
	 std::cout << "\nTime to process a range of " << _mainChain_deque.size() << " elements with std::[deque] : " << duration_deq.count() << " microseconds" << std::endl;
}

void PMergeMe::process_data(const std::string &input) {
	std::istringstream	ss_input(input);
	int	value;
	int counter;
	counter = 0;
	if (ss_input.good()) {
		while (ss_input >> value) {
			if (ss_input.fail()) {
				std::cerr << "Invalid number data" << std::endl;
				exit (EXIT_FAILURE);
			} else if (value < 0) {
				std::cerr << "Numbers cannot be negative" << std::endl;
				exit (EXIT_FAILURE);
			}
			if (counter % 2 == 0)
				_data.__emplace_back(std::make_pair(value, -1));
			else
				_data.back().second = value;
			counter++;
		}
	} else {
		std::cerr << "An error occured" << "\n";
	}
	if (_data.back().second == -1) {
		std::swap(_data.back().first, _data.back().second);
	}
}

void PMergeMe::process_data_deque(const std::string &input) {
	std::istringstream	ss_input(input);
	int	value;
	int counter;
	counter = 0;
	if (ss_input.good()) {
		while (ss_input >> value) {
			if (ss_input.fail()) {
				std::cerr << "Invalid number data" << std::endl;
				exit (EXIT_FAILURE);
			} else if (value < 0) {
				std::cerr << "Numbers cannot be negative" << std::endl;
				exit (EXIT_FAILURE);
			}
			if (counter % 2 == 0)
				_data_deque.push_back(std::make_pair(value, -1));
			else
				_data_deque.back().second = value;
			counter++;
		}
	} else {
		std::cerr << "An error occured" << "\n";
	}
	if (_data_deque.back().second == -1) {
		std::swap(_data_deque.back().first, _data_deque.back().second);
	}
}

void PMergeMe::sort() {
	std::vector<int> pend;
	std::vector<int>::iterator insertion;

	std::sort(_data.begin(), _data.end(), CompareFirstPair());
	_mainChain.reserve((_data.size() + 1) * 2);
	pend.reserve((_data.size() + 1) / 2);
	for (std::vector<std::pair<int, int> >::iterator it = _data.begin(); it != _data.end(); ++it) {
		if (it->first != -1)
			_mainChain.__emplace_back(it->first);
		pend.__emplace_back(it->second);
	}

	std::vector<int>::iterator current_pend = pend.begin();
	for (int k = 0; ; ++k) {
		std::uint_fast64_t diff = jacobsthal_diff[k];
		if (diff > static_cast<std::uint_fast64_t>(std::distance(current_pend, pend.end()))) {
			break ;
		}
		std::vector<int>::iterator pe = current_pend + diff;

		while (pe != current_pend) {
			insertion  = std::upper_bound(_mainChain.begin(), _mainChain.end(), *pe, CompareElem());
			_mainChain.insert(insertion, *pe);
			--pe;
		}
		current_pend += diff;
	}
		while (current_pend != pend.end()) {
			insertion  = std::upper_bound(_mainChain.begin(), _mainChain.end(), *current_pend, CompareElem());
			_mainChain.insert(insertion, *current_pend);
			++current_pend;
		}
}

void PMergeMe::sort_deque() {
	std::deque<int> pend;
	std::deque<int>::iterator insertion;

	std::sort(_data_deque.begin(), _data_deque.end(), CompareFirstPair());
	for (std::deque<std::pair<int, int> >::iterator it = _data_deque.begin(); it != _data_deque.end(); ++it) {
		if (it->first != -1)
			_mainChain_deque.push_back(it->first);
		pend.push_back(it->second);
	}

	std::deque<int>::iterator current_pend = pend.begin();
	for (int k = 0; ; ++k) {
		std::uint_fast64_t diff = jacobsthal_diff[k];
		if (diff > static_cast<std::uint_fast64_t>(std::distance(current_pend, pend.end()))) {
			break ;
		}
		std::deque<int>::iterator pe = current_pend + diff;

		while (pe != current_pend) {
			insertion  = std::upper_bound(_mainChain_deque.begin(), _mainChain_deque.end(), *pe, CompareElem());
			_mainChain_deque.insert(insertion, *pe);
			--pe;
		}
		current_pend += diff;
	}
		while (current_pend != pend.end()) {
			insertion  = std::upper_bound(_mainChain_deque.begin(), _mainChain_deque.end(), *current_pend, CompareElem());
			_mainChain_deque.insert(insertion, *current_pend);
			++current_pend;
		}

}

PMergeMe::~PMergeMe()
{

}

PMergeMe::PMergeMe(const PMergeMe &cpy)
{

}

PMergeMe &PMergeMe::operator=(const PMergeMe &cpy)
{
	return (*this);
}

