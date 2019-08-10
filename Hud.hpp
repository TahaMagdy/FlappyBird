#pragma once
#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include "GameLoop.hpp"

namespace game {
    
    
    class Hud
    {
    private:
        GameDataRef _data;
        sf::Text _scoreText;
        
    public:
        Hud(GameDataRef data);
        void draw();
        void updateScore(int score);
    };
    
    
    
}
