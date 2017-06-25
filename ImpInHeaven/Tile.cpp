//
// Created by howl on 03/06/17.
//

#include "Tile.hpp"

void Tile::set_type(TYPE_TILE type) {
	_type = type;
}

TYPE_TILE Tile::get_type() {
	return _type;
}

bool Tile::isTrap() {
	return _type == TRAP;
}

bool Tile::isWall() {
    return _type == WALL;
}

void Tile::position(Vector2 position) {
    Tile::_position = position;
}

Vector2 Tile::position() {
    return Tile::_position;
}

