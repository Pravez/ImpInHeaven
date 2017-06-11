#ifndef IMPINHEAVEN_MAP_HPP
#define IMPINHEAVEN_MAP_HPP


#include "Vector.hpp"
#include "Tile.hpp"

class Map {
private:
    int _width;
    int _height;
    Tile** _tiles;

    int toIndex(Vector2 position);

public:
    Map(int width, int height);
    Tile* getTile(Vector2 position);
    int get_width() const;
    void set_width(int _width);
    int get_height() const;
    void set_height(int _height);
};


#endif //IMPINHEAVEN_MAP_HPP
