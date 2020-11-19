#include<iostream>
#include<cstdlib>

#ifndef POINT_H
#define POINT_H
#ifndef WIDTH LENGTH SPACE
#define LENGTH 20
#define SPACE ' '
#define WIDTH 40
#endif

class point {
    int x, y;
public:
    point(const int= 0, const int= 0);

    void setX(const int &x);

    void setY(const int &y);

    int getX() const;

    int getY() const;

    point genPoint(const char arr[][WIDTH]);
};

#endif // POINT_H