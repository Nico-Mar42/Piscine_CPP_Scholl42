#include "ScalarConverter.hpp"

int WhatType(const std::string &literal)
{
	size_t lit_len = literal.size() - 1 ;

	int comma = 0;
	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
		return (NAN_TYPE);
	if (literal.compare("+inff") == 0 || literal.compare("-inff") == 0)
		return (INFF_TYPE);
	else if (lit_len == 2 && literal[0] == '\'' && literal[lit_len] == '\'' && isprint(literal[1]) != 0)
		return (CHAR_TYPE);
	else if((literal[0] == '-' || isdigit(literal[0]) != 0))
	{
		for(size_t i = 1; i < lit_len; i++)
		{
			if (isdigit(literal[i]) != 0 || (literal[i] == ',' || literal[i] == '.'))
			{
				if (literal[i] == ',' || literal[i] == '.')
				{
					comma += 1;
				}
			}
			else
				return (OTHER_TYPE);
		}
		if (comma == 0)
			return (INT_TYPE);
		else if (literal[lit_len] == 'f' && comma == 1)
			return (FLOAT_TYPE);
		else if (isdigit(literal[lit_len]) != 0 && comma == 1)
			return (DOUBLE_TYPE);
	}
	return (OTHER_TYPE);
}

void char_to_others(const std::string &literal)
{

	int i = static_cast<int>(literal[1]);

	float f = static_cast<float>(i);

	double d = static_cast<double>(i);

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "Char : " << literal << std::endl;

	std::cout << "Int : " << i << std::endl;

	std::cout << "Float : " << f << "f" << std::endl;
	
	std::cout << "Double : " << d << std::endl;
}

void int_to_others(const std::string &literal)
{
	int i = static_cast<int>(std::strtol(literal.c_str(), NULL, 10));

	char c = static_cast<char>(i);

	float f = static_cast<float>(std::strtof(literal.c_str(), NULL));

	double d = static_cast<double>(std::strtod(literal.c_str(), NULL));

	std::cout << std::fixed << std::setprecision(10);

	if (i < 2147483647 && i > -2147483648 && isprint(i) != 0)
		std::cout << "Char : " << c << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;

	if (std::strtol(literal.c_str(), NULL, 10) <= 2147483647 && std::strtol(literal.c_str(), NULL, 10) >= -2147483648)
		std::cout << "Int : " << i << std::endl;
	else 
		std::cout << "Int : Impossible" << std::endl;

	if (f <= FLT_MAX && f >= -FLT_MAX)
		std::cout << "Float : " << f << "f" << std::endl;
	else
		std::cout << "Float : Impossible"  << std::endl;

	if (d <= DBL_MAX && d >= -DBL_MAX)
		std::cout << "Double : " << d << std::endl;
	else
		std::cout << "Double : Impossible" << std::endl;
}

void float_to_others(const std::string &literal)
{
	float f = static_cast<float>(std::strtof(literal.c_str(), NULL));

	int i = static_cast<int>(std::strtol(literal.c_str(), NULL, 10));

	char c = static_cast<char>(f);
	
	double d = static_cast<double>(std::strtod(literal.c_str(), NULL));

	std::cout << literal << "	" <<  std::strtod(literal.c_str(), NULL) << std::endl;

	std::cout << std::fixed << std::setprecision(10);

	if (f < 2147483647.0f && f > -2147483648.0f && isprint(i) != 0)
		std::cout << "Char : " << c << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;

	if (f <= 2147483647.0f && f >= -2147483648.0f)
		std::cout << "Int : " << i << std::endl;
	else 
		std::cout << "Int : Impossible" << std::endl;

	if (f <= FLT_MAX && f >= -FLT_MAX)
		std::cout << "Float : " << f << "f" << std::endl;
	else
		std::cout << "Float : Impossible" << std::endl;

	if (d <= DBL_MAX && d >= -DBL_MAX)
		std::cout << "Double : " << d << std::endl;
	else
		std::cout << "Double : Impossible" << std::endl;
}

void Double_to_others(const std::string &literal)
{
	double d = static_cast<double>(std::strtod(literal.c_str(), NULL));

	float f = static_cast<float>(std::strtof(literal.c_str(), NULL));

	int i = static_cast<int>(std::strtol(literal.c_str(), NULL, 10));

	char c = static_cast<char>(d);

	std::cout << std::fixed << std::setprecision(10);

	if (d < 2147483647.0 && d > -2147483648.0 && isprint(i) != 0)
		std::cout << "Char : " << c << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;

	if (d <= 2147483647.0f && d >= -2147483648.0f)
		std::cout << "Int : " << i << std::endl;
	else 
		std::cout << "Int : Impossible" << std::endl;

	if (f <= FLT_MAX && f >= -FLT_MAX)
		std::cout << "Float : " << f << "f" << std::endl;
	else
		std::cout << "Float : Impossible" << std::endl;
		
	if (d <= DBL_MAX && d >= -DBL_MAX)
		std::cout << "Double : " << d << std::endl;
}

void other_type()
{
	std::cout << "Char : Impossible" << std::endl;

	std::cout << "Int : Impossible" << std::endl;

	std::cout << "Float : Impossible" << std::endl;
	
	std::cout << "Double : Impossible" << std::endl;
}

void nan_type()
{
	double d = NAN;

	float f = NAN;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "Char: Impossible" << std::endl;

	std::cout << "Int : Impossible" << std::endl;

	std::cout << "Float : " << f << "f" << std::endl;
	
	std::cout << "Double : " << d << std::endl;
}

void inf_type(const std::string &literal)
{
	double d;
	float f;
	if (literal.compare("-inff") == 0)
	{
		d = -std::numeric_limits<double>::infinity();
		f = -std::numeric_limits<float>::infinity();
	}
	else
	{
		d = std::numeric_limits<double>::infinity();
		f = std::numeric_limits<float>::infinity();
	}

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "Char: Impossible" << std::endl;

	std::cout << "Int : Impossible" << std::endl;

	std::cout << "Float : " << f << "f" << std::endl;
	
	std::cout << "Double : " << d << std::endl;
}