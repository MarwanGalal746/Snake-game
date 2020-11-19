#include "snake.h"

void snake::shiftLeft(char arr[][40], int x, int y, const int &len) {
    int i = y;
    int temp_len = len;
    while (true) {
        swap(arr[x][i], arr[x][i - 1]);
        i++;
        temp_len--;
        if (arr[x][i] != BODY || !temp_len) {
            i--;
            break;
        }
    }
    if (temp_len == 0) {
        tail.setX(x);
        tail.setY(i);
        return;
    }
    if (arr[x + 1][i] == BODY)
        this->shiftUp(arr, x + 1, i, temp_len);
    if (arr[x - 1][i] == BODY)
        this->shiftDown(arr, x - 1, i, temp_len);
    if (x == LENGTH - 2) {
        if (arr[1][y] == BODY)
            this->specialShiftUp(arr, 1, y, temp_len);
    }
    if (x == 1) {
        if (arr[LENGTH - 2][y] == BODY)
            this->specialShiftDown(arr, LENGTH - 2, y, temp_len);
    }
}

void snake::shiftRight(char arr[][40], int x, int y, const int &len) {
    int i = y;
    int temp_len = len;
    while (true) {
        swap(arr[x][i], arr[x][i + 1]);
        i--;
        temp_len--;
        if (arr[x][i] != BODY || !temp_len) {
            i++;
            break;
        }
    }
    if (!temp_len) {
        tail.setX(x);
        tail.setY(i);
        return;
    }
    if (arr[x + 1][i] == BODY)
        this->shiftUp(arr, x + 1, i, temp_len);
    if (arr[x - 1][i] == BODY)
        this->shiftDown(arr, x - 1, i, temp_len);
    if (x == LENGTH - 2) {
        if (arr[1][y] == BODY)
            this->specialShiftUp(arr, 1, y, temp_len);
    }
    if (x == 1) {
        if (arr[LENGTH - 2][y] == BODY)
            this->specialShiftDown(arr, LENGTH - 2, y, temp_len);
    }

}

void snake::shiftUp(char arr[][40], int x, int y, const int &len) {
    int i = x;
    int temp_len = len;
    while (true) {
        swap(arr[i][y], arr[i - 1][y]);
        i++;
        temp_len--;
        if (arr[i][y] != BODY || !temp_len) {
            i--;
            break;
        }

    }
    if (!temp_len) {
        tail.setX(i);
        tail.setY(y);
        return;
    }

    if (arr[i][y + 1] == BODY)
        this->shiftLeft(arr, i, y + 1, temp_len);
    if (arr[i][y - 1] == BODY)
        this->shiftRight(arr, i, y - 1, temp_len);
    if (i == LENGTH - 2) {
        if (arr[1][y] == BODY)
            this->specialShiftUp(arr, 1, y, temp_len);
    }

}

void snake::specialShiftUp(char arr[][40], int x, int y, const int &len) {
    int i = x;
    int temp_len = len;
    swap(arr[i][y], arr[LENGTH - 2][y]);
    temp_len--;
    if (!temp_len) {
        tail.setX(x);
        tail.setY(y);
        return;
    }
    if (arr[i][y + 1] == BODY)
        this->shiftLeft(arr, i, y + 1, temp_len);
    if (arr[i][y - 1] == BODY)
        this->shiftRight(arr, i, y - 1, temp_len);
    if (arr[2][y] == BODY)
        this->shiftUp(arr, 2, y, temp_len);

}

void snake::shiftDown(char arr[][40], int x, int y, const int &len) {
    int i = x;
    int temp_len = len;
    while (true) {
        swap(arr[i][y], arr[i + 1][y]);
        i--;
        temp_len--;
        if (arr[i][y] != BODY || !temp_len) {
            i++;
            break;
        }
    }
    if (!temp_len) {
        tail.setX(i);
        tail.setY(y);
        return;
    }
    if (arr[i][y + 1] == BODY)
        this->shiftLeft(arr, i, y + 1, temp_len);
    if (arr[i][y - 1] == BODY)
        this->shiftRight(arr, i, y - 1, temp_len);
    if (i == 1) {
        if (arr[LENGTH - 2][y] == BODY)
            this->specialShiftDown(arr, LENGTH - 2, y, temp_len);
    }
}

void snake::specialShiftDown(char arr[][40], int x, int y, const int &len) {
    int i = x;
    int temp_len = len;
    swap(arr[i][y], arr[1][y]);
    temp_len--;
    if (!temp_len) {
        tail.setX(LENGTH - 2);
        tail.setY(y);
        return;
    }
    if (arr[i][y + 1] == BODY)
        this->shiftLeft(arr, i, y + 1, temp_len);
    if (arr[i][y - 1] == BODY)
        this->shiftRight(arr, i, y - 1, temp_len);
    if (arr[LENGTH - 3][y] == BODY)
        this->shiftDown(arr, LENGTH - 3, y, temp_len);

}


snake::snake() {
    head.setX((LENGTH - 2) / 2);
    head.setY((WIDTH - 2) / 2);
    tail.setX(head.getX());
    tail.setY(head.getY());
    len = 1;
}

point snake::getHead() {
    return head;
}

point snake::getTail() {
    return tail;
}

int snake::getLen() {
    return len;
}

void snake::setTailX(const int &x) {
    tail.setX(x);
}

void snake::setTailY(const int &y) {
    tail.setY(y);
}

void snake::setHeadX(const int &x) {
    head.setX(x);
}

void snake::setHeadY(const int &y) {
    head.setY(y);
}

int snake::setLen(const int &len) {
    this->len = len;
}




