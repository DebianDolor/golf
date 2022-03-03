#include "Entity.h"
#include "Base.h"
#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(Coordinate position, SDL_Texture* texture):pos(position), tex(texture)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
	SDL_QueryTexture(texture, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

SDL_Texture* Entity::getTex()
{
	return tex;
}

void Entity::update(double deltaTime) {}

void Entity::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Entity::setAngle(float angle)
{
	this->angle = angle;
}

void Entity::setScale(float w, float h)
{
	scale.x = w;
	scale.y = h;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}
