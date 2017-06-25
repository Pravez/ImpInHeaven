//
// Created by howl on 03/06/17.
//

#include "Tile.hpp"

void Tile::setType(TYPE_TILE type) {
	this->type = type;
}

TYPE_TILE Tile::getType() const
{
	return type;
}

bool Tile::isTrap() const
{
	return type == TRAP;
}

bool Tile::isWall() const
{
    return type == WALL;
}

void Tile::setPosition(Vector2 position) {
    this->position = position;
}

Vector2 Tile::setPosition() const
{
    return position;
}

