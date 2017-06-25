//
// Created by howl on 03/06/17.
//

#ifndef IMPINHEAVEN_TILE_HPP
#define IMPINHEAVEN_TILE_HPP

#include "Vector.hpp"

#define TILE_WIDTH 5
#define TILE_HEIGHT 5

enum TYPE_TILE { NORMAL, TRAP, WALL};

class Tile {
private:
    Vector2 position;
    Vector2 isoPosition;
	TYPE_TILE type;

public:
	Tile(Vector2 position, TYPE_TILE type) : position(position), isoPosition(Vector2::toIso(position)), type(NORMAL) {}
	bool isTrap() const;
	bool isWall() const;
    void setPosition(Vector2 position);
	TYPE_TILE getType() const;
	void setType(TYPE_TILE type);
    Vector2 setPosition() const;
    //Vector2 to2D(Vector2 point);
};

#endif //IMPINHEAVEN_TILE_HPP
