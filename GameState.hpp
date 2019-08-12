#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "GameLoop.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "Hud.hpp"

namespace game {
    
    class GameState : public State
    {
    private:
        GameDataRef _data; 
        sf::Sprite  _background;
        sf::Clock   clock;
        Pipe  *pipe;
        Land  *land;
        Bird  *bird;
        Flash *flash;
        Hud   *hud;
        Collision _collision;
        int _gameState;
        int _score;
        
        sf::SoundBuffer _hitSoundBuffer;
        sf::SoundBuffer _pointSoundBuffer;
        sf::SoundBuffer _wingSoundBuffer;
        sf::Sound _hitSound;
        sf::Sound _pointSound;
        sf::Sound _wingSound; 
        

        
        
    public:
        GameState(GameDataRef data);
        
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    };
}


