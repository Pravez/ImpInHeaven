#ifndef IMPINHEAVEN_MAP_HPP
#define IMPINHEAVEN_MAP_HPP


#include "../tools/Vector.hpp"
#include "Tile.hpp"

class Map {
private:
    int _width;
    int _height;
    Tile** _tiles;

    Tile* getTile(Vector2 position);
    int toIndex(Vector2 position);

public:
    Map(int width, int height);

};


#endif //IMPINHEAVEN_MAP_HPP
