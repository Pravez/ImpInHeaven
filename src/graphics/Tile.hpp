//
// Created by howl on 03/06/17.
//

#ifndef IMPINHEAVEN_TILE_HPP
#define IMPINHEAVEN_TILE_HPP


#include "../tools/Vector.hpp"

#define TILE_WIDTH 5
#define TILE_HEIGHT 5

class Tile {
private:
    Vector2 _position;
    Vector2 _isoPosition;
    bool _wall;

public:
    Tile(Vector2 position, bool wall) : _position(position), _wall(wall), _isoPosition(Vector2::toIso(position)) {}
    bool isWall();
    void position(Vector2 position);
    Vector2 position();
    Vector2 to2D(Vector2 point);
};


#endif //IMPINHEAVEN_TILE_HPP
