#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include "Snake.h"
using namespace std;
int main(int argc, char *argv[]) {
    cbreak();
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    refresh();
    Snake snake = Snake(3, 3);
    time_t start_time, curr_time;
    struct tm counter = {0};
    double seconds = 0;
    start_time = time(NULL);
    int c = ' ';
    c = wgetch(snake.GetWindow());
    while ((c != KEY_EXIT) && (seconds < 20)){
        snake.Move(NONE);
        usleep(500);
        c = wgetch(snake.GetWindow());
        switch (c) {
            case KEY_UP:
                snake.Move(UP);
                break;
            case KEY_DOWN:
                snake.Move(DOWN);
                break;
            case KEY_LEFT:
                snake.Move(LEFT);
                break;
            case KEY_RIGHT:
                snake.Move(RIGHT);
                break;
            default:
                snake.Move(NONE);
                break;
        }
        curr_time = time(NULL);
        seconds = difftime(curr_time, start_time);
    }

}
