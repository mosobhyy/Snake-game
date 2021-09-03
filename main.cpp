#include <iostream>
#include "Game.cpp"

using namespace std;

int main()
{
    Game game;
    while (!game.isGameOver())
    {
        game.draw();
        if (_kbhit())
            game.moveSnack(_getch());
        Sleep(50);
    }

    return 0;
}