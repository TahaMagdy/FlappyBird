#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManger.hpp"

namespace game {

    struct GameData
    {
        sf::RenderWindow window;
        StateMachine machine;
        AssetManager assets;
        InputManager input;
        
    };
    
    typedef std::shared_ptr<GameData> GameDataRef;
    
    class Game
    {
        
    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;
        GameDataRef _data = std::make_shared<GameData>();
        void run();
        
        
    public:
        explicit Game(int width, int height, std::string title );
        
    };
    
}

