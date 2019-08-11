#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameLoop.hpp"


namespace game {
    
    class GameOverState : public State
    {
    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _background;
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverContainer;
        sf::Sprite _retryButton;

        
    public:
        GameOverState(GameDataRef data);
        
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };
}

