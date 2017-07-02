#ifndef IMPINHEAVEN_MONSTER_HPP
#define IMPINHEAVEN_MONSTER_HPP

#include "DrawableElement.h"
#include "State.h"

class Monster : public DrawableElement
{
private:
	//static
	int ids;

	std::string identifier;
	State state;

public:
	Monster(Vector2<int> position, Vector2<int> dimensions, SDL_Texture* texture) : DrawableElement(position, dimensions, texture) { ids = 0; identifier = "monster" + ids++; setDirection(NORTH); };
	virtual ~Monster() {};

	virtual void doAction() =0;
	void moveUp() { getPosition().minus_y(1); };
	void moveDown() { getPosition().plus_y(1); };
	void moveRight() { getPosition().plus_x(1); };
	void moveLeft() { getPosition().minus_x(1); };
	void setState(State s) { state = s; };
	bool isDead() const { return state == DEAD; };
	std::string getIdentifier() const { return identifier; };
};

//int Monster::ids = 0;

#endif //IMPINHEAVEN_MONSTER_HPP