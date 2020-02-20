#pragma once
#include "CObject.h"
enum states {
	in_place = 0,
	up = 1,
	down = 2,
	right = 3,
	left = 4,
};
class Diver :
	public CObject
{
public:
	states state = in_place;
	float SPEED = 2000;
	virtual void processInput();
	virtual std::string get_sprite_id();
	virtual void update(float delta = 0.F);
protected:
	virtual void down_velocity();
};

