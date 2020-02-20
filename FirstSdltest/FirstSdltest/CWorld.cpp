#include "CWorld.h"
#include "Diver.h"
#include "Boat.h"
#include <iostream>
CWorld::CWorld(SDL_Renderer* ren) {
	p_renderer = ren;
}

void CWorld::processInput() {
	SDL_Event e;
	Boat* boat = (Boat*)objects[0];
	Diver* diver = (Diver*)objects[1];
	while (SDL_PollEvent(&e) != 0) {
		if (e.key.keysym.sym == SDLK_a) {
			diver->velocity.x = -diver->SPEED;
		}
		if (e.key.keysym.sym == SDLK_d) {
			diver->velocity.x = diver->SPEED;
		}


		if (e.key.keysym.sym == SDLK_UP) {
			diver->position->x += boat->SPEED;
		}
		if (e.key.keysym.sym == SDLK_DOWN) {
			diver->position->x -= boat->SPEED;
		}

	}
}
void CWorld::update(float delta) {
	int len = objects.size();
	for (int i = 0; i < len; i++) {
		if (objects[i] != nullptr) {
			objects[i]->update(delta);
		}
	}
	
}
void CWorld::render() {
	SDL_RenderClear(p_renderer);
	int len = objects.size();
	for (int i = 0; i < len; i++) {
		if (objects[i] != nullptr) {
			objects[i]->draw(p_renderer);
		}
	}
	SDL_RenderPresent(p_renderer);

}

bool CWorld::loadworld() {
	TheTextureManager::Instance()->load("../res/boat.png", "boat", p_renderer);
	TheTextureManager::Instance()->load("../res/diver_sheet.png", "diver", p_renderer);
	return true;

}