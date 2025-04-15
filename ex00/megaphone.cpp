#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}	
	for(int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (std::isupper(argv[i][j]) == 0)
			{
				argv[i][j] = std::toupper(argv[i][j]);
			}
		}
		std::cout << argv[i] ;
	}
	return 0;
}
// This program takes command line arguments and converts them to uppercase and prints them.