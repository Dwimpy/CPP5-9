#include <stack>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>

class RPN {

  public:
	enum Operator {
		ADD,
		SUBTRACT,
		MULTIPLY,
		DIVIDE,
	};


	RPN(const std::string &expression);
	~RPN();
	RPN(const RPN &cpy);
	RPN &operator=(const RPN &cpy);

  private:
	std::stack<int, std::vector<int> > _operandStack;

	RPN::Operator char_to_operator(const std::string &op);
	void perform_operation(Operator op);
	bool isOperator(std::string &op);
};