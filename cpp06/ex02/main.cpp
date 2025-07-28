#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>

int main()
{
	Base* test = NULL;

	for (int i = 0; i < 20; i++)
	{
		std::cout << std::endl << "\033[32mTest number " << i + 1 << "\033[0m" << std::endl;
		identify(test);
		identify(*test);
		delete test;
		usleep(1000000);
		test = generate();
	}
	delete test;
	return 0;
}
