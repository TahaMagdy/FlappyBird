#include "Pipe.hpp"
#include "definitions.hpp"

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
            sf::Vector2f position = pipeSprite.at(i).getPosition();
            float movement = PIPE_SPEED * dt;
            pipeSprite.at(i).move(-movement, 0);
        }

        
    } ///
    
    
    void
    Pipe::drawPipes()
    {
        for (unsigned short int i = 0; i < pipeSprite.size(); i++)
            _data->window.draw(pipeSprite.at(i));
    } ///
    
    
    
}
