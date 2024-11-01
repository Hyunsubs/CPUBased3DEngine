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
		std::cout << stderr << ", " << "SDL �ʱ�ȭ ����" << std::endl;
		return false;
	}

	if (Display::GetInst()->Init() == false)
	{
		std::cout << stderr << ", " << "���÷��� �ʱ�ȭ ����" << std::endl;
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
	// �Է� �� delta time ��� ������Ʈ
	ProcessInput();

}

void GameEngine::Render()
{
	Display::GetInst()->Render();

	// Content Rendering


	Display::GetInst()->CopyColorBuffer();
	SDL_RenderPresent(Display::GetInst()->GetSDLRenderer()); // ȭ�鿡 ���
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

