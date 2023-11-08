#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(const std::string &filename) {
	load_database();
	evaluate(filename);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	if (this != &cpy){
		this->_data = cpy._data;
	}
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this != &cpy) {
		this->_data = cpy._data;
	}
	return (*this);
}

bool	compareDates(std::tm &t1, std::tm &t2) {
	return (std::mktime(&t1) <= std::mktime(&t2));
}

void	BitcoinExchange::load_database() {

	std::ifstream is("data.csv");

	std::string line;
	std::tm	time = {};
	size_t	comma_idx;
	std::string date;
	std::string	val;

	is >> line;
	if (is.good()){
		if (line != "date,exchange_rate") {
			throw InvalidDatabaseFirstLineException();
		}
		while (is >> line) {
			comma_idx = line.find(',');
			date = line.substr(0, comma_idx);
			if (date.length() != 10 || strptime(date.c_str(), "%Y-%m-%d", &time) == NULL) {
				throw std::invalid_argument("Invalid date format in database");
			}
			val = line.substr(comma_idx + 1, date.length());

			char	*endptr;
			double	value;

			value = strtod(val.c_str(), &endptr);
			if (endptr == val.c_str()) {
				throw std::invalid_argument("Failed conversion");
			}
			std::pair<std::tm, double> date_value(time, value);
			_data.push_back(date_value);
		}
		if (_data.size() < 10) {
			std::cerr << "Database size too low, provide a more ample database" << std::endl;
			exit(EXIT_FAILURE);
		}
		is.close();
	}
	else {
		std::cerr << "No database provided" << std::endl;
		exit(EXIT_FAILURE);
	}
}

#include <sstream>

bool	BitcoinExchange::parse_data(const std::string &line, EvaluateData &data) {

	std::istringstream ss(line);
	std::string date;
	std::string dump;
	ss >> date;
	ss >> dump;
	if (date.length() != 10 || strptime(date.c_str(), "%Y-%m-%d", &data.time) == NULL) {
		std::cerr << ss.str() << " => " <<  "Date format is invalid" << "\n";
		return (false);
	} else if (dump != "|") {
		std::cerr << ss.str() << " => " << "Invalid format" << "\n";
		return (false);
	} else if (!(ss >> data.price)) {
		std::cerr << ss.str() << " => " << "Invalid price" << "\n";
		return (false);
	}

	if (data.price > 1000.0){
		std::cerr << ss.str() << " => " << "Bitcoin amount too high [Range: 0 - 1000]" << "\n";
		return (false);
	} else if (data.price < 0.0) {
		std::cerr << ss.str() << " => " << "Bitcoin amount cannot be negative [Range: 0 - 1000]" << "\n";
		return (false);
	}
	return (true);
}

int binarySearchClosestDate(std::list<std::pair<std::tm, double> > &data, std::tm& targetDate) {
    std::list<std::pair<std::tm, double> >::iterator left = data.begin();
    std::list<std::pair<std::tm, double> >::iterator right = data.end();
    int closestIndex = -1;

    while (left != right) {
        std::list<std::pair<std::tm, double> >::iterator mid = left;
		std::advance(mid, std::distance(left, right) / 2);

        if (compareDates(mid->first, targetDate)) {
            closestIndex = std::distance(data.begin(), mid);
            left = mid;
			++left;
        } else {
            right = mid;
        }
    }
    return closestIndex;
}

void	BitcoinExchange::evaluate(const std::string &filename) {
	std::ifstream	is("input.txt");
	std::string		line;
	EvaluateData	data = {};
	size_t			idx;

	if (is.good()) {
		std::getline(is, line);
		if (line != "date | value") {
			throw std::invalid_argument("Input invalid first line");
		}
		while (std::getline(is, line)) {
			if (!parse_data(line, data))
				continue;
			idx = binarySearchClosestDate(_data, data.time);
    		std::list<std::pair<std::tm, double> >::iterator it = _data.begin();
    		std::advance(it, idx);

			std::cout << line << " => " << it->second * data.price << std::endl;
		}
		is.close();
	} else {
		std::cerr << "Input file not found" << std::endl;
	}
}

InvalidDatabaseFirstLineException::InvalidDatabaseFirstLineException() : _msg("Invalid database entry: date,exchange_rate maybe?") {}
InvalidDatabaseFirstLineException::~InvalidDatabaseFirstLineException() throw() {}
const char *InvalidDatabaseFirstLineException::what() const throw()
{
	return (_msg.c_str());
}
