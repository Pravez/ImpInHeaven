#ifndef IMPINHEAVEN_IMP_HPP
#define IMPINHEAVEN_IMP_HPP

enum DIRECTION {NORTH, EAST, SOUTH, WEST};

//TODO : Remove and use map object
#define GRID_WIDTH 8
#define GRID_HEIGHT 8

class Imp
{
private:
	int _x;
	int _y;
	DIRECTION _direction;

public:
	Imp(int x, int y) : _x(x), _y(y), _direction(SOUTH) {};
	int getX();
	int getY();
	DIRECTION get_direction();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};


#endif //IMPINHEAVEN_IMP_HPP
