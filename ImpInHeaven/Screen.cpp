#include "Screen.hpp"
#include "utils.h"
#include "SpriteService.h"

//TODO : remove ?
#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}


Screen::Screen(int width, int height) : width(width), height(height), middle(Vector2(GRID_WIDTH/2, GRID_HEIGHT/2)), map( new Map(GRID_WIDTH, GRID_HEIGHT)) {
	sdlWindow = SDL_CreateWindow("ImpInHeaven", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
		SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	pSurface = SDL_GetWindowSurface(sdlWindow);

	auto normalTile = SpriteService::addSprite("/images/new_tiles.bmp", "new_tiles", renderer);
	SpriteService::addSprite("/images/multi_imp.bmp", "multi_imp", renderer);

	SDL_QueryTexture(normalTile, nullptr, nullptr, &tileWidth, &tileHeight);

	tileWidth = 200; //make it little for the moment
	tileHeight = 75;
}

Vector2 Screen::positionToIsometric(int i, int j) const
{
	Vector2 pos;
	int x_mid = width / 2;
	int y_mid = height / 2;

	Vector2 cameraPosition = camera->getPosition();

	pos.x(x_mid - ((tileWidth / 2)*(j - cameraPosition.y())) -(tileWidth/2) + ((i- cameraPosition.x())*(tileWidth/2)));
	pos.y(y_mid + (i - cameraPosition.x()) *(tileHeight / 2) - (tileHeight / 2) + ((j - cameraPosition.y())*(tileHeight/2)));
	if (map->getWidth() % 2 == 1) {
		pos.minus_x(tileWidth / 4);
		pos.minus_y(tileHeight / 4);
	}
	if (map->getHeight() % 2 == 1) {
		pos.plus_x(tileWidth / 4);
		pos.minus_y(tileHeight / 4);
	}

	return pos;
}

void Screen::drawGrid() const
{
	SDL_Rect pos;

	SDL_RenderClear(renderer);
	for (int i = 0; i < map->getWidth(); ++i) {
		for (int j = 0; j < map->getHeight(); ++j) {

			[i, j, &pos](Vector2 position) { pos.x = position.x(); pos.y = position.y(); } (positionToIsometric(i, j));
			
			pos.y = (map->getTile(Vector2(i, j))->getType()) == WALL ? pos.y-25 : pos.y;

			pos.w = tileWidth;
			pos.h = (map->getTile(Vector2(i, j))->getType()) == WALL ? tileHeight+25 : tileHeight;

			SDL_Rect current_tile;
			current_tile.w = 80;
			current_tile.h =  (map->getTile(Vector2(i, j))->getType()) == WALL ? 150 : 125;
			current_tile.x = current_tile.w * static_cast<int>(map->getTile(Vector2(i, j))->getType());
			current_tile.y = (map->getTile(Vector2(i, j))->getType()) == WALL ? 0 : 25;
				
			SDL_RenderCopy(renderer, SpriteService::getSprite("new_tiles"), &current_tile, &pos);
		}
	}
}

void Screen::render() const
{
	SDL_RenderPresent(renderer);
}

SDL_Window * Screen::getWindow() const
{
	return sdlWindow;
}

void Screen::setCamera(Camera* camera)
{
	this->camera = camera;
}

Map * Screen::getMap() const
{
	return map;
}

Imp * Screen::getImp() const
{
	return map->getImp();
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