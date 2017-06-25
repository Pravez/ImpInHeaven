#include "Screen.hpp"
#include "utils.h"

//TODO : remove ?
#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

SDL_Texture* Screen::getImpSprite() const
{
	return impSprite;
}

Screen::Screen(int width, int height) : width(width), height(height), middle(Vector2(GRID_WIDTH/2, GRID_HEIGHT/2)), map( new Map(GRID_WIDTH, GRID_HEIGHT)) {
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

	path = std::string(WORKINGDIR_PATH) + "/images/multi_imp.bmp";
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

Vector2 Screen::getTileDimensions() const
{
	return Vector2(this->tileWidth, this->tileHeight);
}

Vector2 Screen::getScreenDimensions() const
{
	return Vector2(this->width, this->height);
}

SDL_Renderer* Screen::getRenderer() const
{
	return this->renderer;
}

void Screen::drawGrid() {

	SDL_Rect pos;
	tileWidth = 200; //make it little for the moment
	tileHeight = 75;

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
}

void Screen::update()
{
	SDL_RenderPresent(renderer);
}