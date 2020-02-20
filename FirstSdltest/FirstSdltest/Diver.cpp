#include "Diver.h"

void Diver::processInput() {

}
void Diver::update(float delta) {
    *position += velocity*delta;
    if (velocity.length() > 0) {
        down_velocity();
    }
}
std::string Diver::get_sprite_id() {
    return "diver";
}

void Diver::down_velocity() {
    if (velocity.x > 0 )velocity.x -= SPEED / 4;
    else if (velocity.x < 0) velocity.x += SPEED / 4;
    else if (velocity.y > 0)velocity.y -= SPEED / 4;
    else if (velocity.y < 0) velocity.y += SPEED / 4;
}