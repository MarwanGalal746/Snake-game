#include "menu.h"

bool menu::mainMenu() {
    cout << "\t\tPlease choose from these levels ..\n\n";
    cout << "1- Level 1.\n2- Level 2.\n3- Level 3.\n\nPlease enter number of level which you want to play: ";
    string s;
    cin >> s;
    try {
        if (!IfInputValid(s))
            throw s;
    }
    catch (string s) {
        while (!IfInputValid(s)) {
            cout << "Please enter a valid input: ";
            cin >> s;
        }
    }
    g.setLevel(s[0] - '0');
    g.play();
    cout << "\t\t\tGAME OVER :(\n";
    string choice;
    cout << "Do you want to play again?\t(yes/no)\n";
    cin >> choice;
    try {
        UtoL(choice);
        if (choice != "yes" && choice != "no")
            throw s;
        else {
            if (choice == "yes")
                return true;
            else {
                cout << "\t\tWe are sad to leave :(\n\n";
                return false;
            }
        }
    }
    catch (string &choice) {
        while (choice != "yes" && choice != "no") {
            cout << "Please enter a valid input: ";
            cin >> choice;
            UtoL(choice);

        }
        if (choice == "yes")
            return true;
        else {
            cout << "\t\tWe are sad to leave :(\n\n";
            return false;
        }
    }
}

bool menu::IfInputValid(const string &s) {
    if (s.length() == 1) {
        if (s[0] == '1' || s[0] == '2' || s[0] == '3')
            return true;
    }
    return false;
}

void menu::UtoL(string &s) {
    lp(i, s.length())
    if (isupper(s[i]))
        s[i] += ('a' - 'A');
}
