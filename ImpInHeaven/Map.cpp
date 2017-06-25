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

	srand(time(NULL));
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
	imp = new Imp(x, y);
}


void Map::moveUp() {
	int x_imp = imp->getX();
	int y_imp = imp->getY();
	TYPE_TILE type = getType(x_imp, y_imp - 1);
	if (y_imp > 0 &&  type != WALL)
	{
		imp->moveUp();
		if (type == TRAP)
		{
			imp->setState(DEAD);
		}
	}

	imp->setDirection(NORTH);
}

void Map::moveDown() {
	int x_imp = imp->getX();
	int y_imp = imp->getY();
	TYPE_TILE type = getType(x_imp, y_imp + 1);
	if (y_imp < height-1 &&  type != WALL)
	{
		imp->moveDown();
		if (type == TRAP)
		{
			imp->setState(DEAD);
		}
	}
	imp->setDirection(SOUTH);
}

void Map::moveLeft() {
	int x_imp = imp->getX();
	int y_imp = imp->getY();
	TYPE_TILE type = getType(x_imp - 1, y_imp);
	if (x_imp > 0 && type != WALL)
	{
		imp->moveLeft();
		if (type == TRAP)
		{
			imp->setState(DEAD);
		}
	}
	imp->setDirection(WEST);
}

void Map::moveRight() {
	int x_imp = imp->getX();
	int y_imp = imp->getY();
	TYPE_TILE type = getType(x_imp + 1, y_imp);
	if (y_imp < width-1 && type != WALL)
	{
		imp->moveRight();
		if (type == TRAP)
		{
			imp->setState(DEAD);
		}
	}
	imp->setDirection(EAST);
}