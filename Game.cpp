#include "Game.h"

void Game::moveSnack(const char dir)
{
    if (direction.find(dir) == direction.end())         // if input doesn't equal 'w' or 's' or 'd' or 'a' or ' '
        gameOver = true;

    Point newHead = snake.getHead() + direction[dir];
    snake.growSnake(newHead);
    if (newHead == fruit)
    {
        score++;
        generateFruit();
    }
    else
        snake.eraseTail();

    lastDir = dir;
}

bool Game::isGameOver()
{
    return gameOver;
}

void Game::generateFruit()
{
    srand(time(0));
    fruit.setX(1 + (rand() % (panelLength - 2))); // Generate random number between (1) and (length - 2)
    fruit.setY(1 + (rand() % (panelWidth - 2)));  // Generate random number between (1) and (width - 2)
}

void Game::draw()
{
    system("cls");

    moveSnack(lastDir);

    for (int i = 0; i < panelLength; i++)
    {
        for (int j = 0; j < panelWidth; j++)
        {
            if (i == 0 || i == panelLength - 1 || j == 0 || j == panelWidth - 1) // Draw game panel
                cout << "#";
            else if (fruit == Point(i, j)) // Draw Fruit
                cout << "$";
            else if (snake.getHead() == Point(i, j)) // Draw Snake head
                cout << "O";
            else if (snake.isBody(Point(i, j))) // Draw Snake body
                cout << "o";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "Score: " << score;
}

Game::Game()
{
    panelLength = 25;
    panelWidth = 60;
    score = 0;
    gameOver = false;
    lastDir = ' ';
    direction = {
        {'w', Point(-1, 0)},
        {'s', Point(+1, 0)},
        {'d', Point(0, +1)},
        {'a', Point(0, -1)},
        {' ', Point(0, 0)}};         // ' ' is an initial value for starting the game
    snake.getHead().setX(panelLength / 2);
    snake.getHead().setY(panelWidth / 2);
    generateFruit();
}