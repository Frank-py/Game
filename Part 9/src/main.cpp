#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
SDL_DisplayMode DM;


int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
	SDL_GetCurrentDisplayMode(0, &DM);
	RenderWindow window("AAAA", DM.w, DM.h);

	SDL_Texture* ball = window.loadTexture("res/gfx/ball.png");
	SDL_Texture* balken = window.loadTexture("res/gfx/balken.png");

    // Entity entities[4] = {Entity(0, 0, grassTexture),
    //                       Entity(30, 0, grassTexture),
    //                       Entity(30, 30, grassTexture),
    //                       Entity(30, 60, grassTexture)};
	std::cout << DM.w << DM.h;
    std::vector<Entity> entitiees = {Entity(Vector2f(DM.w/2-128, DM.h/2-128), ball, false),
    								Entity(Vector2f(50, DM.h/2-128), balken, true),
    								Entity(Vector2f(DM.w-82, DM.h/2-128), balken, true)};
    // {
	//     Entity wilson(Vector2f(100, 50), grassTexture);

	//     entitiees.push_back(wilson);
	    
	// }



	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		// Get our controls and events
		if (entitiees[0].moveBall(DM, entitiees[1], entitiees[2]) == 1){
			gameRunning = false;
		}
		const Uint8 *keystate = SDL_GetKeyboardState(NULL);
		if (keystate[SDL_SCANCODE_W]){
			entitiees[1].moveBalken(0, DM);
		}
		if (keystate[SDL_SCANCODE_S]){
			entitiees[1].moveBalken(1, DM);
		}
		if (keystate[SDL_SCANCODE_UP]){
			entitiees[2].moveBalken(0, DM);
		}
		if (keystate[SDL_SCANCODE_DOWN]){
			entitiees[2].moveBalken(1, DM);
		}
		while (SDL_PollEvent(&event))
		{
			switch (event.type) {
				case SDL_QUIT:
            		gameRunning = false;
            		break;
				case SDL_KEYDOWN:
    				switch (event.key.keysym.sym)
    					{
        				case SDLK_f:  window.ToggleFullscreen(); break;
        				case SDLK_q: gameRunning = false; break;
        				// case SDLK_UP:    y--; break;
        				// case SDLK_DOWN:  y++; break;
    }
    break;
		}
			}
			

		window.clear();
		

		for (Entity& e : entitiees)
		{ 
			window.render(e);
		}


		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}