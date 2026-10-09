#include "game.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <random>

std::mt19937 rng(std::random_device{}());
std::uniform_int_distribution<int> distX(2, 19);
std::uniform_int_distribution<int> distY(1, 13);


Game::Game()
    : board(height, std::vector<char>(width, ' '))
{
    for (int x = 0; x < board[0].size(); x++)
{
    board[0][x] = '#';
    board[board.size() - 1][x] = '#';
}

for (int y = 0; y < board.size(); y++)
{
    board[y][0] = '#';
    board[y][board[y].size() - 1] = '#';
}
    food.Respawn({10, 5});
}




void Game::GameOver()
{
    std::cout << "Game Over!" << std::endl;
    player.snake = {{5, 3}, {4, 3}, {3, 3}};
    player.SetDirection('d');
    system("pause");

}


void Game::Win()
{
    std::cout << "YOU WON!" << std::endl;
    player.snake = {{5, 3}, {4, 3}, {3, 3}};
    player.SetDirection('d');
    system("pause");
}



void Game::Draw()
{  
    for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[y].size(); x++)
            {
                std::cout << board[y][x];
            }
            std::cout << "\n";
        }
        for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            board[y][x] = ' ';
    }
}
        
}










int Game::Run()
{


    auto lastDraw = std::chrono::steady_clock::now();
    while (true)
    {

        if (_kbhit())
        {
            char key = _getch();
            if (key == 'w' || key ==  'a' || key == 's' || key == 'd')
            {
                player.SetDirection(key);
            }
        }


        auto segments = player.GetSegments();   
        


        for (Position segment : player.GetSegments())
        {
            if (player.GetHeadPos() == segment)
            {
                GameOver();
            }
        }


        auto now = std::chrono::steady_clock::now();

        if (now - lastDraw >= std::chrono::milliseconds(200))
        {
            if (player.snake.size() >= 266)
            {
                Win();
            }

            player.Move();
            auto segments = player.GetSegments();




            if (player.GetHeadPos().x == width - 1)
            {
                player.snake[0].x = 1;
            }
            else if (player.GetHeadPos().x == 0)
            {
                player.snake[0].x = width - 2;
            }
            else if (player.GetHeadPos().y == height - 1)
            {
                player.snake[0].y = 1;
            }
            else if (player.GetHeadPos().y == 0)
            {
                player.snake[0].y = height - 2;
            }
            



            for (Position segment : segments)
            {
                board[segment.y][segment.x] = 'o';
            }


            board[player.GetHeadPos().y][player.GetHeadPos().x] = 'O';
            board[food.GetPos().y][food.GetPos().x] = '*'; 




            if (player.GetHeadPos() == food.GetPos())
            {
                Position newFoodPos = {distX(rng), distY(rng)};

                while (board[newFoodPos.y][newFoodPos.x] != ' ')
                {
                    newFoodPos = {distX(rng), distY(rng)};
                }


                food.Respawn(newFoodPos);

                player.snake.push_back(player.snake.back());
            }



            system("cls");
            Draw();
            lastDraw = now;




            for (int x = 0; x < board[0].size(); x++)
            {
                board[0][x] = '#';
                board[board.size() - 1][x] = '#';
            }



            for (int y = 0; y < board.size(); y++)
            {
                board[y][0] = '#';
                board[y][board[y].size() - 1] = '#';
            }
        }


    }
    return 0;
}