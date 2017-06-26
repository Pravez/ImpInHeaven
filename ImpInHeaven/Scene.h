#pragma once
#include <vector>
#include "Element.h"
#include "Imp.h"
#include <map>

class Scene
{
private:
	std::map<std::string, Imp*> players;
	std::vector<DrawableElement	*> elements;

public:
	Scene();
	void addEntity(DrawableElement* element);
	Imp* addPlayer(Imp* player);
	Imp* getPlayerById(std::string identifier);
	std::vector<Imp*> getPlayers();
	void draw(Screen* screen);
};
