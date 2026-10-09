#include "food.h"

void Food::Respawn(Position pos)
{
    this->pos = pos;
}

Position Food::GetPos()
{
    return pos;
}