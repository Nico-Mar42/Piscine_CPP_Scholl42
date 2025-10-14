#include "RPN.hpp"

RPN::RPN() {
	_Operation = std::stack<std::string>();
}

RPN::RPN(const RPN& other) {
	// Copy constructor
	*this = other;
}

RPN::~RPN() {
	// Destructor
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->_Operation = other._Operation;
	}
	return *this;
}

void RPN::calculate(std::string expr){
	std::string::iterator it = expr.begin();
	std::string::iterator end = expr.end();
	std::string v_1;
	std::string v_2;

	if (!isdigit(*it)){
		std::cerr << RED << "error: first character is not a digit" << RESET << std::endl;
		return ;}
	else{
		std::string tmp(it, it + 1);
		_Operation.push(tmp);}
	it++;
	while(isspace(*it))
		it++;
	if (!isdigit(*it)){
		std::cerr << RED << "error: second character is not a digit" << RESET << std::endl;
		return ;}
	else{
		std::string tmp(it, it + 1);
		_Operation.push(tmp);}
	it++;
	if (!is_sign(*(end - 1))){
		std::cerr << RED << "error: missing operator at the end" << RESET << std::endl;
		return ;}
		
	while(it != expr.end()){
		if (isspace(*it)){
			while(isspace(*it))
				it++;
		}
		else if (is_sign(*it)){
			if (_Operation.size() < 2){
				std::cerr << RED << "error : too many sign" << RESET << std::endl;
				return ;}

			std::string v_2 = _Operation.top();
			_Operation.pop();
			std::string v_1 = _Operation.top();
			_Operation.pop();
			std::string tmp = choice_calcul(atoi(v_1.c_str()), atoi(v_2.c_str()), *it);
			if (tmp == "error")
				return;
			_Operation.push(tmp);
			it++;
		}
		else if (isdigit(*it)){
			std::string tmp(it, it + 1);
			_Operation.push(tmp);
			it++;
		}
		else{
			std::cerr << RED << "error: invalid character '" << *it << "'" << RESET << std::endl;
		return ;}
	}
	if (_Operation.size() == 1)
		std::cout << GREEN << "Result is " << _Operation.top() << RESET << std::endl;
	else{
			std::cerr << RED << "error: stack not empty" << RESET << std::endl;
		return ;}
}

std::string choice_calcul(int f_v, int s_v, int sign){
	std::ostringstream oss;

	if (sign == '+'){
		oss << (f_v + s_v);
		std::string str = oss.str();
		return str;}
	else if (sign == '-'){
		oss << (f_v - s_v);
		std::string str = oss.str();
		return str;}
	else if (sign == '*'){
		oss << (f_v * s_v);
		std::string str = oss.str();
		return str;}
	else if (sign == '/'){
		if (f_v == 0 || s_v == 0){
			std::cerr << RED << "error: division by zero" << RESET << std::endl;
			return "error";}
		oss << (f_v / s_v);
		std::string str = oss.str();
		return str;}
	
	return "error: wrong sign";
}

bool is_sign(int sign){
	if (sign == '+')
		return true;
	else if (sign == '-')
		return true;
	else if (sign == '*')
		return true;
	else if (sign == '/')
		return true;
	return false;
}
