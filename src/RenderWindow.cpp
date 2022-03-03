#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#include "RenderWindow.h"
#include "Entity.h"

RenderWindow::RenderWindow(const char* title, int width, int height)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (window == NULL)
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& e)
{
	SDL_Rect src;
	src.x = e.getCurrentFrame().x;
	src.y = e.getCurrentFrame().y;
	src.w = e.getCurrentFrame().w;
	src.h = e.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = e.getPos().x + (e.getCurrentFrame().w - e.getCurrentFrame().w * e.getScale().x) / 2;
	dst.y = e.getPos().y + (e.getCurrentFrame().h - e.getCurrentFrame().h * e.getScale().y) / 2;
	dst.w = e.getCurrentFrame().w * e.getScale().x;
	dst.h = e.getCurrentFrame().h * e.getScale().y;

	SDL_RenderCopyEx(renderer, e.getTex(), &src, &dst, e.getAngle(), 0, SDL_FLIP_NONE);
}

void RenderWindow::render(int x, int y, SDL_Texture* tex)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w;
	src.h;

	SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, tex, &src, &dst);
}

void RenderWindow::render(float x0, float y0, const char* text, TTF_Font* font, SDL_Color textColor)
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, text, textColor);
	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = surfaceMessage->w;
	src.h = surfaceMessage->h;

	SDL_Rect dst;
	dst.x = x0;
	dst.y = y0;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, message, &src, &dst);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(message);
}

void RenderWindow::renderCenter(float x0, float y0, const char* text, TTF_Font* font, SDL_Color textColor)
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, text, textColor);
	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = surfaceMessage->w;
	src.h = surfaceMessage->h;

	SDL_Rect dst;
	dst.x = 640 / 2 - src.w / 2 + x0;
	dst.y = 480 / 2 - src.h / 2 + y0;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, message, &src, &dst);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(message);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}
