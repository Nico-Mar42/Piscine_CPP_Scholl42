#pragma once

#include "Scalar_Types.hpp"


class ScalarConverter {
public:
	ScalarConverter();
	~ScalarConverter();
	static void convert(const std::string& literal);


private:
	// Attributes here
	int _attribute;
};

