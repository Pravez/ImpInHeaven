

#ifndef IMPINHEAVEN_IMP_HPP
#define IMPINHEAVEN_IMP_HPP

//TODO : Remove and use map object
#define GRID_WIDTH 4
#define GRID_HEIGHT 4

class Imp
{
private:
	int _x;
	int _y;

public:
	Imp(int x, int y) : _x(x), _y(y) {};
	int getX();
	int getY();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};


#endif //IMPINHEAVEN_IMP_HPP
