#pragma once
#include "SDL.h"
#include <SDL_image.h>
#include <string>
#include "STextureManager.h"
#include "Vector2D.h"
class CObject
{
public:
	CObject();
	virtual ~CObject();
	Vector2D* position = new Vector2D(0,0);
	static SDL_Surface* sprite;
	bool right = true;
	int z_index = 0;
	virtual void processInput() = 0;
	virtual void update(float delta = 0) = 0;
	void draw(SDL_Renderer* pRenderer);

	virtual std::string get_sprite_id() = 0;
protected:
	std::string sprite_id = "boat";
};

