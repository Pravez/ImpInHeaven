#include "Camera.h"
#include <map>

void Camera::setTrackingOn(Element* element)
{
	this->tracked = element;
}

void Camera::update()
{
	switch(mode)
	{
	case FIXED_MODE:
		if (tracked->getX() > 0 + margin && tracked->getX() < viewportTileWidth - margin - 1) {
			position.x(tracked->getX());
		}
		if (tracked->getY() > 0 + margin && tracked->getY() < viewportTileHeight - margin - 1) {
			position.y(tracked->getY());
		}
		break;
	default:
		break;
	}
	
}

Vector2 Camera::getPosition() const
{
	return position;
}
