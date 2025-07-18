#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits.h>

# define OTHER_TYPE 0
# define CHAR_TYPE 1
# define INT_TYPE 2
# define FLOAT_TYPE 3
# define DOUBLE_TYPE 4
# define NAN_TYPE 5
# define INFF_TYPE 6

int WhatType(const std::string &literal);
void char_to_others(const std::string &literal);
void int_to_others(const std::string &literal);
void float_to_others(const std::string &literal);
void Double_to_others(const std::string &literal);
void other_type();
void nan_type();
void inf_type(const std::string &literal);

