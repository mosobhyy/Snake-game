#include "Snake.h"

Point& Snake::getHead()
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
        if (it == point && point != getHead())
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

Snake::Snake(Point head = Point(0, 0))
{
    body.emplace_back(head);
}