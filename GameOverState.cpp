#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include "MainMenuState.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"

namespace game {
    
    
    GameOverState::GameOverState(GameDataRef data) : _data(data)
    {
        
    } ///
    
    
    void
    GameOverState::init()
    {
        _data->assets.loadTexture("Game Over Background",
                                  CONST::game_over_background);
        _data->assets.loadTexture("Game Over Title", CONST::game_over_title);
        _data->assets.loadTexture("Game Over Body", CONST::game_over_body);
        
        _background.setTexture(this->_data->assets.getTexture("Game Over Background"));
        _gameOverTitle.setTexture(this->_data->assets.getTexture("Game Over Title"));
        _gameOverContainer.setTexture(this->_data->assets.getTexture("Game Over Body"));
        _retryButton.setTexture(this->_data->assets.getTexture("Play Button"));
       
        
        _gameOverContainer.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2)));
        
        _gameOverTitle.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2)));
        
        _retryButton.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.2)));

        
    } ///
    
    
    void
    GameOverState::handleInput()
    {
        sf::Event event;
        
        while(_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                _data->window.close();
            
            if (_data->input.isSpriteClicked(_retryButton, sf::Mouse::Left, _data->window))
                _data->machine.addState(stateRef(new GameState(_data)));
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
        _data->window.draw(_retryButton);
        _data->window.draw(_gameOverContainer);
        _data->window.draw(_gameOverTitle);
        
        // At the end to draw all at once.
        // draw() after it will not appear.
        _data->window.display();
    } ///
    
    
}

