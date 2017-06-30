#pragma once
#include "Imp.h"
#include <map>
#include <vector>
#include "Entity.h"

class World
{
private:
	std::map<std::string, Imp*> imps;
	std::vector<Entity*> entities;

public:
	World();
	void addImp(std::string name, Imp* imp);
	void addEntity(Entity* entity);

	void update();
};
