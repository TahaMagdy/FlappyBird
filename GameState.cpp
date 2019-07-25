#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"


namespace game {
    
    
    GameState::GameState  (GameDataRef data) : _data(data)
    {
        
    } ///
    
    
    void
    GameState::init()
    {
        std::cout << "Game State\n";
        _data->assets.loadTexture("Game Background",
                                  GAME_BACKGROUND);
        
        _background.setTexture(this->_data->assets.getTexture("Game Background"));
    } ///
    
    
    void
    GameState::handleInput()
    {
        sf::Event event;
        
        while(_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                _data->window.close();
        }
        
    } ///
    
    
    void
    GameState::update(float dt)
    {
        
    } ///
    
    
    void
    GameState::draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    } ///
    
    
}
