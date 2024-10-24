#include "pch.h"
#include "GameEngine.h"


GameEngine::GameEngine()
	: renderer(nullptr)
	, window(nullptr)
	, color_buf{}
	, render_target_texture(nullptr)
{
}

GameEngine::~GameEngine()
{
	if (color_buf != nullptr)
	{
		delete color_buf;
		color_buf = nullptr;
	}

}

bool GameEngine::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << stderr << ", " << "SDL �ʱ�ȭ ����" << std::endl;
		return false;
	}

	// ��üȭ��� ���� ������� ũ�� �˾Ƴ���
	SDL_GetCurrentDisplayMode(0, &display_mode);

	color_buf = new COLOR[display_mode.w * display_mode.h];

	// SDL ������ �����
	window = SDL_CreateWindow("3D Engine", 
							  SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED, 
							  display_mode.w, 
							  display_mode.h, 0);
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

	ratio = display_mode.w / display_mode.h;


	// ���� Ÿ�� �ؽ�ó ����
	CreateTexture();

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
	ClearColor(0xFFFFFFFF);

	// Grid Rendering
	for (int i = 0; i < display_mode.w; i++)
	{
		for (int j = 0; j < display_mode.h; j++)
		{
			if (i % ((int)(ratio * 50)) == 0 || j % (1 * 50) == 0)
				color_buf[display_mode.w * j + i] = 0xFF000000;
		}
	}


	CopyColorBuffer();

	SDL_RenderPresent(renderer); // ȭ�鿡 ���
}

// �÷� ���� Ŭ����
void GameEngine::ClearColor(uint32 color)
{
	for (int i = 0; i < display_mode.w * display_mode.h; i++)
	{
		color_buf[i] = color;
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

void GameEngine::CreateTexture()
{
	render_target_texture = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, // ������ ���������� ���� lockable(����ȭ ����)
		display_mode.w,
		display_mode.h
	);
}

void GameEngine::CopyColorBuffer()
{
	SDL_UpdateTexture(
		render_target_texture,
		NULL,
		color_buf,
		(int)(display_mode.w * sizeof(uint32))
	);

	SDL_RenderCopy(renderer, render_target_texture, NULL, NULL);
}

