#pragma once
#include <string>
#include <SDL.h>


using namespace std;

// Text field class
class TextField
{
    public:
        // Call the constructor function
        TextField(const int width, const int height, const SDL_Point position);

        // Handles mouse event
        void handleEvent(SDL_Event* e);

        // Change the status of the text field 
        // (when moused over)
        int setStatus();

        // Render the text field
        void render(SDL_Renderer* renderer);

    private:
        const int width;
        const int height;
        const SDL_Point position;
        int status;
        bool focus;
        string text;
        string composition;
        Sint32 cursor;
        Sint32 selection_len;
};