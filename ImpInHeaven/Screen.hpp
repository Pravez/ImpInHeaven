#ifndef IMPINHEAVEN_SCREEN_HPP
#define IMPINHEAVEN_SCREEN_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstdio>

#include "Map.hpp"

#define CHECK_INIT_SDL(func) if(func != 0){ fprintf(stderr, "Failed to init (%s)\n", SDL_GetError()); return -1;}

class Screen {
private :
	int width;
	int height;
	int tileWidth;
	int tileHeight;
	Vector2 middle;

	Map * map;

	SDL_Window * sdlWindow;
	SDL_Renderer* renderer;
	SDL_Surface * pSurface;

public :
	Screen(int width, int height);
	SDL_Window * getWindow() const;
	void drawGrid();
	Imp* getImp() const;
	Map* getMap() const;
	SDL_Rect positionToIsometric(int i, int j) const;
	Vector2 getTileDimensions() const;
	Vector2 getScreenDimensions() const;
	SDL_Renderer* getRenderer() const;

	void update();
};


#endif //IMPINHEAVEN_SCREEN_HPP
