#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameLoop.hpp"

namespace game {
    
    class Land
    {
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> _landArray;
        
    public:
        /*
         * - The constructor takes the GameDataRef which contains data like
         *   window to draw to.
         * - Sprite: a computer graphic that may be moved on-screen and otherwise
         *   manipulated as a single entity.
         */
        Land( GameDataRef data);
        void landMove(float dt);
        void drawLand();
        const std::vector<sf::Sprite> &getSprites() const;
    };
}
