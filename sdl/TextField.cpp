#include <SDL.h>
#include <TextField.h>
#include <SDLWindowManager.h>
#include <iostream>

using namespace std;

enum TextFieldStatus
{
    MOUSE_OUT = 0,
    MOUSE_OVER = 1,
    MOUSE_DOWN = 2,
    MOUSE_UP = 3,
    TOTAL = 4
};

TextField::TextField(const int width, const int height, const SDL_Point pos):
    width(width),
    height(height),
    position(pos),
    focus(false)
{   
};

void TextField::render(SDL_Renderer* screenRenderer){
    SDL_Rect rect {
                    TextField::position.x,
                    TextField::position.y,
                    TextField::width, 
                    TextField::height
                    };
    switch (TextField::status)
    {
        case MOUSE_OUT:
        SDL_SetRenderDrawColor(screenRenderer, 40, 40, 40, 255);
        break;

        case MOUSE_OVER:
        SDL_SetRenderDrawColor(screenRenderer, 80, 80, 80, 255);
        break;            
    }

    // If the textfield is in focus
    if (TextField::focus == true)
    {
        SDL_SetRenderDrawColor(screenRenderer, 120, 120, 120, 255);
    }
    //SDL_SetRenderDrawColor(screenRenderer, 40, 40, 40, 255);
    SDL_RenderFillRect(screenRenderer, &rect);
    SDL_SetRenderDrawColor(screenRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(screenRenderer, &rect);
};

void TextField::handleEvent( SDL_Event* e)
{
    // If mouse event happened
    if (e->type == SDL_MOUSEMOTION ||
        e->type == SDL_MOUSEBUTTONDOWN ||
        e->type == SDL_MOUSEBUTTONUP)
    {
        // Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );

        // Check if mouse is in button
        bool inside = true;

        // Mouse left of button
        if (x < TextField::position.x)
        {
            inside = false;
        }
        else if (x > TextField::position.x + TextField::width)
        {
            inside = false;
        }
        else if (y < TextField::position.y)
        {
            inside = false;
        }
        else if (y > TextField::position.y + TextField::height)
        {
            inside = false;
        }
        if (!inside)
        {
            TextField::status = MOUSE_OUT;
            // remove focus from the window
            TextField::focus = false;
        }
        // if mouse is inside the button
        else
        {
            //printf("Mouse is inside button! \n");
            switch(e->type)
            {
                case SDL_MOUSEMOTION:
                TextField::status = MOUSE_OVER;
                break;

                case SDL_MOUSEBUTTONDOWN:
                TextField::status = MOUSE_DOWN;
                cout << "mouse down" << endl;
                TextField::focus = true;
                SDL_StartTextInput();
                break;

                case SDL_MOUSEBUTTONUP:
                TextField::status = MOUSE_UP;
                cout << "mouse up" << endl;
                break;
            }
        }
    }

    // If a keyboard event happened and text input is started
    else if (e->type == SDL_TEXTINPUT || e->type == SDL_TEXTEDITING)
    {
        switch(e->type)
        {
            case SDL_TEXTINPUT:
            TextField::text += e->text.text;
            cout << TextField::text << endl;
            break;

            case SDL_TEXTEDITING:
            cout << "text editing called" << endl;
            composition = e->edit.text;
            cursor = e->edit.start;
            selection_len = e->edit.length;
            break;
        }
    }

    else if (e->type == SDL_KEYDOWN)
    {
        switch (e->key.keysym.sym)
        {
            case SDLK_BACKSPACE: 
            cout << "backspace, \\b pressed" << endl;
            TextField::text.pop_back();
            break;

            case SDLK_RETURN:
            cout << "return, \\r pressed" << endl;
            TextField::text += "\n";
            break;

            case SDLK_TAB:
            cout << "tab, \\t pressed" << endl;
            TextField::text += "\t";
            break;
        }
        //cout << TextField::text << endl;
    }
}