#include "Pipe.hpp"
#include "definitions.hpp"
#include <iostream>
namespace game {
    
    Pipe::Pipe(GameDataRef data) : _data(data)
    {
        _landHeight = _data->assets.getTexture("Land").getSize().y;
        _pipeOffSetY = 0;
    }
    
    void
    Pipe::spawningBottomPipe()
    {
        sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
        float x = _data->window.getSize().x;
        float y = _data->window.getSize().y - sprite.getGlobalBounds().height;
        sprite.setPosition(x, y);
        
        _pipesArray.push_back(sprite);
        
    } ///
    
    void
    Pipe::spawningTopPipe()
    {
        sf::Sprite sprite(_data->assets.getTexture("Pipe Down"));
        float x = _data->window.getSize().x;
        sprite.setPosition(x, 0.0f);
        _pipesArray.push_back(sprite);
        
    } ///
    
    void
    Pipe::spawningInvisiblePipe()
    {
        sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
        float x = _data->window.getSize().x;
        float y = _data->window.getSize().y - sprite.getGlobalBounds().height;
        sprite.setPosition(x, y);
        sprite.setColor(sf::Color(0, 0, 0, 0));
        
        _pipesArray.push_back(sprite);
        
    } ///
    
    void Pipe::movePipes(float dt)
    {
        for (unsigned short int i = 0; i < _pipesArray.size(); i++)
        {
            // delete the pipe once it goes of the left bound.
            if (_pipesArray.at(i).getPosition().x < 0 - _pipesArray.at(i).getGlobalBounds().width)
                _pipesArray.erase(_pipesArray.begin() + i);
            else {
                float movement = CONST::pipe_speed * dt;
                _pipesArray.at(i).move(-movement, 0);
            }
            
            // watching the size of the pipe array.
            // std::cout << pipesArray.size() << std::endl;
 
        }

    } ///
    
    
    void
    Pipe::drawPipes()
    {
        for (unsigned short int i = 0; i < _pipesArray.size(); i++)
            _data->window.draw(_pipesArray.at(i));
    } ///
    
    void
    Pipe::randmisePipesOffset()
    {
        _pipeOffSetY = rand() % (_landHeight + 1);
    }///
    
}
