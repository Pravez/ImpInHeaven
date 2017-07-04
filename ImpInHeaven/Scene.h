#pragma once
#include <vector>
#include "Element.h"
#include <map>

class Scene
{
private:
	std::map<std::string, Monster*> monsters;
	std::vector<DrawableElement	*> elements;

public:
	Scene();
	void addEntity(DrawableElement* element);
	Monster* addMonster(Monster* monster);
	Monster* getMonsterById(std::string identifier);
	std::vector<Monster*> getMonsters();
	void draw(Screen* screen);
};
