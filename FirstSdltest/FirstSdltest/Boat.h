#pragma once
#include "CObject.h"
class Boat : public CObject
{
public:
	float SPEED = 200;
	virtual void processInput();
	virtual void update(float delta = 0.F);
	virtual std::string get_sprite_id();
protected:
	virtual void down_velocity();
};

