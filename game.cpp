#include "game.h"

game::game() {
    lp(i, LENGTH)arr[i][0] = HASH, arr[i][WIDTH - 1] = HASH;
    lp(i, WIDTH)arr[0][i] = SPACE, arr[LENGTH - 1][i] = SPACE;
    loop(i, 1, LENGTH - 2) {
        loop(r, 1, WIDTH - 2)arr[i][r] = SPACE;
    }
    right = 0;
    down = 1;
    left = 0;
    up = 0;
    eatFruit = 0;
    eatBomb = 0;
    fruitP.setX(1);
    fruitP.setY(1);
    bombP.setX(1);
    bombP.setY(1);
    arr[s.getHead().getX()][s.getHead().getY()] = HEAD;
    level = 1;
    lifes = 6;
}

void game::setLevel(const int &level) {
    this->level = level;
    setLifes(level);
}

void game::setLifes(const int &level) {
    if (level == 1) lifes = 6;
    else if (level == 2) lifes = 4;
    else lifes = 2;
}

void game::genFruitBomb() {
    if (!eatFruit || !eatBomb) {
        if (!eatFruit && !eatBomb) {
            point p;
            p = p.genPoint(arr);
            arr[p.getX()][p.getY()] = FRUIT;
            fruitP = p;
            p = p.genPoint(arr);
            arr[p.getX()][p.getY()] = BOMB;
            bombP = p;
            eatFruit = eatBomb = 1;
        } else if (!eatFruit) {
            point p = p.genPoint(arr);
            arr[p.getX()][p.getY()] = FRUIT;
            fruitP = p;
            arr[bombP.getX()][bombP.getY()] = SPACE;
            p = p.genPoint(arr);
            bombP = p;
            arr[bombP.getX()][bombP.getY()] = BOMB;
            eatFruit = eatBomb = 1;
        } else if (!eatBomb) {
            point p = p.genPoint(arr);
            arr[p.getX()][p.getY()] = BOMB;
            bombP = p;
            arr[fruitP.getX()][fruitP.getY()] = SPACE;
            p = p.genPoint(arr);
            fruitP = p;
            arr[fruitP.getX()][fruitP.getY()] = FRUIT;
            eatFruit = eatBomb = 1;
        }
    }
}

