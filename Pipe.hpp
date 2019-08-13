#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "GameLoop.hpp"

namespace game {
    
    class Pipe
    {
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> _pipesArray;
        std::vector<sf::Sprite> _scoringPipesArray;

        int _landHeight;
        int _pipeOffSetY;
        
    public:
        explicit Pipe(GameDataRef data);
        
        void drawPipes();
        void spawningBottomPipe();
        void spawningTopPipe();
        void spawningInvisiblePipe();
        void movePipes(float dt);
        void randmisePipesOffset();
        void spawningScoringPipe();
        const std::vector<sf::Sprite> &getSprites() const;
        std::vector<sf::Sprite> &getScoringSprites();

    };
    
}
