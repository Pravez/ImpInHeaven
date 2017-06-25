#pragma once
#include <vector>
#include "Element.h"
#include "Imp.h"

class Scene
{
private:
	Imp* player;
	std::vector<Element> entities;

public:
	Scene();
	Scene(Vector2 impPosition);
	void addEntity(Element entity);
};
