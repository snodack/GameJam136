#pragma once
#include "CObject.h"
class Boat : public CObject
{
	const float SPEED= 2;
	virtual void processInput();
	virtual void update(float delta = 0.F);
	virtual  std::string get_sprite_id();
};

