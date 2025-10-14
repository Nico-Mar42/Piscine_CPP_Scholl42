#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

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

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

std::map<std::string ,float> make_map(char const *data_name);
void print_rslt(std::map<std::string ,float> data, std::string histo);
#endif