#include "Snake.h"

Point &Snake::getHead()
{
    return *body.begin();
}

int Snake::getLength()
{
    return body.size();
}

bool Snake::isBody(Point point)
{
    for (auto it : body)
        if (it == point && point != getHead()) // Check if it's part of the body and not the head of the snake
            return true;
    return false;
}

void Snake::growSnake(Point newHead)
{
    body.insert(body.begin(), newHead);
}

void Snake::eraseTail()
{
    body.erase(body.end());
}

// Initialize head of snake as (0, 0) when using the default constructor
// and as "head (x, y)" when using the parameterized constructor
Snake::Snake(Point head = Point(0, 0))
{
    body.emplace_back(head);
}