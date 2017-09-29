#ifndef IMPINHEAVEN_ISOMETRICMAPSPRITE_HPP
#define IMPINHEAVEN_ISOMETRICMAPSPRITE_HPP


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>

class IsometricMapSprite : public sf::Sprite {
protected:
    sf::Vector2f _worldpos;
    float _z;
    bool _useLighting;

public:
    IsometricMapSprite();
    IsometricMapSprite(const sf::Image &image, const sf::Vector2f &position=sf::Vector2f(0, 0),
    const sf::Vector2f &scale=sf::Vector2f(1, 1), float rotation = 0.f, const sf::Color &color=sf::Color(255, 255, 255, 255));
    ~IsometricMapSprite();

    void setWorldPosition(float x, float y);
    void setWorldPosition(const sf::Vector2f &position);
    sf::Vector2f getWorldPosition() const;

    void setWorldZ(float z);
    float getWorldZ(){ return _z; }

    void setUseLighting(bool use){ _useLighting = use; }
    bool getUseLighting() { return _useLighting; }
};


#endif //IMPINHEAVEN_ISOMETRICMAPSPRITE_HPP
