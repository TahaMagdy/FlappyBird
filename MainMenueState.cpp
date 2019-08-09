#include <iostream>
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "definitions.hpp"
#include "GameOverState.hpp"


namespace game {
    
    
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
        
    } ///
    
    
    void
    MainMenuState::init()
    {
        _data->assets.loadTexture("Main Menu Background",
                                  CONST::main_menu_background);
        _data->assets.loadTexture("Game Title",
                                  CONST::game_name);
        _data->assets.loadTexture("Play Button",
                                  CONST::play_button);
        
        _background.setTexture(this->_data->assets.getTexture("Main Menu Background"));
        _title.setTexture(this->_data->assets.getTexture("Game Title"));
        _playButton.setTexture(this->_data->assets.getTexture("Play Button"));
        
        float x = (CONST::screen_width / 2) - (_title.getGlobalBounds().width / 2);
        float y = _title.getGlobalBounds().height /2;
        _title.setPosition(x, y);
        
         x = (CONST::screen_width / 2) - (_playButton.getGlobalBounds().width / 2);
        y = (CONST::screen_height / 2) - (_playButton.getGlobalBounds().height / 2);
        _playButton.setPosition(x, y);
        
    } ///
    
    
    void
    MainMenuState::handleInput()
    {
        sf::Event event;
        
        while(_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                _data->window.close();
            
            if (_data->input.isSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
                // Go to the Game State
                _data->machine.addState(stateRef(new GameState(this->_data)), true);
        }
    } ///
    
    
    void
    MainMenuState::update(float dt)
    {
        
    } ///
    
    
    void
    MainMenuState::draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_title);
        _data->window.draw(_playButton);
        _data->window.display();
    } ///
}
