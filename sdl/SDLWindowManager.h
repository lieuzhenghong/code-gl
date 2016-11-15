#include<SDL.h>

class SDLWindowManager{
	public:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	static SDL_Renderer *Init();
	static void Destroy();

	private:
	static SDL_Window *window;
	SDLWindowManager();
};
