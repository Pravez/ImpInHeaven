#include "Map.hpp"
#include <iostream>

Map::Map(int width, int height) {
    _width = width;
    _height = height;
    _tiles = new Tile*[width * height];
    for(int i = 0;i < width;++i){
        for(int j = 0;i < height;i++){
            _tiles[toIndex(Vector2(i, j))] = new Tile(Vector2(i, j), NORMAL);
        }
    }

	for (int i = 0; i < width; ++i) {
		for (int j = 0; i < height; i++) {
			_tiles[i*_width + j]->set_type(NORMAL);
			printf("DEBUG : ON cree tile (%d, %d) avec enum=%d", i, j, _tiles[i*_width + j]->get_type());
		}
	}
}

int Map::toIndex(Vector2 position) {
    return position.x() * _width + position.y();
}

TYPE_TILE Map::get_type(int x, int y) {
	return _tiles[x*_width + y]->get_type();
}

Tile *Map::get_tile(Vector2 position) {
    return _tiles[toIndex(position)];
}

int Map::get_width() const {
    return _width;
}

void Map::set_width(int _width) {
    Map::_width = _width;
}

int Map::get_height() const {
    return _height;
}

void Map::set_height(int _height) {
    Map::_height = _height;
}

Imp * Map::get_imp() {
	return _imp;
}

void Map::add_imp(int x, int y) {
	_imp = new Imp(x, y);
}