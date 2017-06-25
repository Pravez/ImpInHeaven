#include "DrawableElement.h"
#include "Screen.hpp"

void DrawableElement::draw(const Screen* screen) const
{
	Vector2 tileDimensions = screen->getTileDimensions();
	SDL_Rect source_rect = screen->positionToIsometric(this->getX(), this->getY());

	source_rect.x += tileDimensions.x() / 2 - getWidth() / 2;
	source_rect.y -= (tileDimensions.y() / 2);

	source_rect.w = getWidth();
	source_rect.h = getHeight();

	SDL_Rect dest_rect;
	dest_rect.w = 75;
	dest_rect.h = 132;
	dest_rect.x = dest_rect.w * static_cast<int>(getDirection());
	dest_rect.y = 0;

	SDL_RenderCopy(screen->getRenderer(), this->texture, &dest_rect, &source_rect);
}
