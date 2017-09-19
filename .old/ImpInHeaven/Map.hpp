#ifndef IMPINHEAVEN_MAP_HPP
#define IMPINHEAVEN_MAP_HPP


#include "Vector.hpp"
#include "Tile.hpp"
#include "Imp.h"
#include "Monster.h"

#include <vector>
class Map {
private:
    int width;
    int height;
    Tile** tiles;

	Imp* imp;
	std::vector<Monster*> monsters;
	unsigned int nb_monster_left;

    int toIndex(Vector2 position) const;

public:
    Map(int width, int height);
    Tile* getTile(Vector2 position) const;
	TYPE_TILE getType(int x, int y) const;
    int getWidth() const;
    void setWidth(int _width);
    int getHeight() const;
    void setHeight(int _height);

	Imp * getImp() const;
	void setImp(Imp* imp);

	void addMonster(Monster* monster);
	void updateMonsters();

	void moveUp() const;
	void moveDown();
	void moveRight();
	void moveLeft();

	/*void moveMonsterUp(std::string identifiant);
	void moveMonsterDown(std::string identifiant);*/
};


#endif //IMPINHEAVEN_MAP_HPP
