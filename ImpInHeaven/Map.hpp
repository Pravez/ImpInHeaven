#ifndef IMPINHEAVEN_MAP_HPP
#define IMPINHEAVEN_MAP_HPP


#include "Vector.hpp"
#include "Tile.hpp"
#include "Imp.h"

class Map {
private:
    int _width;
    int _height;
    Tile** _tiles;

	Imp* _imp; //TODO : put in map and have map in attribute
    int toIndex(Vector2 position);

public:
    Map(int width, int height);
    Tile* get_tile(Vector2 position);
	TYPE_TILE get_type(int x, int y);
    int get_width() const;
    void set_width(int _width);
    int get_height() const;
    void set_height(int _height);

	void add_imp(int x, int y);
	Imp * get_imp();
};


#endif //IMPINHEAVEN_MAP_HPP
