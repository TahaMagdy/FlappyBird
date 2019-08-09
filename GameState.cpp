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
                                  CONST::GAME_BACKGROUND);
        
        _data->assets.loadTexture("Pipe Up", CONST::PIPE_UP);
        _data->assets.loadTexture("Pipe Down", CONST::PIPE_DOWN);
        
        pipe = new Pipe(_data);
        
        _background.setTexture(this->_data->assets.getTexture("Game Background"));

    } ///
    
    
    void
    GameState::handleInput()
    {
        sf::Event event;
        
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                _data->window.close();
            
            if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window))
            {
                pipe->spawningInvisiblePipe();
                pipe->spawningTopPipe();
                pipe->spawningBottomPipe();
            }
        }
        
    } ///
    
    
    void
    GameState::update(float dt)
    {
        pipe->movePipes(dt);
    } ///
    
    
    void
    GameState::draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        pipe->drawPipes();
        
        _data->window.display();
    } ///
    
    
}
