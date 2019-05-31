#pragma once
#include "GameHandler.h"

class InputManager
{
    public:
        InputManager(GameHandler* gameHandler);
        virtual ~InputManager();

    protected:

    private:
         GameHandler* m_gameHandler;
};


