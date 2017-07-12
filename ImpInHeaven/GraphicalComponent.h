#pragma once
#include <SDL.h>
#include "DataAccessorComponent.h"

class Screen;

class GraphicalComponent : public DataAccessorComponent
{
private:
	Screen *screen;
	SDL_Texture* texture;
	SDL_Rect source_rectangle;

	SDL_Rect destination_rectangle;
public:
	GraphicalComponent(SDL_Texture* texture, Screen* screen) : screen(screen), texture(texture) {}
	GraphicalComponent(SDL_Texture* texture, Screen* screen, SDL_Rect source_rectangle, SDL_Rect destination_rectangle)
		: screen(screen), texture(texture), source_rectangle(source_rectangle), destination_rectangle(destination_rectangle) {}
	virtual ~GraphicalComponent() {}

	SDL_Rect getSourceRectangle() const;
	SDL_Rect getDestinationRectangle() const;
	SDL_Texture* getTexture() const;

	void setSourceRectangle(int x, int y, int width, int height);
	void setDestinationRectangle(int x, int y, int width, int height);
	
	void updateDestinationRectanglePositionsWithBaseData();

	void update(t_delta delta) override;

	virtual void draw();
};
