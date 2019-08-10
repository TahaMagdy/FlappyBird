#include "Land.hpp"
#include "definitions.hpp"


namespace game {
    Land::Land(GameDataRef data) : _data(data)
    {
        sf::Sprite sprite(_data->assets.getTexture("Land"));
        sf::Sprite sprite2(_data->assets.getTexture("Land"));
        
        sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
        sprite2.setPosition(sprite.getGlobalBounds().width,
                            _data->window.getSize().y - sprite.getGlobalBounds().height);
        
        _landArray.push_back(sprite);
        _landArray.push_back(sprite2);

    }
    
    void Land::landMove(float dt)
    {
        for (unsigned short int i = 0; i < _landArray.size(); i++)
        {
            float movement = CONST::pipe_speed *dt;
            _landArray.at(i).move(-movement, 0.0f);
        
            if (_landArray.at(i).getPosition().x < 0 - _landArray.at(i).getGlobalBounds().width)
            {
                sf::Vector2f position(_data->window.getSize().x, _landArray.at(i).getPosition().y);
                _landArray.at(i).setPosition(position);
            }
        }
    }///
    
    void Land::drawLand()
    {
        for (unsigned short int i = 0; i < _landArray.size(); i++)
            _data->window.draw(_landArray.at(i));
        
    }



}
