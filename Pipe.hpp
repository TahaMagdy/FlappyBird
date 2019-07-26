#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "GameLoop.hpp"

namespace game {
    
    class Pipe
    {
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> pipeSprite;
        
    public:
        Pipe(GameDataRef data);
        
        void drawPipes();
        void spawningBottomPipe();
        void spawningTopPipe();
        void spawningInvisiblePipe();
        void movePipes(float dt);
    };
    
}
