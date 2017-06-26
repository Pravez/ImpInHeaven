#include "Screen.hpp"
#include "utils.h"

//TODO : remove ?
#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

Screen::Screen(int width, int height) : width(width), height(height), map( new Map(GRID_WIDTH, GRID_HEIGHT)), middle(Vector2(GRID_WIDTH/2, GRID_HEIGHT/2)) {
	sdlWindow = SDL_CreateWindow("ImpInHeaven", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
		SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	pSurface = SDL_GetWindowSurface(sdlWindow);

	std::string path = std::string(WORKINGDIR_PATH) + "/images/new_tiles.bmp";
	normalTile = IMG_LoadTexture(renderer, path.c_str());
	if (normalTile == nullptr) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		//DBOUT("Wrong path : " << IMG_GetError());
	}

	path = std::string(WORKINGDIR_PATH) + "/images/imps.bmp";
	impSprite = IMG_LoadTexture(renderer, path.c_str());
	if (impSprite == nullptr) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}	

	SDL_QueryTexture(normalTile, nullptr, nullptr, &tileWidth, &tileHeight);
}

SDL_Window * Screen::getWindow() const
{
	return sdlWindow;
}

Map * Screen::getMap() const
{
	return map;
}

Imp * Screen::getImp() const
{
	return map->getImp();
}

SDL_Rect Screen::positionToIsometric(int i, int j) const
{
	SDL_Rect pos;
	int x_mid = width / 2;
	int y_mid = height / 2;

	pos.x = x_mid - ((tileWidth / 2)*(j - middle.y())) -(tileWidth/2) + ((i-middle.x())*(tileWidth/2));
	pos.y = y_mid + (i - middle.x()) *(tileHeight / 2) - (tileHeight / 2) + ((j - middle.y())*(tileHeight/2));
	if (map->getWidth() % 2 == 1) {
		pos.x -= (tileWidth / 4);
		pos.y -= (tileHeight / 4);
	}
	if (map->getHeight() % 2 == 1) {
		pos.x += (tileWidth / 4);
		pos.y -= (tileHeight / 4);
	}

	return pos;
}

void Screen::displayGrid() {

	SDL_Rect pos;
	tileWidth = 200; //make it little for the moment
	tileHeight = 80;

	int margin = 1; //TODO : change location of this
	int x_imp= map->getImp()->getX(), y_imp= map->getImp()->getY();
	if (x_imp > 0 + margin && x_imp < map->getWidth() - margin - 1) {
		middle.x(x_imp);
	}
	if (y_imp > 0 + margin && y_imp < map->getHeight() - margin - 1) {
		middle.y(y_imp);
	}

	SDL_RenderClear(renderer);
	for (int i = 0; i < map->getWidth(); ++i) {
		for (int j = 0; j < map->getHeight(); ++j) {

			pos = positionToIsometric(i, j);
			
			pos.y = (map->getTile(Vector2(i, j))->getType()) == WALL ? pos.y-25 : pos.y;

			pos.w = tileWidth;
			pos.h = (map->getTile(Vector2(i, j))->getType()) == WALL ? tileHeight+25 : tileHeight;

			SDL_Rect current_tile;
			current_tile.w = 80;
			current_tile.h =  (map->getTile(Vector2(i, j))->getType()) == WALL ? 150 : 125;
			current_tile.x = current_tile.w * static_cast<int>(map->getTile(Vector2(i, j))->getType());
			current_tile.y = (map->getTile(Vector2(i, j))->getType()) == WALL ? 0 : 25;
				
			//Y'a 2 méthodes pour faire afficher, le RenderCopy (avec un renderer) et le FillRect (avec le updateWindowSurface), et j'ai l'impression que les deux ne peuvent pas cohabiter ...
			SDL_RenderCopy(renderer, normalTile, &current_tile, &pos);
		}
	}

	Imp * imp = getImp();
	if (imp != nullptr) {
		int _imp_width = 50; //for the moment, the tile has to be a square
		int _imp_height = 80;
		pos = positionToIsometric(imp->getX(), imp->getY());
		imp->getDirection();

		pos.x +=  tileWidth/2 - _imp_width/2;
		pos.y -= (tileHeight/2);

		pos.w = _imp_width;
		pos.h = _imp_height;

		SDL_Rect current_imp;
		current_imp.w = 85;
		current_imp.h = 132;
		current_imp.x = current_imp.w * static_cast<int>(imp->getDirection());
		current_imp.y = 0;

		SDL_RenderCopy(renderer, impSprite, &current_imp, &pos);
		//SDL_FillRect(pSurface, &mini, SDL_MapRGB(pSurface->format, 255, 255, 0));
	}
	SDL_RenderPresent(renderer);
}