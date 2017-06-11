//
// Created by howl on 03/06/17.
//

#include "Tile.hpp"

bool Tile::isWall() {
    return Tile::_wall;
}

void Tile::position(Vector2 position) {
    Tile::_position = position;
}

Vector2 Tile::position() {
    return Tile::_position;
}


