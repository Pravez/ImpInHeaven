#ifndef IMPINHEAVEN_MAP_HPP
#define IMPINHEAVEN_MAP_HPP


#include "Vector.hpp"
#include "Tile.hpp"
#include "Monster.h"

#include <vector>
#define GRID_WIDTH 15
#define GRID_HEIGHT 15

class Map {
private:
    int width;
    int height;
    Tile** tiles;

    int toIndex(Vector2<int> position) const;

public:
    Map(int width, int height);
    Tile* getTile(Vector2<int> position) const;
	TYPE_TILE getType(int x, int y) const;
    int getWidth() const;
    void setWidth(int _width);
    int getHeight() const;
    void setHeight(int _height);

	bool isTrap(Vector2<int> position) const;
	bool isWall(Vector2<int> position) const;
};


#endif //IMPINHEAVEN_MAP_HPP
