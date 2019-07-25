#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include "MainMenuState.hpp"
#include "GameOverState.hpp"


namespace game {
    
    
    GameOverState::GameOverState(GameDataRef data) : _data(data)
    {
        
    } ///
    
    
    void
    GameOverState::init()
    {
        _data->assets.loadTexture("Game Over Background",
                                  GAME_Over_BACKGROUND);
        _background.setTexture(this->_data->assets.getTexture("Game Over Background"));
    } ///
    
    
    void
    GameOverState::handleInput()
    {
        sf::Event event;
        
        while(_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                _data->window.close();
        }
        
    } ///
    
    
    void
    GameOverState::update(float dt)
    {
        
    } ///
    
    
    void
    GameOverState::draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    } ///
    
    
}

