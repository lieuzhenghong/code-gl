#include<SDL.h>
#include<cstdio>
#include<SDLWindowManager.h>

using namespace std;

SDL_Window *SDLWindowManager::window;

SDL_Renderer *SDLWindowManager::Init(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("Error initialising: %s\n", SDL_GetError());
		return nullptr;
	}
	window = SDL_CreateWindow(
		"Code GUI",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);
	if(!window){
		printf("Error creating window: %s\n", SDL_GetError());
		return nullptr;
	}
	return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void SDLWindowManager::Destroy(){
	SDL_DestroyWindow(window);
	SDL_Quit();
}
