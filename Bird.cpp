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
        
        
        // setting the bird inital position
        int x = _data->window.getSize().x / 4 - _birdSprite.getGlobalBounds().width /2;
        int y = _data->window.getSize().y / 2 - _birdSprite.getGlobalBounds().height /2;
        _birdSprite.setPosition(x, y);
        
        // setting the bird inital state
        _birdState = CONST::bird_still;

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
    
    
    void
    Bird::update(float dt)
    {
        // move it down if the state is falling
        if (_birdState == CONST::bird_falling)
            _birdSprite.move(0, CONST::gravity * dt);
        
        // move it up if the state is flying
        else if (_birdState == CONST::bird_flying)
            _birdSprite.move(0, - CONST::flyingSpeed * dt);
        
        if (_movementClock.getElapsedTime().asSeconds() > CONST::flyingDuration)
        {
            _movementClock.restart();
            _birdState = CONST::bird_falling;
        }
        
    }///
    
    
    void
    Bird::tap()
    {
        _movementClock.restart();
        _birdState = CONST::bird_flying;
        
    }///
    
    
}
