#include "Game.h"

// Check if the new input direction is the opposite of the cuurent
bool Game::isOppositeDirection(char dir)
{
    return (lastDir == 'w' && dir == 's' || lastDir == 's' && dir == 'w' || lastDir == 'd' && dir == 'a' || lastDir == 'a' && dir == 'd');
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

// To make the panel circular so the snake can enter from any side and out from the opposite side
Point Game::enhanceNewHead(Point newHead)
{
    if (newHead.getX() == 0)
        newHead.setX(panelLength - 2);

    else if (newHead.getX() == panelLength - 1)
        newHead.setX(1);

    else if (newHead.getY() == 0)
        newHead.setY(panelWidth - 2);

    else if (newHead.getY() == panelWidth - 1)
        newHead.setY(1);

    return newHead;
}

void Game::moveSnack(const char dir)
{
    if (directions.find(dir) == directions.end()) // if input doesn't equal 'w' or 's' or 'd' or 'a' or ' '
        gameOver = true;

    // Prevent the snake from moving to opposite direction
    if (isOppositeDirection(dir) && snake.getLength() > 1)
        return;

    Point newHead = snake.getHead() + directions[dir];

    newHead = enhanceNewHead(newHead);

    // game over if snake eat itself
    if(snake.isBody(newHead))
        gameOver = true;

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
    cout << "\nScore: " << score << endl;
}

Game::Game()
{
    panelLength = 25;
    panelWidth = 60;
    score = 0;
    gameOver = false;
    lastDir = ' ';
    directions = {
        {'w', Point(-1, 0)},
        {'s', Point(+1, 0)},
        {'d', Point(0, +1)},
        {'a', Point(0, -1)},
        {' ', Point(0, 0)}}; // ' ' is an initial value for starting the game
    snake.getHead().setX(panelLength / 2);
    snake.getHead().setY(panelWidth / 2);
    generateFruit();
}