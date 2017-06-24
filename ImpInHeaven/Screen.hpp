#ifndef IMPINHEAVEN_SCREEN_HPP
#define IMPINHEAVEN_SCREEN_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstdio>

#include "Imp.h"

#define CHECK_INIT_SDL(func) if(func != 0){ fprintf(stderr, "Failed to init (%s)\n", SDL_GetError()); return -1;}

class Screen {
private :
	int _width;
	int _height;
	int _tile_width;
	int _tile_height;

	SDL_Window * _sdlWindow;
	SDL_Renderer* _renderer;
	SDL_Surface * _pSurface;
	SDL_Texture * _normal_tile;

	Imp* _imp;
	SDL_Texture * _imp_sprite;

	SDL_Rect position_to_isometric(int i, int j);

public :
	Screen(int width, int height);
	SDL_Window * getWindow();
	void addImp(int x, int y);
	void displayGrid();

};


#endif //IMPINHEAVEN_SCREEN_HPP
