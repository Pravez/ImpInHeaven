#pragma once
#include <vector>
#include "Element.h"
#include "Imp.h"
#include "Bird.h"
#include <map>

class Scene
{
private:
	std::map<std::string, Imp*> players;
	std::map<std::string, Monster*> monsters;
	std::vector<DrawableElement	*> elements;

public:
	Scene();
	void addEntity(DrawableElement* element);
	Imp* addPlayer(Imp* player);
	Monster* addMonster(Monster* monster);
	Imp* getPlayerById(std::string identifier);
	Monster* getMonsterById(std::string identifier);
	std::vector<Imp*> getPlayers();
	std::vector<Monster*> getMonsters();
	void draw(Screen* screen);
};
