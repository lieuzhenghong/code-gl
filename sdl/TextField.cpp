#include <SDL.h>
#include <TextField.h>
#include <SDLWindowManager.h>
#include <SDL_ttf.h>
#include <iostream>
#include <Parser.h>
#include <Screen.h>
#include <vector>
#include <Processor.h>

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
    text(""),
    width(width),
    height(height),
    position(pos),
    text_lines(1)
{
};

void TextField::render(SDL_Renderer* screenRenderer, TTF_Font* font)
{
    SDL_Rect rect 
    {
        position.x,
        position.y,
        width, 
        height
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

    SDL_RenderFillRect(screenRenderer, &rect);
    SDL_SetRenderDrawColor(screenRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(screenRenderer, &rect);

    // Render the text
    SDL_Color textColor = {255, 255, 255, 0};

    // Generate the text lines first
    TextField::renderTextLines();

    // For every text line, render it
    
    unsigned int line_count = 0;
    for (vector<string>::size_type i = 0; i < (TextField::text_lines.size()); i++)
    {

        // First, check if the line I am rendering is nothing.
        // If not, skip the rendering

        if (!TextField::text_lines[i].empty())
        {
            SDL_Surface* textSurface = TTF_RenderText_Solid
            (
                font, 
                TextField::text_lines[i].c_str(), 
                textColor
            );
            SDL_Texture* text = SDL_CreateTextureFromSurface
            (
                screenRenderer, 
                textSurface
            );
            int text_width = textSurface->w;
            int text_height = textSurface->h;
            SDL_FreeSurface(textSurface);

            SDL_Rect textQuad
            {
                int(TextField::position.x + 5),
                int(TextField::position.y + line_count * 16),
                text_width,
                text_height
            };
            SDL_RenderCopy(screenRenderer, text, NULL, &textQuad);
            SDL_DestroyTexture(text);
            line_count++;
        }
    }

};

void TextField::renderTextLines()
{
    //cout << "Function called!" << endl;
    // Clear all text lines
    TextField::text_lines.clear();

    TextField::text_lines.push_back(string());
    uint line_count = 0;
    
    // Prepend the line count
    if (line_count < 9)
    {
        TextField::text_lines[line_count] += " " + to_string(line_count+1) + " ";
    }
    else
    {
        TextField::text_lines[line_count] += to_string(line_count+1) + " ";
    }

    // Until we hit the end of the C++ string, read char by char
    for (uint i = 0; TextField::text[i] != '\0'; i++)
    {
        char c = TextField::text[i];

        // Once we hit a newline,
        if (c == '\n')
        {
            // Go to the next line
            line_count++;
            
            // Add a new string to vector
            TextField::text_lines.push_back(string());

            // Add line number
            if (line_count < 9)
            {
                TextField::text_lines[line_count] += " " + to_string(line_count+1) + " ";
            }
            else
            {
                TextField::text_lines[line_count] += to_string(line_count+1) + " ";
            }
        }

        else if (c == '\t')
        // If it's a tab character, put two spaces instead
        {
            TextField::text_lines[line_count] += "  ";
        }
        
        // Append the character to the correct text_line
        // only if it is NOT a newline or tab character
        else
        {
            TextField::text_lines[line_count] += c;
        }
    }
};

