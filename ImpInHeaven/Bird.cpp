#include "Bird.h"
#include "Screen.hpp"

Bird::Bird(Vector2<int> position, Vector2<int> dimensions, SDL_Texture* texture) : Monster(position, dimensions, texture)
{
	direction = SOUTH;
}

void Bird::doAction() {//Map *map) {
	int action = rand() % (1000 + 0) + 0;
	if (action < 10)
	{
		if (action % 2 == 0)
		{
			moveUp();
			//map->moveMonsterUp(this->getIdentifier());
		}
		else 
		{
			moveDown();
			//map->moveMonsterDown(this->getIdentifier());
		}
	}
}

void Bird::draw(const Screen* screen) const
{
	Vector2<int> tileDimensions = screen->getTileDimensions();
	Vector2<int> source_pos = screen->positionToIsometric(this->getX(), this->getY());
	SDL_Rect source_rect = { source_pos.x(), source_pos.y(), 0, 0 };

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