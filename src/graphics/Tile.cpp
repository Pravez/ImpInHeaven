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

Vector2 Tile::to2D(Vector2 point) {
    Vector2 vec = Vector2(0, 0);
    vec.x((2 * point.y() + point.x()) / 2);
    vec.y((2 * point.y() + point.x()) / 2);
    return vec;
}



