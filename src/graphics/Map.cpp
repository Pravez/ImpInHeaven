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
