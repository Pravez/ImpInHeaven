#include "Map.hpp"
#include <iostream>

Map::Map(int width, int height) {
	this->width = width;
	this->height = height;
    tiles = new Tile*[width * height];
    for(int i = 0;i < this->width;++i){
        for(int j = 0;j < this->height;++j){
            tiles[toIndex(Vector2<int>(i, j))] = new Tile(Vector2<int>(i, j), NORMAL);
        }
    }

	int rdm;

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			rdm = rand() % (8 + 0) + 0;
			if (rdm == 2) {
				tiles[i*width + j]->setType(TRAP);
			}
			if (rdm == 5) {
				tiles[i*width + j]->setType(WALL);
			}
		}
	}
	tiles[width / 2 * width + height / 2]->setType(NORMAL);
}

int Map::toIndex(Vector2<int> position) const
{
    return position.x() * width + position.y();
}

TYPE_TILE Map::getType(int x, int y) const
{
	return tiles[x*width + y]->getType();
}

Tile *Map::getTile(Vector2<int> position) const
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

bool Map::isTrap(Vector2<int> position) const
{
	return getType(position.x(), position.y()) == TRAP;
}

bool Map::isWall(Vector2<int> position) const
{
	return getType(position.x(), position.y()) == WALL;
}