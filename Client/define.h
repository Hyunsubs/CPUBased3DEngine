#pragma once

#define SINGLE(Type) private:\
						Type();\
						~Type();\
						friend class CSingleton<Type>;

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720