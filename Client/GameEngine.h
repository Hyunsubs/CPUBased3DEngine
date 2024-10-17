#pragma once
class GameEngine :
	public CSingleton<GameEngine>
{
	SINGLE(GameEngine)

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	static COLOR color_buffers[WINDOW_WIDTH * WINDOW_HEIGHT];

public:
	bool Init();
	void ProcessInput();
	void Update();
	void Render();

public:
	void ClearColor();


private:
	void SDLEventCheck(SDL_Event& event);

public:
	SDL_Window* GetSDLWindow() { return window; }

};

