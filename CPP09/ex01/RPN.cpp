#include "RPN.hpp"

/* Orthodox Canonical Form */
RPN::RPN()
{}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other) {}
	return *this;
}

RPN::~RPN()
{}

/* Main Logic */
static bool isOperator(const std::string &token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

static int doOperation(int left, int right, char op)
{
	if (op == '+')
		return left + right;
	else if (op == '-')
		return left - right;
	else if (op == '*')
		return left * right;
	else if (op == '/') {
		if (right == 0)
			throw std::runtime_error("Error");
		return left / right;
	}
	else
		throw std::runtime_error("Error");
}

int RPN::evaluate(const std::string &expr) const
{
	std::istringstream str(expr);
	std::string token;
	std::stack<int> stack;

	while (str >> token)
	{
		if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error");
			int right = stack.top();
			stack.pop();
			int left = stack.top();
			stack.pop();
			int res = doOperation(left, right, token[0]);
			stack.push(res);
		}
		else if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
			stack.push(token[0] - '0');
		else
			throw std::runtime_error("Error");
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error");

	return stack.top();
}
