#include "Serializer.hpp"
#include <iostream>

#include <iomanip>

#include <iostream>
#include "Serializer.hpp"

int main()
{
	std::cout << "\033[36m=== Serialization Demo ===\033[0m" << std::endl;

	Data* ptr1 = new Data;
	ptr1->nbr_of_chicken = 26000000000;
	ptr1->nbr_of_humans = 8235316392;

	uintptr_t raw = Serializer::serialize(ptr1);
	Data* ptr2 = Serializer::deserialize(raw);

	std::cout << "\nRaw pointer value: \033[33m" << raw << "\033[0m" << std::endl;

	std::cout << "\n\033[32mOriginal Data (ptr1):\033[0m" << std::endl;
	std::cout << "  Number of chickens: \033[35m" << ptr1->nbr_of_chicken << "\033[0m" << std::endl;
	std::cout << "  Number of humans:   \033[35m" << ptr1->nbr_of_humans << "\033[0m" << std::endl;

	std::cout << "\n\033[31mDeserialized Data (ptr2):\033[0m" << std::endl;
	std::cout << "  Number of chickens: \033[35m" << ptr2->nbr_of_chicken << "\033[0m" << std::endl;
	std::cout << "  Number of humans:   \033[35m" << ptr2->nbr_of_humans << "\033[0m" << std::endl;

	// === Tests ===
	std::cout << "\n\033[36m=== Test Results ===\033[0m\n";

	bool same_pointer = (ptr1 == ptr2);
	bool same_values = (ptr1->nbr_of_chicken == ptr2->nbr_of_chicken) &&
	                   (ptr1->nbr_of_humans == ptr2->nbr_of_humans);

	std::cout << "Pointer equality: " << (same_pointer ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m") << std::endl;
	std::cout << "Data consistency: " << (same_values   ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m") << std::endl;

	// Test with NULL
	std::cout << "\n\033[36m=== Null Pointer Test ===\033[0m\n";
	Data* null_ptr = NULL;
	uintptr_t null_raw = Serializer::serialize(null_ptr);
	Data* recovered_null = Serializer::deserialize(null_raw);

	std::cout << "Null pointer test: " << (recovered_null == NULL ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m") << std::endl;

	delete ptr1;
	return 0;
}

