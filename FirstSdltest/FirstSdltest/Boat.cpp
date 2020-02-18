#include "Boat.h"

void Boat::processInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN && e.key.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_RIGHT) {
                position->x += SPEED;
                right = true;
            }
            if (e.key.keysym.sym == SDLK_LEFT) {
                position->x -= SPEED;
                right = false;
            }

        }
    }
}
void Boat::update(float delta) {
    
}

std::string Boat::get_sprite_id() {
    return sprite_id;
}