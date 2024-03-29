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
        sf::Text _scoreText;
        sf::Text _highScoreText;
        sf::Sprite _medal;
        
        int _score;
        int _high;
        
    public:
        explicit GameOverState(GameDataRef data, int score);
        
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };
}

