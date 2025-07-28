#pragma once

#include "Scalar_Types.hpp"

int WhatType(const std::string &literal);
void char_to_others(const std::string &literal);
void int_to_others(const std::string &literal);
void float_to_others(const std::string &literal);
void Double_to_others(const std::string &literal);
void other_type();
void nan_type();
void inf_type(const std::string &literal);

class ScalarConverter {
public:
	ScalarConverter();
	~ScalarConverter();
	static void convert(const std::string& literal);


private:
	// Attributes here
	int _attribute;
};

