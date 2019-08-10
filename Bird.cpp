#include "Bird.hpp"

namespace game {
    
    Bird::Bird(GameDataRef data) : _data(data)
    {
        _animationIterator = 0;
        
        _animationFrame.push_back(_data->assets.getTexture("Bird01"));
        _animationFrame.push_back(_data->assets.getTexture("Bird02"));
        _animationFrame.push_back(_data->assets.getTexture("Bird03"));
        _animationFrame.push_back(_data->assets.getTexture("Bird04"));
        
        _birdSprite.setTexture( _animationFrame.at(_animationIterator) );

    }///
    
    void
    Bird::draw()
    {
        _data->window.draw(_birdSprite);
    }///
    
    void
    Bird::animate(float dt)
    {
        
        if (_clock.getElapsedTime().asSeconds() > CONST::bird_animation_duration / _animationFrame.size())
        {
            
            if (_animationIterator < _animationFrame.size() - 1)
                _animationIterator++;
            else
                _animationIterator = 0;
         
            _birdSprite.setTexture(_animationFrame.at(_animationIterator));
            _clock.restart();
        }
        
    }///
    
    
}
