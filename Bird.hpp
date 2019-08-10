#pragma once

#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include "GameLoop.hpp"
#include <vector>

namespace game {
    
    
    class Bird
    {
    private:
        GameDataRef _data;
        sf::Sprite _birdSprite;
        std::vector<sf::Texture> _animationFrame;
        unsigned int _animationIterator;
        sf::Clock _clock, _movementClock;
        int _birdState;
        
        
    public:
        Bird(GameDataRef data);
        void draw();
        void animate(float dt);
        void update(float dt);
        void tap();
    };
    
}
