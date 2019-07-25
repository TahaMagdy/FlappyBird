#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameLoop.hpp"


namespace game {
    
    class GameState : public State
    {
    private:
        GameDataRef _data; 
        sf::Sprite _background;
        
    public:
        GameState(GameDataRef data);
        
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };
}


