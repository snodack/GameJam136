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
	float SPEED = 2;
	Vector2D* position = new Vector2D(0,0);
	Vector2D velocity = { 0,0 };
	static SDL_Surface* sprite;
	bool right = true;
	int z_index = 0;
	virtual void processInput() = 0;
	virtual void update(float delta = 0) = 0;
	virtual void draw(SDL_Renderer* pRenderer);


	virtual std::string get_sprite_id() = 0;
protected:
	virtual void down_velocity() = 0;
};

