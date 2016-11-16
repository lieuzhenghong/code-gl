#include<SDL.h>
#include<cstdio>
#include<SDLWindowManager.h>
#include<TextField.h>
#include<Processor.h>
#include<Instruction.h>

using namespace std;

const int height = SDLWindowManager::SCREEN_HEIGHT;
const int width = SDLWindowManager::SCREEN_WIDTH;
const int rect_height = width/2;
const int rect_width = height/2;

const SDL_Point position{20, (height-rect_height)/2};

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
	SDL_Renderer *screenRenderer = SDLWindowManager::Init();
	if(!screenRenderer)
		return 1;
	bool running = true;
	int frame = 0;
	SDL_Event e;
	TextField code_box = TextField(rect_width, rect_height, position);
	while(running){
		while(SDL_PollEvent(&e)!=0){
			if(e.type == SDL_QUIT){
				running = false;
			}
			code_box.handleEvent(&e);
		}
		SDL_SetRenderDrawColor(screenRenderer, 0, 0, 0, 255);
		SDL_RenderClear(screenRenderer);

		code_box.render(screenRenderer);

		SDL_RenderPresent(screenRenderer);

		//frame++;
	}
	SDLWindowManager::Destroy();
	return 0;
}

