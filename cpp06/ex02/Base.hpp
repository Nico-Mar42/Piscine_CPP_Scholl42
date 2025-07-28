#pragma once

#include "string"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <limits.h>

class Base {
public:
	virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);