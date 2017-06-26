#ifndef IMPINHEAVEN_CAMERA_HPP
#define IMPINHEAVEN_CAMERA_HPP
#include "Vector.hpp"
#include "Imp.h"

enum CameraMode { FIXED_MODE };

class Imp;

class Camera {
private:
	Vector2 position;
	int margin;
	int viewportTileWidth;
	int viewportTileHeight;
		
	CameraMode mode;

	Element* tracked;
public:
	Camera(CameraMode mode, int margin, int viewportTileWidth, int viewportTileHeight)
			: position(Vector2(0, 0)), margin(margin), viewportTileWidth(viewportTileWidth), 
				viewportTileHeight(viewportTileHeight), mode(mode), tracked(nullptr) {}

	void setTrackingOn(Element* element);
	void update();
	Vector2 getPosition() const;
};


#endif //IMPINHEAVEN_CAMERA_HPP
