#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"
#include "Base.h"

class Hole : public Entity
{
public:
    Hole(Coordinate position, SDL_Texture* texture);
};