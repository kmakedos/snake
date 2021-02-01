#include <iostream>
#include <ncurses.h>
#include "sWindow.h"
using namespace std;
int main(int argc, char *argv[]) {
    sWindow window = sWindow(3,3);
    window.DrawSnake('1');
    getch();
    window.DrawSnake(' ');
    getch();
//    window.MoveHorizontal(false);
//    window.MoveHorizontal(false);
//    window.MoveHorizontal(false);
    window.MoveVertical(true);
    window.MoveVertical(true);
    window.MoveVertical(true);
    window.DrawSnake('1');
    getch();
}
