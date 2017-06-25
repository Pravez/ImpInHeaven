#ifndef IMPINHEAVEN_IMP_HPP
#define IMPINHEAVEN_IMP_HPP
#include "DrawableElement.h"
#include "Direction.h"


//TODO : Remove and use map object
#define GRID_WIDTH 15
#define GRID_HEIGHT 15

class Imp : public DrawableElement
{
public:
	Imp(Vector2 position, Vector2 dimensions, SDL_Texture* texture);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};


#endif //IMPINHEAVEN_IMP_HPP
