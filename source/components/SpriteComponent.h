#include <SFML/Graphics.hpp>
#include "Component.h"

class SpriteComponent: Component, sf::Sprite
{
private:
    /* data */
public:
    SpriteComponent(/* args */);
    ~SpriteComponent();
};

