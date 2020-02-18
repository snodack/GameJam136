#include "CObject.h"


CObject::CObject() {
}

CObject::~CObject(){
	printf("Destructor");
	delete position;
}
void CObject::draw(SDL_Renderer* pRenderer)
{
	STextureManager::Instance()->draw(sprite_id, position->x, position->y, 64, 64, pRenderer, right?SDL_FLIP_HORIZONTAL: SDL_FLIP_NONE);
}

