#include "pch.h"
#include "GameEngine.h"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

bool GameEngine::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << stderr << ", " << "SDL �ʱ�ȭ ����" << std::endl;
		return false;
	}

	// SDL ������ �����
	window = SDL_CreateWindow("3D Engine", 
							  SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED, 
							  WINDOW_WIDTH, 
							  WINDOW_HEIGHT, 0);
	if (nullptr == window)
	{
		std::cout << stderr << ", SDL ������ ���� ����" << std::endl;
		return false;
	}

	// SDL ������ �����
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (nullptr == renderer)
	{
		std::cout << stderr << ", SDL ������ ���� ����" << std::endl;
		return false;
	}

	return true;
}

void GameEngine::ProcessInput()
{
}

void GameEngine::Update()
{
}

void GameEngine::Render()
{
}
