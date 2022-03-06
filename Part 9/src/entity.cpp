#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include <iostream>

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, bool form)
:pos(p_pos), tex(p_tex)
{
	if (form){
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 128;
	}
	else{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
		srand ( time(NULL) );
		randomy = rand() % 15 + (-7);
		int randombool = rand() % 2 + 1;
	if (randombool ==1 ){
		randomx = -(15-abs(randomy));
	}else{
		randomx = 15-abs(randomy);
		}


	}

}

SDL_Texture* Entity::getTex()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}
int Entity::moveBall(SDL_DisplayMode DM, Entity balken1, Entity balken2){


	if (pos.y <= 0 || pos.y >= DM.h-92){
		pos.x += randomx;
		randomy = randomy*-1;
		pos.y += randomy;
		return 0;
	}
	if (pos.x <= 0 || pos.x >= DM.w-32){
		return 1;
	}
	if ((abs(balken1.getPos().x-pos.x)<64 && abs(balken1.getPos().y-pos.y)<160)||(abs(balken2.getPos().x-pos.x)<64 && abs(balken2.getPos().y-pos.y)<160)){
		pos.y += randomy;
		randomx = randomx*-1;
		pos.x += randomx;
		return 0;
	}
	pos.x += randomx;
	pos.y += randomy;
	return 0;


}
void Entity::moveBalken(int dir, SDL_DisplayMode DM)
{
if (pos.y >= 0 && pos.y <= DM.h-192){
if (dir == 0){
	pos.y -= 10;
}
else if (dir == 1) {
	pos.y += 10;

}}
else{
	if(pos.y <= 0){
		pos.y += 5;
	}
	else{
		pos.y -= 5;
	}
}
}

