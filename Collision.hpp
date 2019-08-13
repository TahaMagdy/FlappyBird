#pragma once
#include <SFML/Graphics.hpp>

namespace game
{
    class Collision
    {
    private:
        
    public:
        explicit Collision();
        bool checkSpriteCollision(sf::Sprite s1,
                                  float scale1,
                                  sf::Sprite s2,
                                  float scale2);
        
    };
}
