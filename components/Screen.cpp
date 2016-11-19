#include <SDL.h>
#include <vector>
#include <Screen.h>
#include <iostream>

using namespace std;

Screen::Screen(const SDL_Point pos):
    position(pos)
{
};

void Screen::render(SDL_Renderer *renderer, const unsigned int scale)
{
    SDL_Rect rect 
    {
        position.x,
        position.y,
        HEIGHT * scale, 
        HEIGHT * scale
    };

    SDL_RenderFillRect(renderer, &rect);
    // Process for rendering:
    SDL_Texture * pixel_grid = SDL_CreateTexture(  
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STATIC,
        HEIGHT,
        HEIGHT
    );

    SDL_UpdateTexture(
        pixel_grid,
        NULL, 
        grid,
        HEIGHT
    );
    SDL_RenderCopy(renderer, pixel_grid, NULL, &rect);
    SDL_DestroyTexture(pixel_grid);
}

void Screen::readWord(unsigned int word)
{

}