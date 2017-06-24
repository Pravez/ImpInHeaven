#include "Screen.hpp"

//TODO : remove ?
#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}


Screen::Screen(int width, int height) : _width(width), _height(height), _imp(NULL) {
	_sdlWindow = SDL_CreateWindow("ImpInHeaven", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height,
		SDL_WINDOW_SHOWN);
	_renderer = SDL_CreateRenderer(_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);

	_pSurface = SDL_GetWindowSurface(_sdlWindow);

	std::string path = "C:/Users/utilisateur1/Desktop/ImpInHeaven/ImpInHeaven/ImpInHeaven/images/tile2.bmp";
	_normal_tile = IMG_LoadTexture(_renderer, path.c_str());
	if (_normal_tile == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		//DBOUT("Wrong path : " << IMG_GetError());
	}

	path = "C:/Users/utilisateur1/Desktop/ImpInHeaven/ImpInHeaven/ImpInHeaven/images/imp.bmp";
	_imp_sprite = IMG_LoadTexture(_renderer, path.c_str());
	if (_imp_sprite == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		//DBOUT("Wrong path : " << IMG_GetError());
	}

	

	SDL_QueryTexture(_normal_tile, NULL, NULL, &_tile_width, &_tile_height);
}


SDL_Window * Screen::getWindow() {
	return _sdlWindow;
}

Imp * Screen::getImp() {
	return _imp;
}

void Screen::addImp(int x, int y) {
	_imp = new Imp(x, y);
}


SDL_Rect Screen::position_to_isometric(int i, int j) {
	SDL_Rect pos;
	int x_mid = _width / 2;
	int y_mid = _height / 2;

	pos.x = x_mid + (i*(_tile_width / 2)) - (_tile_width / 2) - ((_tile_width / 2)*j);
	pos.y = y_mid - (2 * _tile_height) + j*(_tile_height / 2) + i *(_tile_height / 2);
	if (GRID_WIDTH % 2 == 1) {
		pos.x -= (_tile_width / 4);
		pos.y -= (_tile_height / 4);
	}
	if (GRID_HEIGHT % 2 == 1) {
		pos.x += (_tile_width / 4);
		pos.y -= (_tile_height / 4);
	}

	return pos;
}

void Screen::displayGrid() {

	SDL_Rect pos;
	SDL_Rect mini;
	mini.h = 4;
	mini.w = 4;
	_tile_width = 200; //make it little for the moment
	_tile_height = 75;
	//_tile_width = 100; //for the moment, the tile has to be a square
	//_tile_height = 100;

	SDL_RenderClear(_renderer);
	for (int i = 0; i < GRID_WIDTH; ++i) {
		for (int j = 0; j <GRID_HEIGHT; ++j) {

			pos = position_to_isometric(i, j);
			pos.w = _tile_width;
			pos.h = _tile_height;
			mini.x = pos.x;
			mini.y = pos.y;

			//Y'a 2 méthodes pour faire afficher, le RenderCopy (avec un renderer)
			//et le FillRect (avec le updateWindowSurface), et j'ai l'impression que les deux ne peuvent pas cohabiter ...
			SDL_RenderCopy(_renderer, _normal_tile, NULL, &pos);
			SDL_FillRect(_pSurface, &mini, SDL_MapRGB(_pSurface->format, 255, 255, 0));
		}
	}

	if (_imp != NULL) {
		int _imp_width = 40; //for the moment, the tile has to be a square
		int _imp_height = 80;
		pos = position_to_isometric(_imp->getX(), _imp->getY());

		pos.x +=  _tile_width/2 - _imp_width/2;
		pos.y -= (_tile_height/2);
		pos.w = _imp_width;
		pos.h = _imp_height;
		mini.x = pos.x;
		mini.y = pos.y;

		SDL_RenderCopy(_renderer, _imp_sprite, NULL, &pos);
		SDL_FillRect(_pSurface, &mini, SDL_MapRGB(_pSurface->format, 255, 255, 0));
	}

	SDL_RenderPresent(_renderer);


}