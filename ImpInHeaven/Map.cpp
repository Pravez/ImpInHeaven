#include "Map.hpp"
#include <iostream>

Map::Map(int width, int height) {
	this->width = width;
	this->height = height;
    tiles = new Tile*[width * height];
    for(int i = 0;i < this->width;++i){
        for(int j = 0;j < this->height;++j){
            tiles[toIndex(Vector2(i, j))] = new Tile(Vector2(i, j), NORMAL);
        }
    }

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			tiles[i*width + j]->setType(NORMAL);
			printf("DEBUG : ON cree tile (%d, %d) avec enum=%d", i, j, tiles[i*width + j]->getType());
		}
	}
}

int Map::toIndex(Vector2 position) const
{
    return position.x() * width + position.y();
}

TYPE_TILE Map::getType(int x, int y) const
{
	return tiles[x*width + y]->getType();
}

Tile *Map::getTile(Vector2 position) const
{
    return tiles[toIndex(position)];
}

int Map::getWidth() const {
    return width;
}

void Map::setWidth(int _width) {
    Map::width = _width;
}

int Map::getHeight() const {
    return height;
}

void Map::setHeight(int _height) {
    Map::height = _height;
}

Imp * Map::getImp() const
{
	return imp;
}

void Map::addImp(int x, int y) {
	imp = new Imp(Vector2(x, y));
}