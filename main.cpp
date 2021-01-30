#include <iostream>
#include <ncurses.h>
#include "Snake.h"
#include "sWindow.h"
using namespace std;
int main(int argc, char *argv[]) {
    Snake snake = Snake(0,0);
    sWindow window = sWindow();
    snake.DrawSnake(window.DrawChar());
    getch();
}
