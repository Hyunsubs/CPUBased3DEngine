#pragma once

#include <assert.h>
struct COLOR
{
	uint8 a;
	uint8 r;
	uint8 g;
	uint8 b;


template<typename T>
	void operator=(const T& _value)
	{
		if (sizeof(_value) != sizeof(uint32))
		{
			std::cout << "Color Buffer Value Is Not Valid" << std::endl;
			assert(NULL);
		}


		// little endian
		else
		{
			a = (uint32)_value & 0b11111111;
			r = (uint32)_value >> 8 & 0b11111111;
			g = (uint32)_value >> 16 & 0b11111111;
			b = (uint32)_value >> 24 & 0b11111111;
		}
	}


};