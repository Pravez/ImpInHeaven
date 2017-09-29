#include "IsometricMapSprite.hpp"
#include "utils/utils.hpp"

void IsometricMapSprite::setWorldPosition(float x, float y) {
}

void IsometricMapSprite::setWorldPosition(const sf::Vector2f &position) {
    _worldpos = position;
    sf::Vector2f screenpos = worldToScreen(_worldpos);
    screenpos.y -= _z;
    setPosition(screenpos);
}

void IsometricMapSprite::setWorldZ(float z) {
    _z = z;
    sf::Vector2f screenpos = worldToScreen(_worldpos);
    screenpos.y -= _z;
    setPosition(screenpos);
}
