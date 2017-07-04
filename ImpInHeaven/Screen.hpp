#ifndef IMPINHEAVEN_SCREEN_HPP
#define IMPINHEAVEN_SCREEN_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstdio>

#include "Map.hpp"
#include "Camera.h"

#define CHECK_INIT_SDL(func) if(func != 0){ fprintf(stderr, "Failed to init (%s)\n", SDL_GetError()); return -1;}

class Screen {
private :
	int width;
	int height;
	int tileWidth;
	int tileHeight;
	Vector2<int> middle;

	Map * map;

	SDL_Window * sdlWindow;
	SDL_Renderer* renderer;
	SDL_Surface * pSurface;

	Camera* camera;

public :
	Screen(int width, int height);

	Vector2<int> positionToIsometric(int i, int j) const;

	void drawGrid() const;
	void render() const;
	
	Vector2<int> getTileDimensions() const;
	Vector2<int> getScreenDimensions() const;
	SDL_Renderer* getRenderer() const;
	SDL_Window * getWindow() const;

	void setCamera(Camera* camera);
	void setMap(Map* map);
};


#endif //IMPINHEAVEN_SCREEN_HPP
