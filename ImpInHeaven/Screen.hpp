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
	SDL_Texture * normalTile;

	SDL_Texture * impSprite;

	SDL_Rect positionToIsometric(int i, int j) const;

public :
	Screen(int width, int height);
	SDL_Window * getWindow() const;
	void displayGrid();
	Imp * getImp() const;
	Map * getMap() const;

};


#endif //IMPINHEAVEN_SCREEN_HPP
