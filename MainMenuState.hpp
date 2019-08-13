#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameLoop.hpp"


namespace game {
    
    class MainMenuState : public State
    {
    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _title;
        sf::Sprite _playButton;
        
    public:
        explicit MainMenuState(GameDataRef data);
        
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };
    
}
