#pragma once
class GameEngine :
	public CSingleton<GameEngine>
{
	SINGLE(GameEngine)

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	bool Init();
	void ProcessInput();
	void Update();
	void Render();


	SDL_Window* GetSDLWindow() { return window; }

};

