#include "player.h"
#include "food.h"
#include <conio.h>
#pragma once


class Game
{
    public:
        int Run();
        Game();
        void Draw();
        void GameOver();
        void Win();

    private:
        Player player;
        const int width = 30; const int height = 15;
        std::vector<std::vector<char>> board;
        Food food;
};