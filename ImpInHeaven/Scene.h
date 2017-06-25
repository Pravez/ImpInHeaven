#pragma once
#include <vector>
#include "Element.h"
#include "Imp.h"

using namespace std;

class Scene
{
private:
	Imp* player;
	vector<Element> entities;

public:
	Scene();
	Scene(Vector2 impPosition);
	void addEntity(Element entity);
};
