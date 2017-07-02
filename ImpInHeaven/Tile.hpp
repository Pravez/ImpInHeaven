#ifndef IMPINHEAVEN_TILE_HPP
#define IMPINHEAVEN_TILE_HPP

#include "Vector.hpp"

#define TILE_WIDTH 5
#define TILE_HEIGHT 5

enum TYPE_TILE { NORMAL, TRAP, WALL};

class Tile {
private:
    Vector2<int> position;
    Vector2<int> isoPosition;
	TYPE_TILE type;

public:
	Tile(Vector2<int> position, TYPE_TILE type) : position(position), isoPosition(Vector2<int>::toIso(position)), type(NORMAL) {}
	bool isTrap() const;
	bool isWall() const;
    void setPosition(Vector2<int> position);
	TYPE_TILE getType() const;
	void setType(TYPE_TILE type);
    Vector2<int> setPosition() const;
    //Vector2 to2D(Vector2 point);
};

#endif //IMPINHEAVEN_TILE_HPP
