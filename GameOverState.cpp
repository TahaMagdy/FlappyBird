#include <iostream>
#include <sstream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include "MainMenuState.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"

namespace game {
    
    
    GameOverState::GameOverState(GameDataRef data, int score)
        : _data(data),
          _score(score)
    {
        
    } ///
    
    
    void
    GameOverState::init()
    {
        // Saving the highest score
        std::ifstream fread;
        fread.open("resources/game.data");
        
        if (fread.is_open())
            while (!fread.eof())
                fread >> _high;
        else
            std::cout << "Cannot Open game.data file\n";
        
        fread.close();
        
        std::ofstream fwrite("resources/game.data");
        
        if (fwrite.is_open())
        {
            if (_score > _high)
                _high = _score;
            
            fwrite << _high;
        }
        
        fwrite.close();
        
        
        
        _data->assets.loadTexture("Game Over Background",
                                  CONST::game_over_background);
        _data->assets.loadTexture("Game Over Title", CONST::game_over_title);
        _data->assets.loadTexture("Game Over Body",  CONST::game_over_body);
        _data->assets.loadTexture("Bronze Medal",    CONST::bronze_medal);
        _data->assets.loadTexture("Silver Medal",    CONST::silver_medal);
        _data->assets.loadTexture("Gold Medal",      CONST::gold_medal);
        _data->assets.loadTexture("Platinum Medal",  CONST::platinum_medal);
        
        _background.setTexture(this->_data->assets.getTexture("Game Over Background"));
        _gameOverTitle.setTexture(this->_data->assets.getTexture("Game Over Title"));
        _gameOverContainer.setTexture(this->_data->assets.getTexture("Game Over Body"));
        _retryButton.setTexture(this->_data->assets.getTexture("Play Button"));
       
        
        _gameOverContainer.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2)));
        
        _gameOverTitle.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2)));
        
        _retryButton.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.2)));

        
        _scoreText.setString(std::to_string(_score));
        _scoreText.setFont(_data->assets.getFont("Flappy Font"));
        _scoreText.setCharacterSize(56);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width/2,
                                          _scoreText.getGlobalBounds().height/2));
        _scoreText.setPosition(sf::Vector2f(_data->window.getSize().x /10*7.25,
                                            _data->window.getSize().y /2.15));
        
 
        _highScoreText.setString(std::to_string(_high));
        _highScoreText.setFont(_data->assets.getFont("Flappy Font"));
        _highScoreText.setCharacterSize(56);
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width/2,
                                 _highScoreText.getGlobalBounds().height/2);
        _highScoreText.setPosition(_data->window.getSize().x /10*7.25,
                                   _data->window.getSize().y /1.78);
        
        
        if (_score >= CONST::platinum_score)
               _medal.setTexture(_data->assets.getTexture("Platinum Medal"));
        else if (_score >= CONST::gold_score)
               _medal.setTexture(_data->assets.getTexture("Gold Medal"));
        else if (_score >= CONST::silver_score)
               _medal.setTexture(_data->assets.getTexture("Silver Medal"));
        else
               _medal.setTexture(_data->assets.getTexture("Bronze Medal"));
             
        _medal.setPosition(175, 465);
        
        
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
        _data->window.draw(_highScoreText);
        _data->window.draw(_scoreText);
        _data->window.draw(_medal);
        
        // At the end to draw all at once.
        // draw() after it will not appear.
        _data->window.display();
    } ///
    
    
}

