#ifndef IMPINHEAVEN_IMP_HPP
#define IMPINHEAVEN_IMP_HPP
#include "Entity.h"

enum DIRECTION {NORTH, EAST, SOUTH, WEST};
enum STATE {ALIVE, SLEEP, DEAD};

//TODO : Remove and use map object
#define GRID_WIDTH 15
#define GRID_HEIGHT 15

class Imp : public Entity
{
private:
	DIRECTION _direction;
	STATE state;

public:
	Imp(int x, int y) : Entity(x, y), _direction(SOUTH), state(ALIVE) {};
	DIRECTION getDirection() const;
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void setDirection(DIRECTION direction);
	void setState(STATE state);
	bool isDead();
};


#endif //IMPINHEAVEN_IMP_HPP
