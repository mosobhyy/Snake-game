#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <ctime>
#include <conio.h>
#include <windows.h>
#include <map>
#include "Snake.cpp"

class Game
{
private:
    int panelLength, panelWidth, score;
    map<char, Point> direction;
    char lastDir;
    bool gameOver;
    Point fruit;
    Snake snake;

    void generateFruit();

public:
    bool isGameOver();
    void moveSnack(const char direction);
    void draw();
    Game();
};

#endif //SNAKE_GAME_H