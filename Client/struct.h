#pragma once

// ARGB Format
struct COLOR
{
public:
	uint32 color_buffer;

public:
	uint8 a = *(uint8*)&color_buffer;
	uint8 r = *(uint8*)&color_buffer+1;
	uint8 g = *(uint8*)&color_buffer+2;
	uint8 b = *(uint8*)&color_buffer+3;



template <typename T>
	void operator=(T _Value)
	{
		color_buffer = _Value;
	}

};