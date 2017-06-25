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
    Vector2 _position;
    Vector2 _isoPosition;
	TYPE_TILE _type;

public:
	Tile(Vector2 position, TYPE_TILE type) : _position(position), _type(NORMAL), _isoPosition(Vector2::toIso(position)) {}
	bool isTrap();
	bool isWall();
    void position(Vector2 position);
	TYPE_TILE get_type();
	void set_type(TYPE_TILE type);
    Vector2 position();
    //Vector2 to2D(Vector2 point);
};

#endif //IMPINHEAVEN_TILE_HPP
