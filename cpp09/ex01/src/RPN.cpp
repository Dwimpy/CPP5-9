#include "RPN.hpp"

RPN::RPN(const std::string &expression)
{
	std::istringstream	rpn(expression);
	std::string token;
	int			number;

	while (rpn >> token) {
	if (isOperator(token)) {
		perform_operation(char_to_operator(token));
	} else if (std::istringstream(token) >> number) {
		if (number > 9)
		{
			std::cerr << "Invalid number provided. Range: [ 0 - 9 ]" << "\n";
			exit(EXIT_FAILURE);
		}
		_operandStack.push(number);
		} else {
			std::cerr << "Invalid expression" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	if (_operandStack.size() != 1)
	{
		std::cerr << "Invalid expression" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout <<  _operandStack.top() << std::endl;
}

RPN::Operator RPN::char_to_operator(const std::string &op) {
	if (op == "+")
		return (RPN::ADD);
	else if (op == "-")
		return (RPN::SUBTRACT);
	else if (op == "*")
		return (RPN::MULTIPLY);
	else if (op == "/")
		return (RPN::DIVIDE);
	else
	{
		std::cerr << "Invalid operator detected: [ " << op  << " ]" << "\n";
		exit(EXIT_FAILURE);
	}
}

void RPN::perform_operation(RPN::Operator op) {
	int o1;
	int	o2;

	o2 = _operandStack.top();
	_operandStack.pop();
	o1 = _operandStack.top();
	_operandStack.pop();
	switch (op) {
		case RPN::ADD:
			_operandStack.push(o1 + o2);
			break ;
		case RPN::SUBTRACT:
			_operandStack.push(o1 - o2);
			break ;
		case RPN::MULTIPLY:
			_operandStack.push(o1 * o2);
			break ;
		case RPN::DIVIDE:
			if (o2 == 0) {
				std::cout << "Division by zero, exiting" << "\n";
				break ;
			}
			_operandStack.push(o1 / o2);
			break ;
	}
}

bool RPN::isOperator(std::string &op) {
	return (op == "+" || op == "-" || op == "*" || op == "/");
}

RPN::~RPN() {}

RPN::RPN(const RPN &cpy)
{
	if (this != &cpy) {
		this->_operandStack = cpy._operandStack;
	}
}

RPN &RPN::operator=(const RPN &cpy)
{
	if (this != &cpy) {
		this->_operandStack = cpy._operandStack;
	}
	return (*this);
}
