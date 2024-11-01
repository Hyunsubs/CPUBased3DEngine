#pragma once
class GameEngine :
	public CSingleton<GameEngine>
{
	SINGLE(GameEngine)

private:

public:
	bool Init();
	void ProcessInput();
	void Update();
	void Render();

public:

private:
	void SDLEventCheck(SDL_Event& event);

public:

};

