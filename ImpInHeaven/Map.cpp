#include "Map.hpp"

Map::Map(int width, int height) {
    _width = width;
    _height = height;
    _tiles = new Tile*[width * height];
    for(int i = 0;i < width;++i){
        for(int j = 0;i < height;i++){
            _tiles[toIndex(Vector2(i, j))] = new Tile(Vector2(i, j), false);
        }
    }
}

int Map::toIndex(Vector2 position) {
    return position.x() * _width + position.y();
}

Tile *Map::getTile(Vector2 position) {
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