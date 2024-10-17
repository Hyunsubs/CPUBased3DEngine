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
		std::cout << stderr << ", " << "SDL 초기화 실패" << std::endl;
		return false;
	}

	// SDL 윈도우 만들기
	window = SDL_CreateWindow("3D Engine", 
							  SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED, 
							  WINDOW_WIDTH, 
							  WINDOW_HEIGHT, 0);
	if (nullptr == window)
	{
		std::cout << stderr << ", SDL 윈도우 생성 실패" << std::endl;
		return false;
	}

	// SDL 렌더러 만들기
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (nullptr == renderer)
	{
		std::cout << stderr << ", SDL 렌더러 생성 실패" << std::endl;
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
