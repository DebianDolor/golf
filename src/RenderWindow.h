#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "Entity.h"

class RenderWindow
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	RenderWindow(const char* title, int width, int height);

	SDL_Texture* loadTexture(const char* filePath);
	
	void cleanUp();
	
	void clear();
	
	void render(Entity& e);
	
	void render(int x, int y, SDL_Texture* tex);
	
	void render(float x, float y, const char* text, TTF_Font* font, SDL_Color textColor);
	
	void renderCenter(float x, float y, const char* text, TTF_Font* font, SDL_Color textColor);
	
	void display();
};