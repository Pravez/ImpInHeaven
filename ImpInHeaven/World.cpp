#include "World.h"

World::World()
{

}

void World::addImp(std::string name, Imp* imp)
{
	imps.insert(std::pair<std::string, Imp*>(name, imp));
	//entities.push_back(imp);
}

void World::addEntity(Entity* entity)
{
	entities.push_back(entity);
}

void World::update()
{
	for (auto entity : entities)
	{
		entity->update();
	}
}
