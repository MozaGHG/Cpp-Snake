#include "Position.h"
#include <vector>
#pragma once

class Player
{
    public:
        std::vector<Position> snake;
        Player();
        Position GetHeadPos();
        std::vector<Position> GetSegments();
        char GetDirection();
        void SetDirection(char direction);
        void Move();

    private:
        char direction = 'd';

};