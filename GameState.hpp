#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameLoop.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"

namespace game {
    
    class GameState : public State
    {
    private:
        GameDataRef _data; 
        sf::Sprite  _background;
        sf::Clock   clock;
        Pipe *pipe;
        Land *land;
        Bird *bird;
        
    public:
        GameState(GameDataRef data);
        
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };
}


