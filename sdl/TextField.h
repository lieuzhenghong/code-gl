#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>

using namespace std;

// Text field class
class TextField
{
    public:
        // Call the constructor function
        TextField(const int width, const int height, const SDL_Point position);

        // Handles mouse event
        void handleEvent(SDL_Event* e);

        string text;
        
        void renderTextLines();

        // Render the text field
        void render(SDL_Renderer* renderer, TTF_Font* font);

    private:
        const int width;
        const int height;
        const SDL_Point position;
        int status;
        vector<string> text_lines;
};