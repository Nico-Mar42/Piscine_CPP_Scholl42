
#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

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

void print_vector(std::vector<int> l);

std::list<int>::iterator find_index(std::list<int> &container, int idx);
void print_list(std::list<int> l);

class PmergeMe {
	private:
		std::list<int> _Pmerge_list;

		std::vector<int> _Pmerge_vect;

	public:
		PmergeMe();
		PmergeMe(PmergeMe &other);
		PmergeMe &operator=(PmergeMe &other);
		~PmergeMe();

		std::list<int>	get_list();
		std::vector<int> get_vect();

		void sort_list(const char *argv[]);
		void sort_vector(const char *argv[]);

		void list_big_sort(std::list<int> &big);
		int list_little_insert(std::list<int> &little);

		void vect_big_sort(std::vector<int> &big);
		int vect_little_insert(std::vector<int> &l);
	
};

bool check_param(const char *argv[]);


#endif
