#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Base.h"

class Entity
{
private:
	Coordinate pos;
	Coordinate scale = Coordinate(1, 1);
	
	float angle = 0;

	SDL_Rect currentFrame;
	SDL_Texture* tex;

public:
	Entity(Coordinate position, SDL_Texture* texture);

	Coordinate& getPos()
	{
		return pos;
	}
	float getAngle()
	{
		return angle;
	}
	Coordinate getScale()
	{
		return scale;
	}
	void setPos(float x, float y);

	void setScale(float w, float h);

	void setAngle(float angle);

	SDL_Texture* getTex();

	void update(double deltaTime);

	SDL_Rect getCurrentFrame();
};