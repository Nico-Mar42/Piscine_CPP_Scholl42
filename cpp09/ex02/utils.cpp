#include "PmergeMe.hpp"

std::list<int>::iterator find_index(std::list<int> &container, int idx)
{
	std::list<int>::iterator it ;

	for(it  = container.begin(); it != container.end(); it++){

		if (idx == 0)
			return it;
		idx--;		
	}
	return container.end();
}


void print_list(std::list<int> l)
{
	std::cout << BLUE << "list.size = " << l.size() << std::endl;
	std::cout << "list = ";
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << RESET <<std::endl;
}

void print_vector(std::vector<int> l)
{
	std::cout << BLUE << "vector.size = " << l.size() << std::endl;
	std::cout << "vector = ";
	for (size_t i = 0; i < l.size(); i++) {
		std::cout << l.at(i) << " ";
	}
	std::cout << RESET <<std::endl;
}