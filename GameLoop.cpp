#include "GameLoop.hpp"

namespace game {
    
    Game::Game(int width, int height, std::string title)
    {
        _data->window.create(sf::VideoMode(width, height),
                             title,
                             sf::Style::Close | sf::Style::Titlebar);
        // need an init sate
        this->run();
    } ///
    
    void
    Game::run()
    {
        float newTime, frameTime, interpolation;
        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumelator = 0.0f;
        
        while(this->_data->window.isOpen())
        {
            this->_data->machine.processStateChanges();
            
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            
            if (frameTime > 0.25f)
                frameTime = 0.25f;
            
            currentTime = newTime;
            accumelator += frameTime;
            
            while(accumelator >= dt)
            {
                this->_data->machine.getActiveState()->handleInput();
                this->_data->machine.getActiveState()->update(dt);
                
                accumelator -= dt;
            }
            
            interpolation = accumelator / dt;
            this->_data->machine.getActiveState()->draw(interpolation);
            
        }
        
    } ///
    
}
