#include<SDL.h>
#include<cstdio>
#include<SDLWindowManager.h>
#include <iostream>

#include<TextField.h>
#include<Processor.h>
#include<Instruction.h>
#include <Screen.h>
#include <Parser.h>

using namespace std;

const int height = SDLWindowManager::SCREEN_HEIGHT;
const int width = SDLWindowManager::SCREEN_WIDTH;
const int rect_height = width/2;
const int rect_width = height/2;
TTF_Font* font = NULL;
const SDL_Point code_box_position{20, (height-rect_height)/2};
const uint8_t PIXEL_LED_SCALE = 10;
const SDL_Point pixel_led_position {
	300, 
	(height- (Screen::HEIGHT * PIXEL_LED_SCALE))/2
	};
TextField code_box = TextField(rect_width, rect_height, code_box_position);
Screen pixel_led = Screen(pixel_led_position);
SDL_Renderer *screenRenderer = SDLWindowManager::Init();
Processor pro = Processor();
bool processor_running = false;

void handleEvent(SDL_Event* e, TextField* code_box)
{
    // If a keyboard event happened and text input is started
    if (e->type == SDL_TEXTINPUT )
    {
        switch(e->type)
        {
            case SDL_TEXTINPUT:
            code_box->text += e->text.text;
            break;
        }
    }

    else if (e->type == SDL_KEYDOWN)
    {
        switch (e->key.keysym.sym)
        {
            case SDLK_BACKSPACE: 
            //cout << "backspace, \\b pressed" << endl;

            if (!code_box->text.empty())
            {
                code_box->text.pop_back();
            }
            break;

            case SDLK_RETURN:
           // cout << "return, \\r pressed" << endl;
            code_box->text += "\n";
            break;

            case SDLK_TAB:
            //cout << "tab, \\t pressed" << endl;
            code_box->text += "\t";
            break;

            case SDLK_RIGHT:
            Parser parser = Parser();
			pro.ConnectScreen(&pixel_led);
			pro.Reset();
			unsigned int i = 0;
			for (uint32_t word : parser.Parse(code_box->text))
			{
				cout << "Command: " << word << endl;
				pro.FlashMem(i, word);
				i++;
			}
			pro.FlashMem(i, Instruction::EncodeHalt());
			processor_running = true;
            break;
        }
    }
}

int main(int argc, char* args[]){
	/*
	Processor p = Processor();
	p.FlashMem(0, Instruction::EncodeMovI(0, 5));
	p.FlashMem(1, Instruction::EncodeMovI(1, 7));
	p.FlashMem(2, Instruction::EncodeMovI(2, 0));
	p.FlashMem(3, Instruction::EncodeMovI(3, 1));
	p.FlashMem(4, Instruction::EncodeJz(1, 8));
	p.FlashMem(5, Instruction::EncodeAdd(2, 2, 0));
	p.FlashMem(6, Instruction::EncodeSub(1, 1, 3));
	p.FlashMem(7, Instruction::EncodeJmp(3));
	p.FlashMem(8, Instruction::EncodePrint(2));
	p.FlashMem(9, Instruction::EncodeHalt());

	int cnt = 0;
	while(p.GetError() == Processor::ErrorCode::NO_ERROR){
		cnt++;
		p.RunCycle();
	}

	return 0;
	*/

	printf("%i: %i\n", rect_height, rect_width);
	if(!screenRenderer)
		return 1;
	bool running = true;
	SDL_Event e;

    if (TTF_Init() == -1)
    {
        cout << "Init TTF failed" << SDL_GetError() << endl;
        return 1;
    }
    font = TTF_OpenFont("bin/SourceCodePro-Medium.ttf", 14);
    if (font == nullptr)
    {
        cout << "Failed to load font: " << SDL_GetError() << endl;
		return 1;
    }
	else
	{
		cout << "Font: " << font << endl;
	}

	while(running){
		while(SDL_PollEvent(&e)!=0){
			if(e.type == SDL_QUIT){
				running = false;
			}
			handleEvent(&e, &code_box);
		}
		SDL_SetRenderDrawColor(screenRenderer, 0, 0, 0, 255);
		SDL_RenderClear(screenRenderer);

		code_box.render(screenRenderer, font);
		pixel_led.Render(screenRenderer, PIXEL_LED_SCALE);

		unsigned int cnt = 0;
		if (pro.GetError() == Processor::ErrorCode::NO_ERROR && 
			processor_running
			)
		{
			cnt++;
			pro.RunCycle();
		}
		if (pixel_led.ReadyToDraw())
		{
			SDL_RenderPresent(screenRenderer);
		}
	}
	SDLWindowManager::Destroy();
	return 0;
};
