using namespace std;
#ifndef GAME_H

#include<point.h>
#include<snake.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <chrono>
#include <thread>

#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define WIDTH 40
#define LENGTH 20
#define FRUIT '@'
#define BOMB '*'
#define HASH '#'
#define SPACE ' '
#define SPEED 30
#define BODY 'o'
#define HEAD 'O'
#define lp(i, n)     for(int i=0 ; i<n ; i++)
#define loop(i, x, n)     for(int i=x ; i<=n ; i++)
#define GAME_H


class game {
    bool right, down, left, up, eatFruit, eatBomb;
    point bombP, fruitP;
    char arr[LENGTH][WIDTH];
    int lifes, level;
    snake s;

    int getLifes();

    void genFruitBomb();

    void display();

public:
    game();

    void setLevel(const int &);

    void setLifes(const int &);

    int getLevel();

    void play();
};

#endif // GAME_H