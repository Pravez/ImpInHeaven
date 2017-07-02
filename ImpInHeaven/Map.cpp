#include "Map.hpp"
#include <iostream>

Map::Map(int width, int height) {
	this->width = width;
	this->height = height;
	this->nb_monster_left = 0;
    tiles = new Tile*[width * height];
    for(int i = 0;i < this->width;++i){
        for(int j = 0;j < this->height;++j){
            tiles[toIndex(Vector2<int>(i, j))] = new Tile(Vector2<int>(i, j), NORMAL);
        }
    }

	int rdm;

	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			rdm = rand() % (8 + 0) + 0;
			if (rdm == 2) {
				tiles[i*width + j]->setType(TRAP);
			}
			if (rdm == 5) {
				tiles[i*width + j]->setType(WALL);
			}
		}
	}
	tiles[width / 2 * width + height / 2]->setType(NORMAL);
}

int Map::toIndex(Vector2<int> position) const
{
    return position.x() * width + position.y();
}

TYPE_TILE Map::getType(int x, int y) const
{
	return tiles[x*width + y]->getType();
}

Tile *Map::getTile(Vector2<int> position) const
{
    return tiles[toIndex(position)];
}

int Map::getWidth() const {
    return width;
}

void Map::setWidth(int _width) {
    Map::width = _width;
}

int Map::getHeight() const {
    return height;
}

void Map::setHeight(int _height) {
    Map::height = _height;
}

bool Map::isTrap(Vector2<int> position) const
{
	return getType(position.x(), position.y()) == TRAP;
}

bool Map::isWall(Vector2<int> position) const
{
	return getType(position.x(), position.y()) == WALL;
}

Imp * Map::getImp() const
{
	return imp;
}

void Map::setImp(Imp* imp)
{
	this->imp = imp;
}


void Map::addMonster(Monster* monster)
{
	this->nb_monster_left++;
	monsters.push_back(monster);
}

void Map::moveUp() const
{
	int x_imp = imp->getX();
	int y_imp = imp->getY();
	if (y_imp > 0 && getType(x_imp, y_imp - 1) != WALL)
	{
		imp->moveUp();
		if (getType(x_imp, y_imp - 1) == TRAP)
		{
			imp->setState(DEAD);
		}
	}

	imp->setDirection(NORTH);
}

void Map::moveDown() {
	int x_imp = imp->getX();
	int y_imp = imp->getY();
	if (y_imp < height-1 && getType(x_imp, y_imp + 1) != WALL)
	{
		imp->moveDown();
		if (getType(x_imp, y_imp + 1) == TRAP)
		{
			imp->setState(DEAD);
		}
	}
	imp->setDirection(SOUTH);
}

void Map::moveLeft() {
	int x_imp = imp->getX();
	int y_imp = imp->getY();
	if (x_imp > 0 && getType(x_imp - 1, y_imp) != WALL)
	{
		imp->moveLeft();
		if (getType(x_imp - 1, y_imp) == TRAP)
		{
			imp->setState(DEAD);
		}
	}
	imp->setDirection(WEST);
}

void Map::moveRight() {
	int x_imp = imp->getX();
	int y_imp = imp->getY();
	if (x_imp < width-1 && getType(x_imp + 1, y_imp) != WALL)
	{
		imp->moveRight();
		if (getType(x_imp + 1, y_imp) == TRAP)
		{
			imp->setState(DEAD);
		}
	}
	imp->setDirection(EAST);
}

/*void Map::moveMonsterUp(std::string identifiant)
{
	Monster * monster = NULL;
	for (unsigned int i = 0; i<this->nb_monster_left; ++i)
	{
		if (monsters[i]->getIdentifier() == identifiant)
			monster = monsters[i];
	}
	if (monster == NULL) { //TODO :ERROR : invalid identifier
	};

	int x_monster = monster->getX();
	int y_monster = monster->getY();
	if (y_monster > 0 && getType(x_monster, y_monster - 1) != WALL)
	{
		monster->moveUp();
		if (getType(x_monster, y_monster - 1) == TRAP)
		{
			monster->setState(DEAD);
		}
	}

	monster->setDirection(NORTH);
}

void Map::moveMonsterDown(std::string identifiant)
{
	Monster * monster = NULL;
	//TODO get Monster by id
	for (unsigned int i = 0; i<this->nb_monster_left; ++i)
	{
		if (monsters[i]->getIdentifier() == identifiant)
			monster = monsters[i];
	}
	if (monster == NULL) { //TODO :ERROR : invalid identifier
	};

		int x_monster = monster->getX();
		int y_monster = monster->getY();
		if (y_monster < height - 1 && getType(x_monster, y_monster + 1) != WALL)
		{
			monster->moveDown();
			if (getType(x_monster, y_monster + 1) == TRAP)
			{
				monster->setState(DEAD);
			}
		}
		monster->setDirection(SOUTH);
}*/

void Map::updateMonsters()
{

	for (unsigned int i = 0; i<this->nb_monster_left; ++i)
	{
		monsters[i]->doAction();// this);
	}
}