void game::play() {
    while (true) {
        genFruitBomb();
        char c;
        if (kbhit()) {
            c = getch();
            if (c == UP || c == UP_ARROW) {
                if (!down)
                    up = 1, down = left = right = 0;
            } else if (c == DOWN || c == DOWN_ARROW) {
                if (!up)
                    down = 1, up = left = right = 0;
            } else if (c == LEFT || c == LEFT_ARROW) {
                if (!right)
                    left = 1, down = up = right = 0;
            } else if (c == RIGHT || c == RIGHT_ARROW) {
                if (!left)
                    right = 1, down = left = up = 0;
            }
        }
        char pre;
        int prex, prey;
        if (right) {
            if (arr[s.getHead().getX()][s.getHead().getY() + 1] == FRUIT) {
                arr[s.getHead().getX()][s.getHead().getY() + 1] = SPACE, eatFruit = 0;
                arr[s.getTail().getX()][s.getTail().getY()] = BODY;
                s.setLen(s.getLen() + 1);
            } else if (arr[s.getHead().getX()][s.getHead().getY() + 1] == BOMB) {
                arr[s.getHead().getX()][s.getHead().getY() + 1] = SPACE, eatBomb = 0;
                lifes--;
            }
            pre = arr[s.getHead().getX()][s.getHead().getY() + 1], s.shiftRight(arr, s.getHead().getX(),
                                                                                s.getHead().getY(),
                                                                                s.getLen()), s.setHeadY(
                    s.getHead().getY() + 1);;
        }
        if (up) {
            if (s.getHead().getX() == 1) {
                if (arr[LENGTH - 2][s.getHead().getY()] == FRUIT)
                    arr[LENGTH -
                        2][s.getHead().getY()] = SPACE, eatFruit = 0, arr[s.getTail().getX()][s.getTail().getY()] = BODY, s.setLen(
                            s.getLen() + 1);
                else if (arr[LENGTH - 2][s.getHead().getY()] == BOMB) {
                    arr[LENGTH - 2][s.getHead().getY()] = SPACE, eatBomb = 0;
                    lifes--;
                }
                pre = arr[LENGTH - 2][s.getHead().getY()], s.specialShiftUp(arr, 1, s.getHead().getY(),
                                                                            s.getLen()), s.setHeadX(LENGTH - 2);
            } else {
                if (arr[s.getHead().getX() - 1][s.getHead().getY()] == FRUIT)
                    arr[s.getHead().getX() -
                        1][s.getHead().getY()] = SPACE, eatFruit = 0, arr[s.getTail().getX()][s.getTail().getY()] = BODY, s.setLen(
                            s.getLen() + 1);
                else if (arr[s.getHead().getX() - 1][s.getHead().getY()] == BOMB) {
                    arr[s.getHead().getX() - 1][s.getHead().getY()] = SPACE, eatBomb = 0;
                    lifes--;
                }
                pre = arr[s.getHead().getX() - 1][s.getHead().getY()], s.shiftUp(arr, s.getHead().getX(),
                                                                                 s.getHead().getY(),
                                                                                 s.getLen()), s.setHeadX(
                        s.getHead().getX() - 1);
            }
        }
        if (down) {
            if (s.getHead().getX() == LENGTH - 2) {
                if (arr[1][s.getHead().getY()] == FRUIT)
                    arr[1][s.getHead().getY()] = SPACE, eatFruit = 0, arr[s.getTail().getX()][s.getTail().getY()] = BODY, s.setLen(
                            s.getLen() + 1);
                else if (arr[1][s.getHead().getY()] == BOMB) {
                    arr[1][s.getHead().getY()] = SPACE, eatBomb = 0;
                    lifes--;
                }
                pre = arr[1][s.getHead().getY()], s.specialShiftDown(arr, LENGTH - 2, s.getHead().getY(),
                                                                     s.getLen()), s.setHeadX(1);
            } else {
                if (arr[s.getHead().getX() + 1][s.getHead().getY()] == FRUIT)
                    arr[s.getHead().getX() +
                        1][s.getHead().getY()] = SPACE, eatFruit = 0, arr[s.getTail().getX()][s.getTail().getY()] = BODY, s.setLen(
                            s.getLen() + 1);
                else if (arr[s.getHead().getX() + 1][s.getHead().getY()] == BOMB) {
                    arr[s.getHead().getX() + 1][s.getHead().getY()] = SPACE, eatBomb = 0;
                    lifes--;
                }
                pre = arr[s.getHead().getX() + 1][s.getHead().getY()], s.shiftDown(arr, s.getHead().getX(),
                                                                                   s.getHead().getY(),
                                                                                   s.getLen()), s.setHeadX(
                        s.getHead().getX() + 1);
            }
        }
        if (left) {
            if (arr[s.getHead().getX()][s.getHead().getY() - 1] == FRUIT)
                arr[s.getHead().getX()][s.getHead().getY() -
                                        1] = SPACE, eatFruit = 0, arr[s.getTail().getX()][s.getTail().getY()] = BODY, s.setLen(
                        s.getLen() + 1);
            else if (arr[s.getHead().getX()][s.getHead().getY() - 1] == BOMB) {
                arr[s.getHead().getX()][s.getHead().getY() - 1] = SPACE, eatBomb = 0;
                lifes--;
            }
            pre = arr[s.getHead().getX()][s.getHead().getY() - 1], prex = s.getHead().getX(), prey =
                    s.getHead().getY() - 1, s.shiftLeft(arr, s.getHead().getX(), s.getHead().getY(),
                                                        s.getLen()), s.setHeadY(s.getHead().getY() - 1);
        }
        display();
        if (pre != SPACE)
            return;
        if (!lifes)
            return;


    }
}

void game::display() {
    if (level == 1)
        this_thread::sleep_for(chrono::milliseconds(SPEED * 6));
    else if (level == 2)
        this_thread::sleep_for(chrono::milliseconds(SPEED * 3));
    else
        this_thread::sleep_for(chrono::milliseconds(SPEED));
    system("cls");
    lp(i, LENGTH) {
        lp(r, WIDTH)cout << arr[i][r];
        cout << endl;
    }
    cout << "\t\tSCORE: " << (s.getLen() * 5) - 5 << "\tLIFES: " << lifes << endl;
    cout << "@ is a fruit\n* is a bomb\n";
}