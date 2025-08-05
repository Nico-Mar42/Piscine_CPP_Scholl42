#include "Iter.hpp"

void mult_2(int &i)
{
	i = i *2;
}

void printStr(const char* &str)
{
	std::cout << GREEN << str << RESET << std::endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int i;

	std::cout << YELLOW << "Test of Iter with an Int Array" << RESET << std::endl << std::endl;

	std::cout << GREEN << "before Iter :" << BLUE << std::endl;
	for(i = 0; i < 5; i++)
	{
		std::cout << "the value of " << i << " place of the array is " << arr[i] << std::endl;
	}
	std::cout << RESET << std::endl;

	iter<int>(arr, 5, mult_2);

	std::cout << RED << "After Iter :" << MAGENTA << std::endl;

	for(i = 0; i < 5; i++)
	{
		std::cout << "the value of " << i << " place of the array is " << arr[i] << std::endl;
	}
	std::cout << RESET << std::endl;


	std::cout << YELLOW << "Test of Iter with a LOTR String Array" << RESET << std::endl << std::endl;

	const char* lotrArr[] = {"Frodo", "Samwise", "Gandalf", "Aragorn", "Legolas"};

	iter(lotrArr, 5, printStr);	

}