#include <SDL.h>
#include <vector>

using namespace std;

Screen::Screen(const uint_8_t height, const SDL_Point position):
    height(height),
    position(pos),
    grid(NULL);
{
};

void Screen::render(SDL_Renderer *renderer, const unsigned int scale){
    
    // Process for rendering:
    SDL_Texture * pixel_grid = SDL_CreateTexture
    (   
        renderer,
        SDL_PIXELFORMAT_INDEX8,
        SDL_TEXTUREACCESS_STATIC,
        Screen::height * scale,
        Screen::height * scale
    );
    cout << SDL_BITSPERPIXEL(SDL_PIXELFORMAT_INDEX8) << endl;
    cout << SDL_BYTESPERPIXEL(SDL_PIXELFORMAT_INDEX8) << endl;
}

void Screen::readWord(unsigned int word)
{

}