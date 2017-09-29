#ifndef IMPINHEAVEN_UTILS_HPP
#define IMPINHEAVEN_UTILS_HPP

#include <SFML/System.hpp>

//ScreenX = 2*WorldX - 2*WorldY
//ScreenY = WorldX + WorldY
sf::Vector2f worldToScreen(sf::Vector2f v)
{
    return sf::Vector2f(2.0f*v.x - 2.0f*v.y, v.x + v.y);
}

//WorldX = (ScreenX + 2*ScreenY)/4
//WorldY = (2*ScreenY - ScreenX)/4
sf::Vector2f screenToWorld(sf::Vector2f v) {
    return sf::Vector2f((v.x + 2.0f * v.y)/4.0f, (2.0f*v.y - v.x)/4.0f);
}

#endif //IMPINHEAVEN_UTILS_HPP
