#include "CWorld.h"

CWorld::CWorld(SDL_Renderer* ren) {
	p_renderer = ren;
}

void CWorld::processInput() {
	int len = objects.size();
	for (int i = 0; i < len; i++) {
		if (objects[i] != nullptr) {
			objects[i]->processInput();
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
	return true;

}