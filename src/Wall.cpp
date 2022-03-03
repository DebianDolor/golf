#include "Wall.h"
#include "Entity.h"
#include "Base.h"

#include <SDL.h>

Wall::Wall(Coordinate p_pos, SDL_Texture* p_tex):Entity(p_pos, p_tex) {}