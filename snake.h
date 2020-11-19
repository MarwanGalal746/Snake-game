
using namespace std;
#ifndef SNAKE_H
#define SNAKE_H

#include<cstdlib>
#include <iostream>
#include<algorithm>
#include<point.h>

#define RIGHT 'd'
#define WIDTH 40
#define LENGTH 20
#define HASH '#'
#define SPACE ' '
#define BODY 'o'
#define HEAD 'O'


class snake {
    point head;
    point tail;
    int len;
public:
    snake();

    point getHead();

    point getTail();

    int getLen();

    void setTailX(const int &);

    void setTailY(const int &);

    void setHeadX(const int &);

    void setHeadY(const int &);

    void shiftLeft(char arr[][40], int x, int y, const int &len);

    void shiftRight(char arr[][40], int x, int y, const int &len);

    void shiftUp(char arr[][40], int x, int y, const int &len);

    void specialShiftUp(char arr[][40], int x, int y, const int &len);

    void shiftDown(char arr[][40], int x, int y, const int &len);

    void specialShiftDown(char arr[][40], int x, int y, const int &len);

    int setLen(const int &len);

};

#endif // SNAKE_H