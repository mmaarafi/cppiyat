#pragma once

#include <iostream>
#include <stdint.h>

struct Data {
	int num;
};

class Serializer {	
	private :
		virtual void method() const = 0;
	public :
		Serializer();
		Serializer(const Serializer &cp);
		Serializer &operator=(const Serializer &obj);
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

