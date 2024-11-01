#include "pch.h"
#include "Display.h"


Display::Display()
{

}

Display::~Display()
{
	if (color_buf != nullptr)
	{
		delete color_buf;
		color_buf = nullptr;
	}
}

bool Display::Init()
{
	// 전체화면용 현재 모니터의 크기 알아내기
	SDL_GetCurrentDisplayMode(0, &display_mode);

	color_buf = new COLOR[display_mode.w * display_mode.h];

	// SDL 윈도우 만들기
	window = SDL_CreateWindow("3D Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		display_mode.w,
		display_mode.h, 0);

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

	ratio = display_mode.w / display_mode.h;


	// 렌더 타겟 텍스처 생성
	CreateTexture();

	return true;
}

void Display::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	ClearColor(0xFFFFFFFF);

	// Actual Content Rendering 여기가 분리돼야 함
	DrawRect(150, 150, 300, 300, 0xFFFF0000);
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
	SDL_RenderPresent(renderer); // 화면에 출력
}

void Display::ClearColor(uint32 color)
{
	for (int i = 0; i < display_mode.w * display_mode.h; i++)
	{
		color_buf[i] = color;
	}
}

void Display::DrawRect(int x, int y, int width, int height, uint32 color)
{
	int start_pos_x = x - width / 2;
	int start_pos_y = y - height / 2;
	if (start_pos_x < 0)
		start_pos_x = 0;
	if (start_pos_y < 0)
		start_pos_y = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int target_idx = (display_mode.w * start_pos_y + start_pos_x) + (display_mode.w * i) + j;
			color_buf[target_idx] = color;
		}
	}
}

void Display::CreateTexture()
{
	render_target_texture = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, // 수정이 수시적으로 가능 lockable(동기화 가능)
		display_mode.w,
		display_mode.h
	);
}

void Display::CopyColorBuffer()
{
	SDL_UpdateTexture(
		render_target_texture,
		NULL,
		color_buf,
		(int)(display_mode.w * sizeof(uint32))
	);

	SDL_RenderCopy(renderer, render_target_texture, NULL, NULL);
}
