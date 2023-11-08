#pragma once

#include <list>
#include <ctime>
#include <string>

struct EvaluateData {
	std::tm	time;
	double	price;
};

class BitcoinExchange {

  public:
	BitcoinExchange(const std::string &filename);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &cpy);

  private:
	std::list<std::pair<std::tm, double> >	_data;
	void load_database();
	void evaluate(const std::string &filename);
	bool parse_data(const std::string &line, EvaluateData &data);
};

  class InvalidDatabaseFirstLineException: public std::exception {

	public:
		InvalidDatabaseFirstLineException() ;
		~InvalidDatabaseFirstLineException() throw();
		virtual const char *what() const throw();

	private:
	  std::string _msg;
  };