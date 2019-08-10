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
                                  CONST::game_background);
        
        _data->assets.loadTexture("Pipe Up", CONST::pipe_up);
        _data->assets.loadTexture("Pipe Down", CONST::pipe_down);
        _data->assets.loadTexture("Land", CONST::land);
        _data->assets.loadTexture("Bird01", CONST::bird_frame1);
        
        pipe = new Pipe(_data);
        land = new Land(_data);
        bird = new Bird(_data);
        
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

            }
        }
        
    } ///
    
    
    void
    GameState::update(float dt)
    {
        pipe->movePipes(dt);
        land->landMove(dt);
        
        if ( clock.getElapsedTime().asSeconds() > CONST::pipe_spwan_frequency )
        {
            // generating pipes
            pipe->randmisePipesOffset();
            pipe->spawningInvisiblePipe();
            pipe->spawningTopPipe();
            pipe->spawningBottomPipe();
            
            // otherwise the clock will be always larger than the CONST::pipe_spwan_frequency.
            // and arbitrary number of pipes will be generated
            clock.restart();
        }
    } ///
    
    
    void
    GameState::draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        
        pipe->drawPipes();
        land->drawLand();
        bird->draw();
        
        _data->window.display();
    } ///
    
    
}
