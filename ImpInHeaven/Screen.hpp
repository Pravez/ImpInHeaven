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
	int _width;
	int _height;
	int _tile_width;
	int _tile_height;

	Map * _map;

	SDL_Window * _sdlWindow;
	SDL_Renderer* _renderer;
	SDL_Surface * _pSurface;
	SDL_Texture * _normal_tile;

	SDL_Texture * _imp_sprite;

	SDL_Rect position_to_isometric(int i, int j);

public :
	Screen(int width, int height);
	SDL_Window * get_window();
	void display_grid();
	Imp * get_imp();
	Map * get_map();

};


#endif //IMPINHEAVEN_SCREEN_HPP
