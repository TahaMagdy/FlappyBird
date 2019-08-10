#include "Bird.hpp"

namespace game {
    
    Bird::Bird(GameDataRef data) : _data(data)
    {
        _birdSprite.setTexture( _data->assets.getTexture("Bird01") );

    }///
    
    void
    Bird::draw()
    {
        _data->window.draw(_birdSprite);
    }///
    
    
}
