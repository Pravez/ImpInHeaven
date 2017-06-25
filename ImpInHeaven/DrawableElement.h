#pragma once
#include <SDL.h>
#include "Screen.hpp"
#include "Element.h"

class DrawableElement : public Element
{
private:
	SDL_Texture* texture;

public:
	DrawableElement(Vector2 position, Vector2 dimensions, SDL_Texture* texture) : Element(position, dimensions), texture(texture) {};
	void draw(const Screen* screen) const;
};
