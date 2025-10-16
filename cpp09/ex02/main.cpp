#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	PmergeMe t;
	if (argc <= 1){
		std::cerr << RED << "Error: not enough parameter" << RESET << std::endl;
		return 1;}
	t.sort_vector(&(argv[1]));
	
	t.sort_list(&(argv[1]));
}
