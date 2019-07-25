#pragma once

namespace game {
    
    class State
    {
    public:
        virtual void Init() = 0;
        virtual void handleInput() = 0;
        virtual void update(float dt) = 0;
        virtual void draw(float dt) = 0;
        
        virtual void puase() { }
        virtual void resume() { }
    };
}
