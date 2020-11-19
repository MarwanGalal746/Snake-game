#include "point.h"

point::point(const int x, const int y) {
    this->x = x;
    this->y = y;
}

void point::setX(const int &x) {
    this->x = x;
}

void point::setY(const int &y) {
    this->y = y;
}

int point::getX() const {
    return x;
}

int point::getY() const {
    return y;
}

point point::genPoint(const char arr[][WIDTH]) {
    int x = 1 + (rand() % (LENGTH - 2));
    int y = 1 + (rand() % (WIDTH - 2));
    while (arr[x][y] != SPACE) {
        x = 1 + (rand() % (LENGTH - 2));
        y = 1 + (rand() % (WIDTH - 2));
    }
    point p;
    p.x = x;
    p.y = y;
    return p;
}
