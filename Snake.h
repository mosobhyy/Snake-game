#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <iostream>
#include <vector>
#include "Point.cpp"

using namespace std;

class Snake
{
private:
    vector<Point> body;
public:
    Point& getHead();
    int getLength();
    bool isBody(Point point);
    void growSnake(Point newHead);
    void eraseTail();
    Snake(Point head);
};


#endif //SNAKE_SNAKE_H