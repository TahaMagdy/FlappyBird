#include "StateMachine.hpp"

/*
 * -- Defining method outside the class.
 */

namespace game
{
    void
    StateMachine::addState(stateRef newState, bool isReplacing)
    {
        this->_isAdding = true;
        this->_isReplacing = isReplacing;
        this->_newState = std::move(newState);
    } ///
    
    void
    StateMachine::removeState()
    {
        this->_isRemoving = true;
    } ///
    
    
    void
    StateMachine::processStateChanges()
    {
        // Check for removing
        if (this->_isRemoving && !this->_states.empty())
        {
            this->_states.pop();
            
            if (!this->_states.empty())
                this->_states.top()->resume();
            
            this->_isRemoving = false;
        }
        
        // Check for adding
        if (this->_isAdding)
        {
            if(!this->_states.empty())
            {
                if(this->_isReplacing)
                    this->_states.pop();
                else
                    this->_states.top()->puase();
            }
            
            this->_states.push(std::move(this->_newState));
            this->_states.top()->Init();
            this->_isAdding = false;
        }
    } ///
    
    
    stateRef
    &StateMachine::getActiveState()
    {
        return this->_states.top();
    }
    
}
