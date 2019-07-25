#include "MainMenuState.hpp"
#include "definitions.hpp"
#include <iostream>


namespace game {
    
    
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
        
    } ///
    
    
    void
    MainMenuState::init()
    {
        _data->assets.loadTexture("Main Menu Background",
                                  MAIN_MENU_BACKGROUND);
        _data->assets.loadTexture("Game Title",
                                  GAME_NAME);
        _data->assets.loadTexture("Play Button",
                                  PLAY_BUTTON);
        
        _background.setTexture(this->_data->assets.getTexture("Main Menu Background"));
        _title.setTexture(this->_data->assets.getTexture("Game Title"));
        _playButton.setTexture(this->_data->assets.getTexture("Play Button"));
        
        float x = (SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2);
        float y = _title.getGlobalBounds().height /2;
        _title.setPosition(x, y);
        
         x = (SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2);
        y = (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2);
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
                std::cout << "Go to the Game State\n";
                
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
