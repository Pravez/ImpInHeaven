#include "Scene.h"
#include "utils.h"
#include <algorithm>
#include <iterator>

Scene::Scene()
{
}

void Scene::addEntity(DrawableElement* element)
{
	elements.push_back(element);
}
Monster* Scene::addMonster(Monster* monster)
{
	monsters.insert(std::pair<std::string, Monster*>(monster->getIdentifier(), monster));
	return monster;
}


Monster* Scene::getMonsterById(std::string identifier)
{
	return monsters.at(identifier);
}

std::vector<Monster*> Scene::getMonsters()
{
	std::vector<Monster*> monstersVector;
	monstersVector.reserve(monsters.size());
	std::transform(monsters.begin(), monsters.end(), std::back_inserter(monstersVector), [](std::pair<const std::string, Monster*> const &p) { return p.second; });
	return monstersVector;
}