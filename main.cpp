#include <iostream>
#include <cstdlib>
#include<menu.h>

using namespace std;


int main() {
    srand((time(NULL)));
    while (true) {
        menu snakeGame;
        if (!snakeGame.mainMenu())
            break;
    }
    return 0;
}

