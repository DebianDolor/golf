#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"
#include "Base.h"

class Wall : public Entity
{
public:
    Wall(Coordinate position, SDL_Texture* texture);
};