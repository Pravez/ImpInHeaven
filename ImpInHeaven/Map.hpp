#ifndef IMPINHEAVEN_MAP_HPP
#define IMPINHEAVEN_MAP_HPP


#include "Vector.hpp"
#include "Tile.hpp"
#include "Imp.h"


#include <time.h> //TODO : remove when random will be not used anymore

class Map {
private:
    int width;
    int height;
    Tile** tiles;


	Imp* imp;
    int toIndex(Vector2 position) const;

public:
    Map(int width, int height);
    Tile* getTile(Vector2 position) const;
	TYPE_TILE getType(int x, int y) const;
    int getWidth() const;
    void setWidth(int _width);
    int getHeight() const;
    void setHeight(int _height);

	void addImp(int x, int y);
	Imp * getImp() const;

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};


#endif //IMPINHEAVEN_MAP_HPP
