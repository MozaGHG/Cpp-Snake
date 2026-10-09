#include "Position.h"
#pragma once

class Food
{
    public:
        void Respawn(Position pos);
        Position GetPos();

    private:
        Position pos = {10, 10};
};