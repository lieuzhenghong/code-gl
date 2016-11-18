#pragma once
#include <SDL.h>
#include <stdint.h>

using namespace std;

typedef uint8_t pixel;

class Screen
{
    public:
        // Constructor function
        Screen(const uint8_t height, const SDL_Point position);

        // Read the input coming in from the processor
        // and mutate own state
        void readWord(unsigned int word);

        // Render the screen and scale it up x times
        void render(SDL_Renderer* renderer, const unsigned int scale);

    private:
        const uint8_t height; // Supports up to 256 x 256 squares
        const SDL_Point position;
        pixel grid [Screen::height][Screen::height];
};