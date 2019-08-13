#pragma once

#include <SFML/Graphics.hpp>
#include "GameLoop.hpp"
#include "definitions.hpp"

namespace game {
    
    
    class Flash
    {
    private:
        GameDataRef _data;
        sf::RectangleShape _shape;
        bool _flashOn;
        
    public:
        explicit Flash(GameDataRef data);
        void show(float dt);
        void draw();
    };
    
    
    
}
