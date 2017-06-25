#include "Scene.h"

Scene::Scene()
{
	this->player = new Imp(Vector2(0, 0), Vector2(0, 0), );
}

Scene::Scene(Vector2 impPosition)
{
	this->player = new Imp(impPosition.x(), impPosition.y());
}

void Scene::addEntity(Element entity)
{
	entities.push_back(entity);
}
