#include<SDL.h>
#include<cstdio>
#include<SDLWindowManager.h>
#include<TextField.h>

using namespace std;

const int height = SDLWindowManager::SCREEN_HEIGHT;
const int width = SDLWindowManager::SCREEN_WIDTH;
const int rect_height = width/2;
const int rect_width = height/2;

const SDL_Point position{20, (height-rect_height)/2};

int main(int argc, char* args[]){
	printf("%i: %i\n", rect_height, rect_width);
	SDL_Renderer *screenRenderer = SDLWindowManager::Init();
	if(!screenRenderer)
		return 1;
	bool running = true;
	int frame = 0;
	SDL_Event e;
	TextField code_box = TextField(rect_width, rect_height, position);
	while(running){
		while(SDL_PollEvent(&e)!=0){
			if(e.type == SDL_QUIT){
				running = false;
			}
			code_box.handleEvent(&e);
		}
		SDL_SetRenderDrawColor(screenRenderer, 0, 0, 0, 255);
		SDL_RenderClear(screenRenderer);

		code_box.render(screenRenderer);

		SDL_RenderPresent(screenRenderer);

		//frame++;
	}
	SDLWindowManager::Destroy();
	return 0;
}

