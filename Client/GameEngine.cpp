#include "pch.h"
#include "GameEngine.h"
#include "Display.h"

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

	if (Display::GetInst()->Init() == false)
	{
		std::cout << stderr << ", " << "디스플레이 초기화 실패" << std::endl;
		return false;
	}

	return true;
}

void GameEngine::ProcessInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	SDLEventCheck(event);

}

void GameEngine::Update()
{
	// 입력 외 delta time 등등 업데이트


}

void GameEngine::Render()
{
	Display::GetInst()->Render();
	// 게임 레벨 Render

}


void GameEngine::SDLEventCheck(SDL_Event& event)
{
	extern bool is_running;
	switch (event.type)
	{
	case SDL_QUIT:
		is_running = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			is_running = false;
		}
		break;

	default:
		break;
	}
}

