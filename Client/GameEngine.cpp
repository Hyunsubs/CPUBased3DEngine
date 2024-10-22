#include "pch.h"
#include "GameEngine.h"


GameEngine::GameEngine()
	: renderer(nullptr)
	, window(nullptr)
{
}

GameEngine::~GameEngine()
{
	if (color_buf != nullptr)
	{
		for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
		{
			delete(color_buf[i]);
			color_buf[i] = nullptr;
		}
	}
}

bool GameEngine::Init()
{
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
	{
		color_buf[i] = new COLOR;
	}

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
	SDL_Event event;
	SDL_PollEvent(&event);
	SDLEventCheck(event);

}

void GameEngine::Update()
{
}

void GameEngine::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	// Render Something



	SDL_RenderPresent(renderer);
}

void GameEngine::ClearColor()
{
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
	{
		color_buf[i]->color_buffer = 0;
	}
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

