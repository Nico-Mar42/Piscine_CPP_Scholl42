#include "MutantStack.hpp"

int main()
{
	std::cout << RED << "Test Mutant stack" << RESET <<std::endl <<std::endl;

	std::cout << MAGENTA << "create mstack and list with 5 and 17" << RESET <<std::endl <<std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::list<int> list;
	list.push_front(5);
	list.push_front(17);
	std::cout << YELLOW << "the top of mstack = " << mstack.top() << std::endl;
	std::cout << "and the top of list = "<< list.front() << RESET << std::endl << std::endl;
	
	std::cout << MAGENTA << "Delete first element" << RESET <<std::endl <<std::endl;


	mstack.pop();
	list.pop_front();
	std::cout <<BLUE << "the new size of mstack" << mstack.size() << std::endl;
	std::cout << "the new size of list" << list.size() << RESET << std::endl << std::endl;

	std::cout << YELLOW << "the top of mstack = " << mstack.top() << std::endl;
	std::cout << "and the top of list = "<< list.front() << RESET << std::endl << std::endl;

	std::cout << MAGENTA << "Add four element and print all stack" << RESET <<std::endl <<std::endl;

	
	mstack.push(3);
	mstack.push(8);
	mstack.push(737);
	mstack.push(0);

	list.push_back(3);
	list.push_back(8);
	list.push_back(737);
	list.push_back(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator l_it = list.begin();
	++it;
	--it;
	it++;
	it--;
	int i = 0;
	while (it != ite)
	{
	std::cout << BLUE << "at the place number " << i << " in mstack = " << *it << std::endl;
	std::cout << "at the place number " << i << " in list = " << *l_it << RESET << std::endl;
	++it;
	i++;
	++l_it;
	}
	std::stack<int> s(mstack);
	return 0;
}
