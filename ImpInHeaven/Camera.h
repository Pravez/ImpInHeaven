#ifndef IMPINHEAVEN_CAMERA_HPP
#define IMPINHEAVEN_CAMERA_HPP
#include "Vector.hpp"
#include "Imp.h"

enum CameraMode { FIXED_MODE };

class GameElement;

class Camera {
private:
	Vector2<int> position;
	int margin;
	int viewportTileWidth;
	int viewportTileHeight;
		
	CameraMode mode;

	GameElement* tracked;
public:
	Camera(CameraMode mode, int margin, int viewportTileWidth, int viewportTileHeight)
			: position(Vector2<int>(0, 0)), margin(margin), viewportTileWidth(viewportTileWidth),
				viewportTileHeight(viewportTileHeight), mode(mode), tracked(nullptr) {}

	void setTrackingOn(GameElement* element);
	void update();
	Vector2<int> getPosition() const;
};


#endif //IMPINHEAVEN_CAMERA_HPP
