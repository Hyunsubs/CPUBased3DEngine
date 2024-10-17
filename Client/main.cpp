#include "pch.h"
#include <stdio.h>

#include "GameEngine.h"

bool is_running = false;

int main(int argc, char* args[])
{
	if (is_running = GameEngine::GetInst()->Init())
	{
		std::cout << "Initilize Successed" << std::endl;
	}

	while (is_running)
	{
		// process_input()
		// update()
		// render()
	}


	return 0;
}