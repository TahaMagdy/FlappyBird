#pragma once

#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include "GameLoop.hpp"

namespace game {
    
    
    class Bird
    {
    private:
        GameDataRef _data;
        sf::Sprite _birdSprite;
        
    public:
        Bird(GameDataRef data);
        void draw();
    };
    
}
