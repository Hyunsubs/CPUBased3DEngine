#include "pch.h"
#include <stdio.h>

#include "GameEngine.h"

bool is_running = false;

int main(int argc, char* args[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (is_running = GameEngine::GetInst()->Init())
	{
		std::cout << "Initilize Successed" << std::endl;
	}

	while (is_running)
	{
		GameEngine::GetInst()->Update();
		GameEngine::GetInst()->Render();
	}


	return 0;
}