#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include "MainMenuState.hpp"
#include "SplashState.hpp"


namespace game {
    
    
    SplashState::SplashState(GameDataRef data) : _data(data)
    {
        
    } ///
    
    
    void
    SplashState::init()
    {
        //_data->assets.loadTexture("Splash State Background",                                CONST::splash_scence_background);
        _data->assets.loadTexture("Splash State Background",                                CONST::game_background);
        _background.setTexture(this->_data->assets.getTexture("Splash State Background"));
    } ///
    
    
    void
    SplashState::handleInput()
    {
        sf::Event event;
        
        while(_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                _data->window.close();
        }
        
    } ///
    
    
    void
    SplashState::update(float dt)
    {
        if(_clock.getElapsedTime().asSeconds() > CONST::splash_state_show_time)
        {
            _data->machine.addState(stateRef(new MainMenuState(this->_data)), true);
            
        }
    } ///
    
    
    void
    SplashState::draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    } ///
    
    
}
