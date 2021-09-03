#include "Snake.h"

Point& Snake::getHead()
{
    return *body.begin();
}

// vector<Point>& Snake::getSnake()
// {
//     return body;
// }

void Snake::growSnake(Point newHead)
{
    body.insert(body.begin(), newHead);
}

void Snake::eraseTail()
{
    body.erase(body.end());
}

bool Snake::isBody(Point point)
{
    for (auto it : body)
        if (it == point)
            return true;
    return false;
}

Snake::Snake(Point head = Point(0, 0))
{
    body.emplace_back(head);
}