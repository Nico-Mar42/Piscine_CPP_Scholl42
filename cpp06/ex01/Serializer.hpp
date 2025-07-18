#pragma once

#include "Serialization.hpp"

class Serializer 
{
public:
	Serializer();
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};