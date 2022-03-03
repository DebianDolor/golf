#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>

#include "Hole.h"
#include "Wall.h"
#include "Entity.h"

class Ball : public Entity
{
private:
    Coordinate velocity;
    Coordinate target;
    Coordinate launchedVelocity;
    Coordinate initialMousePos;

    float velocity1D;
    float launchedVelocity1D;
    float friction = 0.001;

    bool canMove = true;
    bool playedSwingFx = true;
    bool win = false;

    int index;
    int strokes = 0;
    int dirX = 1;
    int dirY = 1;

    std::vector<Entity> points;
    std::vector<Entity> powerBar;

public:
    Ball(Coordinate position, SDL_Texture* texture, SDL_Texture* pointTex, SDL_Texture* powerMTexFG, 
        SDL_Texture* powerMTexBG, int index);
    Coordinate& getVelocity()
    {
        return velocity;
    }
    Coordinate& getInitialMousePos()
    {
        return initialMousePos;
    }
    std::vector<Entity> getPoints()
    {
        return points;
    }
    std::vector<Entity> getPowerBar()
    {
        return powerBar;
    }
    int getStrokes()
    {
        return strokes;
    }
    bool isWin()
    {
        return win;
    }
    void setWin(bool win);

    void setInitialMousePos(float x, float y);

    void setVelocity(float x, float y);

    void setLaunchedVelocity(float x, float y);

    void update(double deltaTime, bool mouseDown, bool mousePressed, std::vector<Wall> walls, 
        std::vector<Hole> holes, Mix_Chunk* chargeSfx, Mix_Chunk* swingSfx, Mix_Chunk* holeSfx);
};