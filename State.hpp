#pragma once

namespace flappy {
    
    class State
    {
    public:
        virtual void Init() = 0;
        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void draw(float dt) = 0;
        
        virtual void puase() { }
        virtual void resume() { }
    };
}
