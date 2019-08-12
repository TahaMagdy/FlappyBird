#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "definitions.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"

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
        _data->assets.loadTexture("Bird02", CONST::bird_frame2);
        _data->assets.loadTexture("Bird03", CONST::bird_frame3);
        _data->assets.loadTexture("Bird04", CONST::bird_frame4);
        _data->assets.loadTexture("Scoring Pipe", CONST::scoring_pipe);
        _data->assets.loadFont("Flappy Font", CONST::font);

        
        pipe  = new Pipe(_data);
        land  = new Land(_data);
        bird  = new Bird(_data);
        flash = new Flash(_data);
        hud   = new Hud(_data);
        
        _background.setTexture(this->_data->assets.getTexture("Game Background"));

        _gameState = EnumGameState::eReady;
        _score = 0;
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
                if (_gameState != EnumGameState::eGameOver)
                {
                    _gameState = EnumGameState::ePlaying;
                    bird->tap();
                }
            }
        }
        
    } ///
    
    
    void
    GameState::update(float dt)
    {
        if (_gameState != EnumGameState::eGameOver)
        {
            bird->animate(dt);
            land->landMove(dt);
        }

        
        if (_gameState == EnumGameState::ePlaying)
        {
            pipe->movePipes(dt);
            
            if ( clock.getElapsedTime().asSeconds() > CONST::pipe_spwan_frequency )
            {
                
                // generating pipes
                pipe->randmisePipesOffset();
                pipe->spawningInvisiblePipe();
                pipe->spawningTopPipe();
                pipe->spawningBottomPipe();
                pipe->spawningScoringPipe();
                
                // otherwise the clock will be always larger than the CONST::pipe_spwan_frequency.
                // and arbitrary number of pipes will be generated
                clock.restart();
            }
            
            bird->update(dt);
            
            // check for collisions
            std::vector<sf::Sprite> landSprite = land->getSprites();
            for (int i = 0; i < landSprite.size(); i++)
            {
                if(_collision.checkSpriteCollision(bird->getSprite(),
                                                   0.625f,
                                                   landSprite.at(i),
                                                   1.0f))
                {
                    _gameState = EnumGameState::eGameOver;
                    clock.restart();
                }
            }
            
            std::vector<sf::Sprite> pipeSprite = pipe->getSprites();
            for (int i = 0; i < pipeSprite.size(); i++)
            {
                if(_collision.checkSpriteCollision(bird->getSprite(),
                                                   0.625f,
                                                   pipeSprite.at(i),
                                                   1.0f))
                {
                    _gameState = EnumGameState::eGameOver;
                    clock.restart();
                }
            }
            
            
            if (_gameState == EnumGameState::ePlaying)
            {
                std::vector<sf::Sprite> &scoringPipe = pipe->getScoringSprites();
                for (int i = 0; i < scoringPipe.size(); i++)
                {
                    if(_collision.checkSpriteCollision(bird->getSprite(),
                                                       0.625f,
                                                       scoringPipe.at(i),
                                                       1.0f))
                    {
                        _score++;
                        hud->updateScore(_score);
                        scoringPipe.erase(scoringPipe.begin() + i );
                    }
                }
            }
        }
        
        if (_gameState == EnumGameState::eGameOver)
        {
            flash->show(dt);
            
            // After n seconds go to the GameOverState
            if (clock.getElapsedTime().asSeconds() > CONST::time_before_game_over)
            {
                _data->machine.addState(stateRef(new GameOverState(_data, _score)), true);
            }
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
        flash->draw();
        hud->draw();
        
        
        _data->window.display();
    } ///
    
    
}
