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

Imp* Scene::getPlayerById(std::string identifier)
{
	return players.at(identifier);
}

std::vector<Imp*> Scene::getPlayers()
{
	std::vector<Imp*> playersVector;
	playersVector.reserve(players.size());
	std::transform(players.begin(), players.end(), std::back_inserter(playersVector), [](std::pair<const std::string, Imp*> const &p) { return p.second; });
	return playersVector;
}

void Scene::draw(Screen* screen)
{
	for(const auto player : players)
	{
		player.second->draw(screen);
	}

	for(const auto element : elements)
	{
		element->draw(screen);
	}
}
