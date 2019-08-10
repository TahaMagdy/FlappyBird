#include "Hud.hpp"


namespace game {
    
    
    Hud::Hud(GameDataRef data) : _data(data)
    {
        _scoreText.setFont(_data->assets.getFont("Flappy Font"));
        _scoreText.setString("0");
        _scoreText.setCharacterSize(128);
        _scoreText.setFillColor(sf::Color::White);
        int x = _scoreText.getGlobalBounds().width /2;
        int y = _scoreText.getGlobalBounds().height /2;
        _scoreText.setOrigin(x, y);
        _scoreText.setPosition(_data->window.getSize().x /2,
                               _data->window.getSize().y/5);
    }
    
    void
    Hud::draw()
    {
        _data->window.draw(_scoreText);
    }
    
    void
    Hud::updateScore(int score)
    {
        _scoreText.setString( std::to_string(score) );
    }
    
    
}
