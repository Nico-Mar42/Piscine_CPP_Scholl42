#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
	// Destructor
}

void ScalarConverter::convert(const std::string &literal)
{
	switch (WhatType(literal))
	{
	case CHAR_TYPE:
		char_to_others(literal);
		break;

	case INT_TYPE:
		int_to_others(literal);
		break;
	case FLOAT_TYPE:
		float_to_others(literal);
		break;

	case DOUBLE_TYPE:
		Double_to_others(literal);
		break;

	case NAN_TYPE:
		nan_type();
		break;

	case INFF_TYPE:
		inf_type(literal);
		break;

	case OTHER_TYPE:
		other_type();
		break;

	default:
		break;
	}
	return;
}

