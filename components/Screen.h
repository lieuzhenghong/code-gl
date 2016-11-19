#pragma once
#include <SDL.h>
#include <stdint.h>

using namespace std;

typedef uint8_t pixel;

class Screen
{
    public:
        static const uint8_t HEIGHT = 32; // Supports up to 256 x 256 squares

        // Constructor function
        Screen(const SDL_Point position);

        // Read the input coming in from the processor
        // and mutate own state
        void ReadWord(unsigned int word);

        // Render the screen and scale it up x times
        void Render(SDL_Renderer* renderer, const unsigned int scale);

    private:
        const SDL_Point position;
        pixel grid [Screen::HEIGHT * Screen::HEIGHT];
};
