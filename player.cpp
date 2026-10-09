#include "player.h"

Player::Player()
{
    snake.push_back({5, 3});
    snake.push_back({4, 3});
    snake.push_back({3, 3});
}

Position Player::GetHeadPos()
{
    return snake[0];
}

std::vector<Position> Player::GetSegments()
{
    return std::vector<Position>(snake.begin() + 1, snake.end());
}

char Player::GetDirection()
{
    return direction;
}

void Player::SetDirection(char direction)
{
    this->direction = direction;
}

void Player::Move()
{
    for (int i = snake.size() - 1; i > 0; --i)
        snake[i] = snake[i - 1];

    switch(direction)
    {
        case 'w': snake[0].y--; break;
        case 's': snake[0].y++; break;
        case 'a': snake[0].x--; break;
        case 'd': snake[0].x++; break;
    }
}