#pragma once
#include <SDL.h>
#include <stdint.h>

using namespace std;

typedef uint8_t pixel;

class Screen
{
    public:
        static const uint8_t HEIGHT = 16; // Supports up to 256 x 256 squares
        static const uint8_t WIDTH = 32;

        // Constructor function
        Screen(const SDL_Point position);

        // Read the input coming in from the processor
        // and mutate own state
        void ReadWord(unsigned int word);

        // Render the screen and scale it up x times
        void Render(SDL_Renderer* renderer, const unsigned int scale);

    private:
        const SDL_Point position;
        bool is_reading;
        unsigned int register_count;
        pixel grid [HEIGHT * WIDTH] = {0};
};
