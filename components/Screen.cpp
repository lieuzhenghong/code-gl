#include <SDL.h>
#include <vector>
#include <Screen.h>
#include <iostream>

using namespace std;

Screen::Screen(const SDL_Point pos):
    position(pos)
{
    memset(grid, 0, sizeof(grid));
};

void Screen::Render(SDL_Renderer *renderer, const unsigned int scale)
{
    SDL_Rect rect 
    {
        position.x,
        position.y,
        WIDTH * scale, 
        HEIGHT * scale
    };

    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    // Process for rendering:

    SDL_Texture * pixel_grid = SDL_CreateTexture(  
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STATIC,
        WIDTH,
        HEIGHT
    );

    uint32_t converted_grid[WIDTH * HEIGHT] = {0};
    // Convert 8 bit to 32-bit color
    // 8 bit format: 
    // Bit  7 6 5 4 3 2 1 0
    // Data R R R G G G B B

    for (unsigned int i = 0; i < sizeof(grid) / sizeof(grid[0]); i++)
    {
        // Handle red first: first 3 bytes
        // 8 values map to 256 values.
        // Each value times 32

            uint8_t red = (grid[i] >> 5) + 1;
            uint8_t grn = (grid[i] >> 2 & 7) + 1;
            uint8_t blu = (grid[i] & 3);

            // cout << +red << ":" << +grn << ":" << +blu << endl;

            // Convert all of them to 256 colors
            // For blue, there are only 2 bits, so the
            // max is 4 blue colors
            red = (red * 32) - 1;
            grn = (grn * 32) - 1;
            blu = (blu * 85);

            // cout << +red << ":" << +grn << ":" << +blu << endl;

            converted_grid[i] = red;
            converted_grid[i] = converted_grid[i] << 8; 
            // 00000000 00000000 RRRRRRRR 00000000

            converted_grid[i] += grn;
            converted_grid[i] = converted_grid[i] << 8; 
            // 00000000 RRRRRRRR GGGGGGGG 00000000

            converted_grid[i] += blu;
            converted_grid[i] = converted_grid[i] << 8;
            // RRRRRRRR GGGGGGGG BBBBBBBB 00000000

            converted_grid[i] += 255;
            // RRRRRRRR GGGGGGGG BBBBBBBB 11111111
        
    }

    SDL_UpdateTexture(
        pixel_grid,
        NULL,
        converted_grid,
        WIDTH * sizeof(uint32_t)
    );
    SDL_RenderCopy(renderer, pixel_grid, NULL, &rect);
    
    // Draw border
    SDL_RenderDrawRect(renderer, &rect);

    // Clean up
    SDL_DestroyTexture(pixel_grid);
}

void Screen::ReadWord(unsigned int word)
{
    // I evidently didn't think this through
    // Because there's no way to show a specific register
    
    const unsigned int NUM_REGISTERS = 16;
    const unsigned int REGISTER_SIZE = 32;

    if (!is_reading)
    {
        register_count = 0;
        is_reading = true;
    }
    // Each register is 32 bits and there are 16 registers
    // Each pixel is 8 bits and there are 32 pixels per line
    // One register per line
    // So, we are going to fill up each pixel completely;
    // either 00000000 or 11111111 (255)
    // If the nth bit of the register is 1, fill up the nth pixel
    // in the line. Easy!

    cout << "Register " << register_count << " : " << word << endl;
    for (unsigned int n = 0; n < REGISTER_SIZE; n++)
    {
        // If the nth bit of the register is a 1
        if (word & (1 << n))
        {
            grid[(register_count * 32) + n] = 255;
        }
        else
        {
            //cout << n << "th bit is 0" << endl;
            grid[(register_count * 32) + n] = 0;
        }
        //cout << "Grid square " << (register_count * 32) + n << " : " <<  +grid[(register_count *32) + n] << endl;
    }
    register_count++;
    
    //Finished reading--reset the flag
    if (register_count > NUM_REGISTERS - 1)
    {
        //cout << "triggering" << endl;
        is_reading = false;
    }
}