#include "SDL.h"
#include <iostream>
#include <ctime>

#include "CObject.h"
#include "Boat.h"
#include "CWorld.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
using namespace std;
void init(SDL_Renderer*);
/*void processInput();
void update();
void render();*/
SDL_Surface* load(string);

CWorld* current_world = nullptr;

SDL_Surface* Boat::sprite = IMG_Load("../res/boat.png");

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags)) {
		std::cout << "Can't init image: " << IMG_GetError() << std::endl;
	}
	SDL_Window* window = SDL_CreateWindow("Game Jam 136", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
	init(ren);

	
	Uint32 frameStart = 0, frameTime =0;
	while (current_world != nullptr) {
		frameTime = SDL_GetTicks() - frameStart;
		current_world->processInput();
		current_world->update(frameTime/100.f);
		current_world->render();
		frameStart = SDL_GetTicks();
		/*if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}*/
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

/*void processInput() {
}
void update() {
}
void render() {

}*/

SDL_Surface* load(string path) {
	return IMG_Load(path.c_str());
}

void init(SDL_Renderer* r){
	current_world = new CWorld(r);
	current_world->loadworld();
	current_world->objects.push_back(new Boat());
}