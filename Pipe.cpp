#include "Pipe.hpp"
#include "definitions.hpp"
#include <iostream>
namespace game {
    
    Pipe::Pipe(GameDataRef data) : _data(data) { }
    
    void
    Pipe::spawningBottomPipe()
    {
        sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
        float x = _data->window.getSize().x;
        float y = _data->window.getSize().y - sprite.getGlobalBounds().height;
        sprite.setPosition(x, y);
        
        pipeSprite.push_back(sprite);
        
    } ///
    
    void
    Pipe::spawningTopPipe()
    {
        sf::Sprite sprite(_data->assets.getTexture("Pipe Down"));
        float x = _data->window.getSize().x;
        sprite.setPosition(x, 0.0f);
        pipeSprite.push_back(sprite);
        
    } ///
    
    void
    Pipe::spawningInvisiblePipe()
    {
        sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
        float x = _data->window.getSize().x;
        float y = _data->window.getSize().y - sprite.getGlobalBounds().height;
        sprite.setPosition(x, y);
        sprite.setColor(sf::Color(0, 0, 0, 0));
        
        pipeSprite.push_back(sprite);
        
    } ///
    
    void Pipe::movePipes(float dt)
    {
        for (unsigned short int i = 0; i < pipeSprite.size(); i++)
        {
            // delete the pipe once it goes of the left bound.
            if (pipeSprite.at(i).getPosition().x < 0 - pipeSprite.at(i).getGlobalBounds().width)
                pipeSprite.erase(pipeSprite.begin() + i);
            else {
                float movement = CONST::pipe_speed * dt;
                pipeSprite.at(i).move(-movement, 0);
            }
            
            std::cout << pipeSprite.size() << std::endl;

        }

        
        
    } ///
    
    
    void
    Pipe::drawPipes()
    {
        for (unsigned short int i = 0; i < pipeSprite.size(); i++)
            _data->window.draw(pipeSprite.at(i));
    } ///
    
    
    
}
