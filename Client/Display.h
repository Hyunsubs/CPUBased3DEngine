#pragma once
#include "singleton.h"

class Display :
    public CSingleton<Display>
{
    SINGLE(Display)

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* render_target_texture;
	SDL_DisplayMode display_mode;

	COLOR* color_buf;

	float ratio;

public:
    bool Init();
	void Render();

	void ClearColor(uint32 color);
	void DrawRect(int x, int y, int width, int height, uint32 color);
	void CreateTexture();
	void CopyColorBuffer();

	
public:
	SDL_Window* GetSDLWindow() { return window; }
	SDL_Renderer* GetSDLRenderer() { return renderer; }

};

