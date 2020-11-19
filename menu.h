#ifndef MENU_H

#include<game.h>

#define MENU_H


class menu {
    game g;

    bool IfInputValid(const string &s);

    void UtoL(string &s);

public:
    bool mainMenu();
};

#endif // MENU_H