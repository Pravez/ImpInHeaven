#ifndef IMPINHEAVEN_MAP_HPP
#define IMPINHEAVEN_MAP_HPP


#include "Vector.hpp"
#include "Tile.hpp"
#include "Imp.h"

class Map {
private:
    int width;
    int height;
    Tile** tiles;

	Imp* imp; //TODO : put in map and have map in attribute
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
};


#endif //IMPINHEAVEN_MAP_HPP
