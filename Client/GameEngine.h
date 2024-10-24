#pragma once
class GameEngine :
	public CSingleton<GameEngine>
{
	SINGLE(GameEngine)

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* render_target_texture;
	SDL_DisplayMode display_mode;

	COLOR* color_buf;

	float ratio;

public:
	bool Init();
	void ProcessInput();
	void Update();
	void Render();

public:
	void ClearColor(uint32 color);


private:
	void SDLEventCheck(SDL_Event& event);
	void CreateTexture();
	void CopyColorBuffer();

public:
	SDL_Window* GetSDLWindow() { return window; }
	SDL_Renderer* GetSDLRenderer() { return renderer; }

};

