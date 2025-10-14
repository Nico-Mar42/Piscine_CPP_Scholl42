#ifndef RPN_HPP
	#define RPN_HPP

#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>
#include <sstream>
#include <iterator>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

bool check_digit(std::string s);


class RPN{
	private:
		std::stack<std::string> _Operation;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		void clear();

		void calculate(std::string expr);
};


std::string choice_calcul(int f_v, int s_v, int sign);
bool is_sign(int sign);
#endif