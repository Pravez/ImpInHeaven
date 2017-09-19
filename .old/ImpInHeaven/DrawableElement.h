#pragma once

#include <SDL.h>
#include "Element.h"

class Screen;

class DrawableElement : public Element
{
protected:
	SDL_Texture* texture;

public:
	DrawableElement(Vector2 position, Vector2 dimensions, SDL_Texture* texture) : Element(position, dimensions), texture(texture) {}
	void draw(const Screen* screen) const;
};
