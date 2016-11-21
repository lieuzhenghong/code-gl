#pragma once
#include <SDL.h>
#include <stdint.h>

using namespace std;

typedef uint8_t pixel;

class Screen
{
    public:
        const uint8_t height; // Supports up to 256 x 256 squares
        const uint8_t width;

        // Constructor function
        Screen(const SDL_Point position, const uint8_t height, const uint8_t width);

        // Destructor function
        ~Screen();
        
        // Read the input coming in from the processor
        // and mutate own state
        void ReadWord(unsigned int word);

        void ReadWordRAM(unsigned int word);

        // Render the screen and scale it up x times
        void Render(SDL_Renderer* renderer, const unsigned int scale);

        // Public function to check if the screen is ready to draw
        bool ReadyToDraw();

    private:
        const SDL_Point position;
        bool is_reading;
        bool ready_to_display = true;
        unsigned int register_count;
        pixel* grid; 
};
