#include "Camera.h"
#include "GameElement.h"

void Camera::setTrackingOn(GameElement* element)
{
	this->tracked = element;
}

void Camera::update()
{
	switch(mode)
	{
	case FIXED_MODE:
		if (tracked->getPositionX() > 0 + margin && tracked->getPositionX() < viewportTileWidth - margin - 1) {
			position.x(tracked->getPositionX());
		}
		if (tracked->getPositionY() > 0 + margin && tracked->getPositionY() < viewportTileHeight - margin - 1) {
			position.y(tracked->getPositionY());
		}
		break;
	default:
		break;
	}
	
}

Vector2<int> Camera::getPosition() const
{
	return position;
}
