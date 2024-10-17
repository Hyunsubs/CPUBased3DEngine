#pragma once

#define SINGLE(Type) private:\
						Type();\
						~Type();\
						friend class CSingleton<Type>;

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;