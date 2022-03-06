#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Math.hpp>

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex, bool form);
	Vector2f& getPos()
	{
		return pos;
	}
	SDL_Texture* getTex();
	void moveBalken(int dir, SDL_DisplayMode DM);
	int moveBall(SDL_DisplayMode DM, Entity balken1, Entity balken2);
	SDL_Rect getCurrentFrame();
private:
	Vector2f pos;
	
	bool form;
	int randomx;
	int randomy;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};