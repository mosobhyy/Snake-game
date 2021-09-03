#ifndef SNAKE_POINT_H
#define SNAKE_POINT_H


class Point
{
private:
    int x, y;
public:
    int getX() const;

    int getY() const;

    void setX(int x);

    void setY(int y);

    bool operator==(Point const &point);

    Point operator+(Point const &point);

    Point(int x, int y);

};


#endif //SNAKE_POINT_H
