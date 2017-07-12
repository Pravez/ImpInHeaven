#include "GraphicalComponent.h"
#include "Screen.hpp"

SDL_Rect GraphicalComponent::getSourceRectangle() const
{
	return source_rectangle;
}

SDL_Rect GraphicalComponent::getDestinationRectangle() const
{
	return destination_rectangle;
}

SDL_Texture* GraphicalComponent::getTexture() const
{
	return texture;
}

void GraphicalComponent::setSourceRectangle(int x, int y, int width, int height)
{
	this->source_rectangle.x = x;
	this->source_rectangle.y = y;
	this->source_rectangle.w = width;
	this->source_rectangle.h = height;
}

void GraphicalComponent::setDestinationRectangle(int x, int y, int width, int height)
{
	this->destination_rectangle.x = x;
	this->destination_rectangle.y = y;
	this->destination_rectangle.w = width;
	this->destination_rectangle.h = height;
}

void GraphicalComponent::updateDestinationRectanglePositionsWithBaseData()
{
	this->destination_rectangle.x = getPositionX();
	this->destination_rectangle.y = getPositionY();
}

void GraphicalComponent::update(t_delta delta)
{
	draw();
}

void GraphicalComponent::draw()
{
	Vector2<int> tileDimensions = screen->getTileDimensions();
	Vector2<int> source_pos = screen->positionToIsometric(this->getPositionX(), this->getPositionY());
	SDL_Rect source_rect = { source_pos.x(), source_pos.y(), 0, 0 };

	source_rect.x += tileDimensions.x() / 2 - getWidth() / 2;
	source_rect.y -= (tileDimensions.y() / 2);

	source_rect.w = getWidth();
	source_rect.h = getHeight();

	SDL_Rect dest_rect;
	dest_rect.w = 85;
	dest_rect.h = 132;
	dest_rect.x = dest_rect.w * static_cast<int>(getDirection());
	dest_rect.y = 0;

	SDL_RenderCopy(screen->getRenderer(), getTexture(), &dest_rect, &source_rect);
}

