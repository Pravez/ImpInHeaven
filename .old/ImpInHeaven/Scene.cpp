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

Imp* Scene::addPlayer(Imp* player)
{
	players.insert(std::pair<std::string, Imp*>(player->getIdentifier(), player));
	return player;
}

Monster* Scene::addMonster(Monster* monster)
{
	monsters.insert(std::pair<std::string, Monster*>(monster->getIdentifier(), monster));
	return monster;
}

Imp* Scene::getPlayerById(std::string identifier)
{
	return players.at(identifier);
}

Monster* Scene::getMonsterById(std::string identifier)
{
	return monsters.at(identifier);
}

std::vector<Imp*> Scene::getPlayers()
{
	std::vector<Imp*> playersVector;
	playersVector.reserve(players.size());
	std::transform(players.begin(), players.end(), std::back_inserter(playersVector), [](std::pair<const std::string, Imp*> const &p) { return p.second; });
	return playersVector;
}

std::vector<Monster*> Scene::getMonsters()
{
	std::vector<Monster*> monstersVector;
	monstersVector.reserve(monsters.size());
	std::transform(monsters.begin(), monsters.end(), std::back_inserter(monstersVector), [](std::pair<const std::string, Monster*> const &p) { return p.second; });
	return monstersVector;
}

void Scene::draw(Screen* screen)
{
	for(const auto player : players)
	{
		player.second->draw(screen);
	}

	for (const auto monster : monsters)
	{
		dynamic_cast<Bird*>(monster.second)->draw(screen);
	}

	for(const auto element : elements)
	{
		element->draw(screen);
	}
}
